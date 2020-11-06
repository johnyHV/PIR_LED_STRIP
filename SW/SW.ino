#include "Config.h"
#include "IR_Remote.h"
#include "LedPas.h"
#include "Premenne.h"
#include "PIR_Sensor.h"
#include "TimerOne.h"

void timerIsr();

void setup() {
  /* Init serioveho rozhrania */  
  Serial.begin(115200);
  /* Init PIR senzora */
  PIR_Init();
  EnablePir = true;
  /* Init IR prijimaca */
#if (IR_REMOTE_ENABLE == true)
  IR_rx.enableIRIn();
#endif

  /* init LED pasu */
  LED_StripClear();
  /* Init STATUS LED */
  pinMode(STATUS_LED, OUTPUT);
  digitalWrite(STATUS_LED, LOW);

  /* Init casovaca */
  Timer1.initialize(1000000);       ///< Nastavenie casovaca na dlzku 100000 microseconds
  Timer1.attachInterrupt(timerIsr); ///< attach funkcie pre prerusenie 

  Serial.println(F("Start MCU!"));
}

void loop() {
  /* kontrola IR prijimaca */
  IR_Scan();

  /* kontrola detekcie pohybu z PIR senzora, a kontrola zapnuta detekcie pohybu cez IR dialkove ovladanie */
  if ((PIR_CheckStatus() == true) && (EnablePir == true)) {
    Serial.println(F("Motion detection! "));
    TimerCounter = 0;
    StartStripOn = true;
  }

  /* kontrola zapnutia LED pasu */
  if ((StartStripOn == true) && (LedStripStatus == false)) {
    Serial.println(F("Strip ON"));
    LED_StripOn();
    LED_ShelfOneOn();
    LED_ShelfTwoOn();
    LedStripStatus = true;
    StartStripOn = false;
  }

  /* kontrola vyprsania timeoutu, a vypnutie LED pasu */
  if ((TimerCounter >= LED_STRIP_TIMEOUT) && (LedStripStatus == true)) {
    Serial.println(F("Strip OFF"));
    LED_ShelfTwoOff();
    LED_ShelfOneOff();
    LED_StripOff();
    LedStripStatus = false;
    StartStripOn = false;
  }
}

/// --------------------------
/// Custom ISR Timer Routine
/// --------------------------
void timerIsr() {
  TimerCounter++;
  Serial.print(F("ISR: "));
  Serial.println(TimerCounter);
}

/* EOF */

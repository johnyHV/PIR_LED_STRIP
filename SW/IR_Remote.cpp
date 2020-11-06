/**
   @file IR_Remote.cpp

   @brief praca s IR dialkovym ovladanim

   @author Miroslav Pivovarsky
   Contact: miroslav.pivovarsky@gmail.com

   @bug: no know bug

*/

#include "IR_Remote.h"

/**

   @info Kniznica kontrolujuca stav IR prijimaca
   @param uint8_t - jas
   @return none
*/
uint8_t IR_Scan() {
#if (IR_REMOTE_ENABLE == true)
  decode_results results;

  if (IR_rx.decode(&results)) {
    Serial.print(F("IR button HEX code: "));
    Serial.println(results.value, HEX);
    IR_rx.resume();
    IR_CheckButton(&results);
  }
#endif
}

/**

   @info Funkcia spracuvajuca prichadzajuci prikaz
   @param decode_results - prijaty prikaz
   @return none
*/
#if (IR_REMOTE_ENABLE == true)
void IR_CheckButton(decode_results *results) {
  switch (results->value) {
    case IR_REMOTE_BUTTON_0:
      Serial.println("Cislo 0, OFF");
      strip.clear(LED_STRIP_COUNT);
      break;
    case IR_REMOTE_BUTTON_1:
      Serial.println("Cislo 1, RED");
      LED_updateColorsAll(LED_MAX_BRIGHTNESS, 0 , 0, 0);
      strip.sendPixels(LED_STRIP_COUNT, pixels);
      break;
    case IR_REMOTE_BUTTON_2:
      Serial.println("Cislo 2, GREEN");
      LED_updateColorsAll(0, LED_MAX_BRIGHTNESS , 0, 0);
      strip.sendPixels(LED_STRIP_COUNT, pixels);
      break;
    case IR_REMOTE_BUTTON_3:
      Serial.println("Cislo 3, BLUE");
      LED_updateColorsAll(0, 0, LED_MAX_BRIGHTNESS, 0);
      strip.sendPixels(LED_STRIP_COUNT, pixels);
      break;
    case IR_REMOTE_BUTTON_4:
      Serial.println("Cislo 4, WHITE");
      LED_updateColorsAll(0, 0, 0, LED_MAX_BRIGHTNESS);
      strip.sendPixels(LED_STRIP_COUNT, pixels);
      break;
    case IR_REMOTE_BUTTON_5:
      Serial.println("Cislo 5, RGB");
      LED_updateColorsAll(LED_MAX_BRIGHTNESS, LED_MAX_BRIGHTNESS, LED_MAX_BRIGHTNESS, 0);
      strip.sendPixels(LED_STRIP_COUNT, pixels);
      break;
    case IR_REMOTE_BUTTON_6:
      Serial.println("Cislo 6, RGBW");
      LED_updateColorsAll(LED_MAX_BRIGHTNESS, LED_MAX_BRIGHTNESS, LED_MAX_BRIGHTNESS, LED_MAX_BRIGHTNESS);
      strip.sendPixels(LED_STRIP_COUNT, pixels);
      break;
    case IR_REMOTE_BUTTON_7:
      Serial.println("Cislo 7, YELLOW");
      LED_updateColorsAll(LED_MAX_BRIGHTNESS, LED_MAX_BRIGHTNESS, 0 , 0);
      strip.sendPixels(LED_STRIP_COUNT, pixels);
      break;
    case IR_REMOTE_BUTTON_8:
      Serial.println("Cislo 8, PRESENT");
      rainbow1N(80);
      break;
    case IR_REMOTE_BUTTON_9:
      Serial.println("Cislo 9");
      break;
    case IR_REMOTE_BUTTON_HASHTAG:
      Serial.println("Enable PIR!");
      EnablePir = true;
      digitalWrite(STATUS_LED, LOW);
      break;
    case IR_REMOTE_BUTTON_STAR:
      Serial.println("Disable PIR!");
      EnablePir = false;
      digitalWrite(STATUS_LED, HIGH);
      break;
  }
}

#endif

/* EOF */

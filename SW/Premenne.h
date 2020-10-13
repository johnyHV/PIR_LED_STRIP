/**
   @file Premenne.h

   @brief Globalne premenne

   @author Miroslav Pivovarsky
   Contact: miroslav.pivovarsky@gmail.com

   @bug: no know bug

*/

#ifndef _PREMENNE_H_
#define _PREMENNE_H_

#include "Config.h"
#include "LedPas_cfg.h"
#include "IR_Remote_cfg.h"
#include "FAB_LED.h"

# if (IR_REMOTE_ENABLE == true)
#include <IRremote.h>
extern IRrecv IR_rx;                  ///< Objekt pre pracu s IR receiverom
#endif

extern sk6812<D, LED_PIN>  strip;     ///< Objekt pre pracu s LED pasom
extern rgbw pixels[LED_STRIP_COUNT];  ///< Pole objektov pre nastavenie kazdej LED na celom LED Pase

extern bool LedStripStatus;           ///< Vypnutie/zapnutie PIR senzora pomocou IR dialkoveho ovladania

extern uint8_t TimerCounter;          ///< Pocitadlo, kolko krat bol zavolany timer, od posledneho resetovania pocitadla
extern bool StartStripOn;             ///< Informacia o zapnutomm/vypnutom LED pase

extern bool EnablePir;                ///< Pomocou tejto premennej mozeme vypnut/zapnut detekciu pohybu cez IR dialkove ovladanie

#endif

/* EOF */

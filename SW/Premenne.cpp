/**
   @file Premenne.cpp

   @brief Globalne premenne

   @author Miroslav Pivovarsky
   Contact: miroslav.pivovarsky@gmail.com

   @bug: no know bug

*/

#include "Premenne.h"

#if (IR_REMOTE_ENABLE == true)
IRrecv IR_rx(IR_REC_INPUT);
#endif

sk6812<D, LED_PIN>  strip;
rgbw  pixels[LED_STRIP_COUNT] = {};

bool LedStripStatus = false;

uint8_t TimerCounter = 0;
bool StartStripOn = false;

bool EnablePir = true;

/* EOF */

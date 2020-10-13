/**
   @file PIR_Sensor.cpp

   @brief Inicializacia a kontrola PIR senzora

   @author Miroslav Pivovarsky
   Contact: miroslav.pivovarsky@gmail.com

   @bug: no know bug

*/

#include "PIR_Sensor.h"

/**

   @info Inicializacia PIR senzora
   @param none
   @return none
*/
void PIR_Init() {
  pinMode(PIR_IN, INPUT);
}

/**

   @info Kontrola stavu PIR senzora
   @param none
   @return detekcia pohybu
*/
bool PIR_CheckStatus() {
  return digitalRead(PIR_IN);
}

/* EOF */

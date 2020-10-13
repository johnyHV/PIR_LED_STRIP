/**
   @file PIR_Sensor.h

   @brief Inicializacia a kontrola PIR senzora

   @author Miroslav Pivovarsky
   Contact: miroslav.pivovarsky@gmail.com

   @bug: no know bug

*/

#ifndef _PIR_SENSOR_H_
#define _PIR_SENSOR_H_

#include "Premenne.h"
#include "Config.h"

void PIR_Init();              ///< Inicializacia PIR senzora
bool PIR_CheckStatus();       ///< Kontrola stavu PIR senzora

#endif

/* EOF */

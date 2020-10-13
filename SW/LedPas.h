/**
   @file LedPas.h

   @brief Praca s LED pasom

   @author Miroslav Pivovarsky
   Contact: miroslav.pivovarsky@gmail.com

   @bug: no know bug

*/

#ifndef _LED_PAS_H_
#define _LED_PAS_H_

#include "FAB_LED.h"
#include "LedPas_cfg.h"
#include "Config.h"
#include "Premenne.h"

void LED_updateColors(char r, char g, char b, char w);                          ///< Nastavenie farby na zakladnej dlzke LED pasu
void LED_updateColorsAll(char r, char g, char b, char w);                       ///< Nastavenie farby na celej dlzke LED pasu
void LED_updateColorsPixel(uint8_t index, char r, char g, char b, char w);      ///< Nastavenie farby na jednom pixele
void LED_StripClear();                                                          ///< Vymazanie nastavenia farby LED na celom LED pase
void LED_StripOn();                                                             ///< Zapnutie zakladnej dlzky led pasu svetelnym hadom
void LED_StripOff();                                                            ///< Vypnutie zakladnej dlzky led pasu svetelnym hadom
void LED_ShelfOneOn();                                                          ///< Zapnutie LED pasu na prvej policke
void LED_ShelfOneOff();                                                         ///< Vypnutie LED pasu na prvej policke
void LED_ShelfTwoOn();                                                          ///< Zapnutie LED Pasu na druhej policke
void LED_ShelfTwoOff();                                                         ///< Vypnutie LED Pasu na druhej policke
void LedTest();                                                                 ///< TEST efekt
void rainbow1N(uint8_t brightness);                                             ///< Rozsvietenie duhy na LED pase
static void colorWheel(uint8_t incStep, uint8_t & R, uint8_t & G, uint8_t & B); ///< nastavenie farby pre duhu

#endif

/* EOF */

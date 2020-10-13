/**
   @file LedPas_cfg.h

   @brief konfiguracia kniznice pre pracu s LED pasom

   @author Miroslav Pivovarsky
   Contact: miroslav.pivovarsky@gmail.com

   @bug: no know bug

*/

#ifndef _LED_PAS_CFG_H_
#define _LED_PAS_CFG_H_

#define LED_STRIP_COUNT     178     ///< Pocet LED diod na LED pase
#define LED_DELAY           25      ///< Oneskorenie medzi zapojenim LED diod
#define LED_MAX_BRIGHTNESS  255     ///< Jas LED diod na celom pase
#define LED_STRIP_TIMEOUT   60      ///< Cas, pocas ktoreho bude zapnuty LED pas

#define LED_NUMBER          149     ///< Pocet LED diod na hlavnej casti LED pasu
#define LED_CENTER          75      ///< Nastavenie strednej LED diody

#define LED_SHELF_1_COUNT   15      ///< Prva LED dioda pre policku 1
#define LED_SHELF_1_START   150     ///< Posledna LED dioda pre policku 1
#define LED_SHELF_2_COUNT   13      ///< Prva LED dioda pre policku 2
#define LED_SHELF_2_START   165     ///< Posledna LED dioda pre policu 2

#endif

/* EOF */

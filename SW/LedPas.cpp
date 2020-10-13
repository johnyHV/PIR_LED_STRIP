/**
   @file LedPas.cpp

   @brief Praca s LED pasom

   @author Miroslav Pivovarsky
   Contact: miroslav.pivovarsky@gmail.com

   @bug: no know bug

*/

#include "LedPas.h"

/**

   @info Nastavenie farby na zakladnej dlzke LED pasu
   @param char - intenzita RED
   @param char - intenzita GREEN
   @param char - intenzita BLUE
   @param char - intenzita WHITE
   @return none
*/
void LED_updateColors(char r, char g, char b, char w)
{
  for (int i = 0; i < LED_NUMBER; i++)
  {
    pixels[i].r = r;
    pixels[i].g = g;
    pixels[i].b = b;
    pixels[i].w = w;
  }
}

/**

   @info Nastavenie farby na celej dlzke LED pasu
   @param char - intenzita RED
   @param char - intenzita GREEN
   @param char - intenzita BLUE
   @param char - intenzita WHITE
   @return none
*/
void LED_updateColorsAll(char r, char g, char b, char w)
{
  for (int i = 0; i < LED_STRIP_COUNT; i++)
  {
    pixels[i].r = r;
    pixels[i].g = g;
    pixels[i].b = b;
    pixels[i].w = w;
  }
}

/**

   @info Nastavenie farby na jednom pixele
   @param uint8_t - Index LED
   @param char - intenzita RED
   @param char - intenzita GREEN
   @param char - intenzita BLUE
   @param char - intenzita WHITE
   @return none
*/
void LED_updateColorsPixel(uint8_t index, char r, char g, char b, char w) {
  pixels[index].r = r;
  pixels[index].g = g;
  pixels[index].b = b;
  pixels[index].w = w;
}

/**

   @info Vymazanie nastavenia farby LED na celom LED pase
   @param none
   @return none
*/
void LED_StripClear() {
  strip.clear(LED_STRIP_COUNT);
}

/**

   @info Zapnutie zakladnej dlzky led pasu svetelnym hadom
   @param none
   @return none
*/
void LED_StripOn() {
  for (uint8_t s = 0; s < LED_CENTER; s++) {
    LED_updateColorsPixel(s, 0, 0, 0, LED_MAX_BRIGHTNESS);
    LED_updateColorsPixel(LED_NUMBER - s, 0, 0, 0, LED_MAX_BRIGHTNESS);
    strip.sendPixels(LED_STRIP_COUNT, pixels);
    delay(LED_DELAY);
  }
  LED_updateColorsPixel(LED_CENTER, 0, 0, 0, LED_MAX_BRIGHTNESS);
  strip.sendPixels(LED_STRIP_COUNT, pixels);
}

/**

   @info Vypnutie zakladnej dlzky led pasu svetelnym hadom
   @param none
   @return none
*/
void LED_StripOff() {
  for (uint8_t s = 0; s < LED_CENTER; s++) {
    strip.sendPixels(LED_STRIP_COUNT, pixels);
    delay(LED_DELAY);
    LED_updateColorsPixel(s, 0, 0, 0, 0);
    LED_updateColorsPixel(LED_NUMBER - s, 0, 0, 0, 0);
  }
  LED_updateColorsPixel(LED_CENTER, 0, 0, 0, 0);
  strip.sendPixels(LED_STRIP_COUNT, pixels);
  strip.clear(2 * LED_NUMBER);
}

/**

   @info TEST efekt
   @param none
   @return none
*/
void LedTest() {

  // Write the pixel array red
  LED_updateColors(LED_MAX_BRIGHTNESS, 0 , 0, 0);
  // Display the pixels on the LED strip
  strip.sendPixels(LED_STRIP_COUNT, pixels);
  // Wait 0.1 seconds
  delay(1000);

  // Write the pixel array green
  LED_updateColors(0, LED_MAX_BRIGHTNESS, 0, 0);
  // Display the pixels on the LED strip
  strip.sendPixels(LED_STRIP_COUNT, pixels);
  // Wait 0.1 seconds
  delay(1000);

  // Write the pixel array blue
  LED_updateColors(0, 0, LED_MAX_BRIGHTNESS, 0);
  // Display the pixels on the LED strip
  strip.sendPixels(LED_STRIP_COUNT, pixels);
  // Wait 0.1 seconds
  delay(1000);

  // Write the pixel array white
  LED_updateColors( LED_MAX_BRIGHTNESS, LED_MAX_BRIGHTNESS, LED_MAX_BRIGHTNESS, 0);
  // Display the pixels on the LED strip
  strip.sendPixels(LED_STRIP_COUNT, pixels);
  // Wait 0.1 seconds
  delay(1000);

  // Write the pixel array warm white
  LED_updateColors( 0, 0, 0, LED_MAX_BRIGHTNESS);
  // Display the pixels on the LED strip
  strip.sendPixels(LED_STRIP_COUNT, pixels);
  // Wait 0.1 seconds
  delay(1000);

  // Turn off the LEDs
  strip.clear(LED_STRIP_COUNT);
  delay(500);
}

/**

   @info Zapnutie LED pasu na prvej policke
   @param none
   @return none
*/
void LED_ShelfOneOn() {
  for (uint8_t s = LED_SHELF_1_START; s < (LED_SHELF_1_START + LED_SHELF_1_COUNT); s++) {
    LED_updateColorsPixel(s, 0, 0, 0, LED_MAX_BRIGHTNESS);
    strip.sendPixels(LED_STRIP_COUNT, pixels);
    delay(LED_DELAY);
  }
}

/**

   @info Vypnutie LED pasu na prvej policke
   @param none
   @return none
*/
void LED_ShelfOneOff() {
  for (uint8_t s = LED_SHELF_1_START; s < (LED_SHELF_1_START + LED_SHELF_1_COUNT); s++) {
    LED_updateColorsPixel(s, 0, 0, 0, 0);
    strip.sendPixels(LED_STRIP_COUNT, pixels);
    delay(LED_DELAY);
  }
}

/**

   @info Zapnutie LED pasu na druhej policke
   @param none
   @return none
*/
void LED_ShelfTwoOn() {
  for (uint8_t s = LED_SHELF_2_START; s < (LED_SHELF_2_START + LED_SHELF_2_COUNT); s++) {
    LED_updateColorsPixel(s, 0, 0, 0, LED_MAX_BRIGHTNESS);
    strip.sendPixels(LED_STRIP_COUNT, pixels);
    delay(LED_DELAY);
  }
}

/**

   @info Vypnutie LED pasu na druhej policke
   @param none
   @return none
*/
void LED_ShelfTwoOff() {
  for (uint8_t s = LED_SHELF_2_START; s < (LED_SHELF_2_START + LED_SHELF_2_COUNT); s++) {
    LED_updateColorsPixel(s, 0, 0, 0, 0 );
    strip.sendPixels(LED_STRIP_COUNT, pixels);
    delay(LED_DELAY);
  }
}

/**

   @info Rozsvietenie duhy na LED pase
   @param uint8_t - jas
   @return none
*/
void rainbow1N(uint8_t brightness)
{
  rgb pix[1];

  // Initialize the colors on the array
  pix[0].r = brightness;
  pix[0].g = 0;
  pix[0].b = 0;

  // Display the LEDs
  const uint8_t oldSREG = SREG;
  cli();
  for (uint16_t i = 0; i < LED_STRIP_COUNT ; i++) {
    strip.sendPixels(1, pix);
    // Rotate the colors based on the pixel's previous color.
    colorWheel(1, pix[0].r, pix[0].g, pix[0].b);
  }
  SREG = oldSREG;
}

/**

   @info nastavenie farby pre duhu
   @param uint8_t - krok
   @param uint8_t - cervena
   @param uint8_t - zelena
   @param uint8_t - modra
   @return none
*/
static void colorWheel(uint8_t incStep, uint8_t & R, uint8_t & G, uint8_t & B)
{
  if (B == 0 && R != 0) {
    R = (R <= incStep) ? 0 : R - incStep;
    G = (G >= 255 - incStep) ? 255 : G + incStep;
    return;
  }
  if (R == 0 && G != 0) {
    G = (G <= incStep) ? 0 : G - incStep;
    B = (B >= 255 - incStep) ? 255 : B + incStep;
    return;
  }
  if (G == 0 && B != 0) {
    B = (B <= incStep) ? 0 : B - incStep;
    R = (R >= 255 - incStep) ? 255 : R + incStep;
    return;
  }
}

/* EOF */

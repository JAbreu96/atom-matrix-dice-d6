#include "./invaders.h";
#include "./utility.h";

#ifndef PIXEL_FUNCTIONS_H
#define PIXEL_FUNCTIONS_H

void traverseMatrix( Adafruit_NeoPixel&matrix, int invader[], const uint32_t colour) {
  uint16_t hue = getRandomHue();
  int size = sizeof(invader);

  if (size < 24) {
    Serial.println("Error: argument[1] size is less than 24");
    // exit(1);
    return;
  }

  for (int i = 0; i < size; i++) {
    if (invader[i] == 1) {
      matrix.setPixelColor(i, matrix.ColorHSV(hue, 200, 100));
    }
  }
}

void fillMatrix(Adafruit_NeoPixel&matrix, uint16_t hue) {
  matrix.fill(hue, 0, 25);
}

// Display the specified dice number on the matrix, in the specified colour.
void drawInvader( Adafruit_NeoPixel&matrix, const uint8_t number, const uint32_t colour ) {
  switch (number)
  {
    case 1:
      traverseMatrix(matrix, invader1, colour);
      break;
  
    case 2:
      traverseMatrix(matrix, invader2, colour);
      break;

    case 3:
      traverseMatrix(matrix, invader3, colour);
      break;

    case 4:
      traverseMatrix(matrix, invader4, colour);
      break;

    case 5:
      traverseMatrix(matrix, invader5, colour);
      break;

    case 6:
      traverseMatrix(matrix, invader6, colour);
      break;
  }
}

void clearMatrix(Adafruit_NeoPixel&matrix) {
  matrix.clear();
}

#endif
#include "M5Atom.h"
#include <ArduinoUnit.h>
#include <Adafruit_NeoPixel.h>
#include "./pixel-functions.h"
#include "./invaders.h"
#include "./utility.h"

#define PIN 27
#define NUM_LEDS 25
Adafruit_NeoPixel matrix = Adafruit_NeoPixel(25, PIN, NEO_GRB + NEO_KHZ800);

  //Tests that the display is cleared
  test(clear_matrix) {
    clearMatrix(matrix);

    //should Clear the Display
    for (int i = 0; i < 25; i++) {
      assertEqual(matrix.getPixelColor(i), 0);
    }
  };

  test(draw_invader_one) {
    //Call clearMatrix to clear LEDs
    clearMatrix(matrix);
    //Call drawInvader
    drawInvader(matrix, 1, 1600);

    for (int i = 0; i < 25; i++) {
      uint32_t pixelColor = matrix.getPixelColor(i);
      if (pixelColor > 0) {
        assertEqual(pixelColor > 0, invader1[i] == 1);
      }
    }
  };

  test(draw_invader_two) {
    clearMatrix(matrix);

    drawInvader(matrix, 2, 1600);

    for (int i = 0; i < 25; i++) {
      uint32_t pixelColor = matrix.getPixelColor(i);
      if (pixelColor > 0) {
        assertEqual(pixelColor > 0, invader2[i] == 1);
      }
    }
  };
  test(draw_invader_three) {
    clearMatrix(matrix);
    drawInvader(matrix, 3, 1600);

    for (int i = 0; i < 25; i++) {
      uint32_t pixelColor = matrix.getPixelColor(i);
      if (pixelColor > 0) {
        assertEqual(pixelColor > 0, invader3[i] == 1);
      }
    }
  };
  test(draw_invader_four) {
    clearMatrix(matrix);
    drawInvader(matrix, 4, 1600);

    for (int i = 0; i < 25; i++) {
      uint32_t pixelColor = matrix.getPixelColor(i);
      if (pixelColor > 0) {
        assertEqual(pixelColor > 0, invader4[i] == 1);
      }
    }
  };

  test(draw_invader_five) {
    clearMatrix(matrix);
    drawInvader(matrix, 5, 1600);

    for (int i = 0; i < 25; i++) {
      uint32_t pixelColor = matrix.getPixelColor(i);
      if (pixelColor > 0) {
        assertEqual(pixelColor > 0, invader5[i] == 1);
      }
    }
  };
  test(draw_invader_six) {
    clearMatrix(matrix);
    drawInvader(matrix, 6, 1600);

    for (int i = 0; i < 25; i++) {
      uint32_t pixelColor = matrix.getPixelColor(i);
      if (pixelColor > 0) {
        assertEqual(pixelColor > 0, invader6[i] == 1);
      }
    }
  };

  test(draw_invader_with_out_of_bound_number) {
    clearMatrix(matrix);
    drawInvader(matrix, 0, 1600);

    for (int i = 0; i < 25; i++) {
      uint32_t pixelColor = matrix.getPixelColor(i);
      
      assertEqual(pixelColor, 0);
    }
  }

  test(get_random_dice_roll) {
    uint8_t num = getRandomDiceRoll();

    assertLess(num, 7);
    assertMore(num, 0);
  }

  test(get_random_hue) {
    uint16_t hue = getRandomHue();

    assertLess(hue, 65537);
    assertMore(hue, -1);
  }

  test(fill_matrix) {
    clearMatrix(matrix);

    uint16_t hue = 1600;
    fillMatrix(matrix, hue);

    for (int i = 0; i < 25; i++) {
      uint32_t pixelColor = matrix.getPixelColor(i);
      assertEqual(pixelColor, 1600);
    }
  }

  test(traverse_matrix_with_empty_invader) {
    clearMatrix(matrix);

    int emptyInvader[] = {};

    traverseMatrix(matrix, emptyInvader, 1600);

    String error = Serial.readString();
    assertTrue(error.compareTo("Error: argument[1] size is less than 24"));
  }


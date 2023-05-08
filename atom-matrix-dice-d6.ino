#include "M5Atom.h"
#include "./space-invaders-test.h"
#include <Adafruit_NeoPixel.h>
#include "./pixel-functions.h"
#include <ArduinoUnit.h>
#include <EEPROM.h>
#include "./utility.h"

#define PIN 27
#define NUM_LEDS 25

//PIXELS OBJECT
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(25, PIN, NEO_GRB + NEO_KHZ800);

// The colour of the dots which show the number.
const CRGB g_foregroundColour{ 0xffffff };

// The colour of all the other pixels.
const CRGB g_backgroundColour{ 0x003300 };

void setup()
{
  Serial.begin(9600);
  Serial.write(0x0c);
  pinMode(39, INPUT_PULLUP);
  // Enable the matrix display, and ensure it's initially empty.
  pixels.begin();

  // Test::min_verbosity = TEST_VERBOSITY_ALL;
  // Test::exclude("get_random_dice_roll");
  
}

uint8_t state = 1;

void loop()
{
  Test::run();
  // Clear the matrix display when the button is pushed down.
  if (digitalRead(39) == LOW)
  {
    state = 0;
    pixels.clear();
    delay(100);
  }

  // Show a random number when the button is released.
  if (digitalRead(39) == HIGH && state == 0)
  {
    fillMatrix(pixels, getRandomHue());

    state = 1;
    
    drawInvader(pixels, getRandomDiceRoll(), g_foregroundColour);
    //Test the functions
    pixels.show();
    delay(100);
    
  }
}

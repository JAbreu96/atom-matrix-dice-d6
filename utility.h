#ifndef UTILITY_H
#define UTILITY_H
// Get a random number between 1 and 6 (inclusive).
uint8_t getRandomDiceRoll()
{
  // Any disconnected GPIO pin should work here:
  return (analogRead(32) % 6) + 1;
}

// Get a random hue
uint16_t getRandomHue() {
  return random(0, 65536);
}

#endif
  /*
  LEDBackpack_Peizo
  by Scott Kildall
  Janaury 3, 2017

  A simple Arudino sketch that uses the Adafruit LED backpack hooked to a Peizo.
  The (+) lead of the peizo goes to pin A0 and the (-) to GND.
  A 1M Ohm resistor goes from A0 to GND so that we don't have floating input.

  Uses the Adafruit LED Backpack libraries, which must be installead into your Arduino libraries folder

   When you 'knock' on the peizo, it will show the 10-bit analog value (0-1023) on the 4-digit LED display for about 250ms. Then it goes back to zero.

   The AdaFruit GitHub repo is here
   https://github.com/adafruit/Adafruit_LED_Backpack

   Adapted the KnockSensor code here: https://www.arduino.cc/en/Tutorial/KnockSensor
*/


#include "Adafruit_LEDBackpack.h"

Adafruit_7segment matrix = Adafruit_7segment();

int threshhold = 10;
int delayTime = 250;

//-- initialize the LED Backpack, set value to 0
void setup() {
  matrix.begin(0x70);
  matrix.print(0, DEC);
  matrix.writeDisplay();
}

//-- get value from A0. If greater than threshhold, show it
void loop() {
  int val= analogRead(A0);
  if (val >= threshhold) {
    // greater than theshhold: update display and delay so that we can read it
    matrix.print(val, DEC);
    delay(delayTime);
  }
  else
    //-- show ZERO if below threshhold
    matrix.print(0, DEC);     

   //-- update the LED display
   matrix.writeDisplay();
}

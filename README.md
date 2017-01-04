# LEDBackpack_Peizo
by Scott Kildall

www.kildall.com

January 3rd 2017

--------------------

A simple Arudino sketch that uses the Adafruit LED backpack hooked to a Peizo. The (+) lead of the peizo goes to pin A0 and the (-) to GND. A 1M Ohm resistor goes from A0 to GND so that we don't have floating input.

Uses the Adafruit LED Backpack libraries, which must be installead into your Arduino libraries folder

When you 'knock' on the peizo, it will show the 10-bit analog value (0-1023) on the 4-digit LED display for about 250ms. Then it goes back to zero.

Their GitHub repo is here
https://github.com/adafruit/Adafruit_LED_Backpack
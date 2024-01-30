# Arduino_Running_Water_Effect

## Overview

This Arduino sketch is designed to control a WS2811 LED strip using the FastLED library. The LED strip is triggered by a physical switch (or a relay), resulting in the illumination of LEDs in pairs with a warm color tone. The warm color aims to simulate a color temperature of approximately 4000 Kelvin.

## Hardware Setup

1.	**Arduino Mega 2560 R3**: This serves as the primary microcontroller.
2.	**WS2811 LED Strip**: Connected to digital pin 6 on the Arduino Mega.
3.	**Switch (Relays will also work)**: Connected to digital pin 4 and GND on the Arduino Mega.

## Global Variables

1. LED_PIN: Specifies the digital pin to which the WS2811 LED strip is connected (pin 6).
2. SWITCH_PIN: Specifies the digital pin to which the switch is connected (pin 4).
3. NUM_LEDS: Indicates the number of LEDs in the WS2811 LED strip (171 LEDs).
4. leds: An array used to store color information for each individual LED.
5. lastSwitchTime: Records the timestamp of the most recent switch trigger.
6. onDelay: Determines the delay duration for switching on 2 LEDs at a time (20 milliseconds).
7. offDelay: Determines the delay duration for switching off 2 LEDs at a time (20 milliseconds).
8. currentLED: Keeps track of the current LED position.
9. switchTriggered: A flag indicating whether the switch has been triggered.

## Functions

### setup()
Initializes the WS2811 LED strip using the FastLED library.
Configures the switch pin as an input with a pull-up resistor.
### switchOnTwoLEDs()
Illuminates 2 LEDs at a time with a warm color tone.
The color tone is represented by the CRGB(255, 180, 100) setting; adjust these values for the desired warmth.
Delays execution for the specified onDelay duration.
### switchOffTwoLEDs()
Turns off 2 LEDs at a time.
Delays execution for the specified offDelay duration.
### loop()
Monitors the state of the physical switch.
If the switch is pressed:
Illuminates LEDs in pairs from 0 to 171.
Sets the switchTriggered flag.
Records the timestamp of the switch trigger.
Waits for the switch to be released.
If switchTriggered and 10 seconds have passed:
Turns off LEDs in pairs starting from LED 171.
Resets the switchTriggered flag.

## Usage

1.	Connect the hardware components following the guidelines in the Hardware Setup section.
2.	Upload the provided Arduino code to the Arduino Mega using the Arduino IDE.
3.	Observe the behavior: pressing the switch triggers the LED strip, and it turns off after 10 seconds if not triggered again.

   	
## Customization

•	Adjust the RGB values in the CRGB(255, 180, 100) lines to change the warmth of the LED color.
•	Modify delay values (onDelay and offDelay) for different switching speeds.
Dependencies
•	FastLED Library

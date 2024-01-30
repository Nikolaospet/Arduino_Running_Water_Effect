# Arduino_Running_Water_Effect

## Overview

This Arduino sketch is designed to control a WS2811 LED strip using the FastLED library. The LED strip is triggered by a physical switch (or a relay), resulting in the illumination of LEDs in pairs with a warm color tone. The warm color aims to simulate a color temperature of approximately 4000 Kelvin.

## Hardware Setup

1.	**Arduino Mega 2560 R3**: This serves as the primary microcontroller.
2.	**WS2811 LED Strip**: Connected to digital pin 6 on the Arduino Mega.
3.	**Switch (Relays will also work)**: Connected to digital pin 4 and GND on the Arduino Mega.

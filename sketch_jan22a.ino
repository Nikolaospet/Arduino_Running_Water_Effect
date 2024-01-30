#include <FastLED.h>

#define LED_PIN       6   // Digital pin to which the LED strip is connected
#define SWITCH_PIN    4   // Digital pin to which the switch is connected
#define NUM_LEDS      171 // Number of LEDs in your strip

CRGB leds[NUM_LEDS];
unsigned long lastSwitchTime = 0;
const unsigned long onDelay = 20;     // Delay for switching on 2 LEDs at a time
const unsigned long offDelay = 20;    // Delay for switching off 2 LEDs at a time
int currentLED = 0; // Variable to keep track of the current LED
bool switchTriggered = false;

void setup() {
  FastLED.addLeds<WS2811, LED_PIN, BRG>(leds, NUM_LEDS);
  pinMode(SWITCH_PIN, INPUT_PULLUP);  // Internal pull-up resistor for the switch
}

void switchOnTwoLEDs() {
  if (currentLED < NUM_LEDS - 1) {
    // Set the color for the current LED to simulate a warmer tone
    leds[currentLED] = CRGB(255, 180, 100); // Adjust these values for the desired warmth
    leds[currentLED + 1] = CRGB(255, 180, 100); // Adjust these values for the desired warmth
    FastLED.show();
    delay(onDelay);  // Delay for the desired speed
    currentLED += 2;
  }
}

void switchOffTwoLEDs() {
  if (currentLED > 1) {
    leds[currentLED - 1] = CRGB::Black; // Turn off the previous LED
    leds[currentLED - 2] = CRGB::Black; // Turn off the second previous LED
    FastLED.show();
    delay(offDelay);  // Delay for the desired speed
    currentLED -= 2;
  }
}

void loop() {
  // Check the state of the switch
  if (digitalRead(SWITCH_PIN) == LOW) {
    // Switch is pressed, switch on LEDs from 0 to 171 in pairs with a warmer tone
    for (int i = 0; i < NUM_LEDS; i += 2) {
      switchOnTwoLEDs();
    }
    switchTriggered = true;
    lastSwitchTime = millis();

    // Wait for switch to be released before proceeding
    while (digitalRead(SWITCH_PIN) == LOW) {
      delay(10);
    }
  }

  // Check if it's time to switch off LEDs
  if (switchTriggered && millis() - lastSwitchTime > 10000) {
    // If the switch is not triggered again within 10 seconds, turn off LEDs in pairs starting from LED 171
    for (int i = NUM_LEDS - 2; i >= 0; i -= 2) {
      switchOffTwoLEDs();
    }
    switchTriggered = false;
  }

  // You can add additional code here if needed
}

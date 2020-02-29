#include <Adafruit_NeoPixel.h>
#include "TM1637.h"
#define LED_PIN    9 // WS2812 data pin
#define LED_COUNT 30 // The number of LEDs
#define CLK 3      // CLK pin of the TM1637 
#define DIO 2      // DIO pin of the TM1637
int brightness = 0;
int fadeAmount = 1;
TM1637 tm1637(CLK,DIO);
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  strip.begin(); // Initializes the string
  strip.show(); // Switching the whole strip off
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL); 
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  int d = analogRead(A1); // Reading the variable for the brightness
  int g = analogRead(A0)/2; // Reading the variable for yhe color
  int j = analogRead(A0)/2; // That one for the color too
  int a,b,h;
  int c = (analogRead(A0)/2)-470; // Green color

        if ((g-210)*2 > 420) { // Blue color
    a=0;
}
  else {
    
        if (g > 210) {
    h=(g-210)*2;
    a=g-h;
    
}
  else {
    a=g-h;
    h=0;
  }
  }

          if (j < 220) { // Red color
   b=0;
}
  else {
    b=(j-220);
  }
              if (j > 460) { // Red color
    b=0;

}

          if (c > 0) { // Green color
     brightness = brightness + fadeAmount;
  if (brightness <= 0 || brightness >= 2048) {
    fadeAmount = -fadeAmount;
    delay(12);

  }
}
          if (c < 0) { // Green color
     brightness = 0;

  }

  int e = d/10.2; // Calculates the percentage of brightness
  int f = d/4.02; // Calculates the brightness itself
  strip.setBrightness(f); // That one is setting the brightness
  strip.setBrightness(d); // That one is setting the brightness
  uint32_t color = strip.Color(b, brightness/8, a); // Color
  void display(int8_t DispData[]);
  tm1637.display(e); // Sending the percentage of brightness to the TM1637
  strip.fill(color, 0, LED_COUNT); // Sends color to the strip
  strip.show();  // That one updates the whole strip at once

}

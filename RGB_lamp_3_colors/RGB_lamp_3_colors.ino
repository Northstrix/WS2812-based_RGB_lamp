// Written by Maxim Bortnikov
// https://github.com/Northstrix/WS2812-based_RGB_lamp
#include <Adafruit_NeoPixel.h>
#include "TM1637.h"
#define LED_PIN    9 // WS2812 data pin
#define LED_COUNT 20 // The number of LEds
#define CLK 3      // CLK pin of the TM1637 
#define DIO 2      // DIO pin of the TM1637
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
  int g = analogRead(A2)/2; // Reading the variable for yhe color
  int j = analogRead(A2)/2; // That one for the color too
  int a,b,h,i ;
  int c = analogRead(A3)/4.02; // Green color

        if ((g-192)*2 > 384) { // Red color
    a=0;
}
  else {
    
        if (g > 192) {
    h=(g-192)*2;
    a=g-h;
    
}
  else {
    a=g-h;
    h=0;
  }
  }

          if (j < 128) { // Blue color
   b=0;
}
  else {
    b=(j-128)/1.5;
  }

  int e = d/10.2; // Calculates the percentage of brightness
  int f = d/4.02; // Calculates the brightness itself
  strip.setBrightness(f); // That one is setting the brightness
  uint32_t color = strip.Color(a, c, b);
  strip.fill(color, 0, LED_COUNT);
  void display(int8_t DispData[]);
  tm1637.display(e); // Sending the percentage of brightness to the TM1637
  strip.show();  // That one updates the whole strip at once

}

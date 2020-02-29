#include <Adafruit_NeoPixel.h>
#define LED_PIN    9 // WS2812 data pin
#define LED_COUNT 30 // The number of LEds
int brightness = 0;
int fadeAmount = 1;
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  strip.begin(); // Initializes the string
  strip.show(); // Switching the whole strip off
}

void loop() {
  int d = 220; // Set the brightness here 0-255
  int g = analogRead(A0)/2; // Reading the variable for yhe color
  int j = analogRead(A0)/2; // That one for the color too
  int a,b,f,h;
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


  strip.setBrightness(d); // That one is setting the brightness
  uint32_t color = strip.Color(b, brightness/8, a); // Color
  strip.fill(color, 0, LED_COUNT); // Sends color to the strip
  strip.show();  // That one updates the whole strip at once

}

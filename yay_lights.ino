#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define LED_COUNT 10
#define POT_PIN A0

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void rainbow(int potVal, float s = 1);

void setup() {
  #ifdef DEBUG
    Serial.begin(9600);
    Serial.print("yAY LIGHTS!");
  #endif

  strip.begin();
  strip.show();
  strip.setBrightness(25);
}

void loop() {
  int potVal = analogRead(POT_PIN);
  rainbow(potVal);
}

//the rainbow function from the sample code but with a potentiometer
void rainbow(int potVal, float s = 1)
{
  long firstPixelHue = map(potVal, 0, 1023, 0, s * 65536);
  for(int i=0; i<strip.numPixels(); i++)
  {
    int pixelHue = firstPixelHue + (s * i * 65536L / strip.numPixels());
    strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
  }
  strip.show();
}

#include <application.h>
#include "SunRiseLamp.h"
#include "neopixel/neopixel.h"

SunRiseLamp::SunRiseLamp(int totalTime, int pixelCount, int pixelPin, int pixelType) {
    colorInterval = (totalTime * 1000) / 1500;
    sunRiseTemp = 0;
    brightness = 0;
    neoPixelPtr = new Adafruit_NeoPixel(pixelCount, pixelPin, pixelType);
    neoPixelPtr->begin();
    neoPixelPtr->setBrightness(0);
    neoPixelPtr->show();
}

void SunRiseLamp::begin() {
    lastUpdate = millis();
}

bool SunRiseLamp::update() {
    unsigned long currentMillis = millis();
    if (currentMillis - lastUpdate > colorInterval) {
        if (direction == 1 && sunRiseTemp < 3500) {
            //make a smooth transition from 0 to 2255
            if( brightness < 255 )
                neoPixelPtr->setBrightness(brightness++);
        } else if (direction == -1 && sunRiseTemp > 2000) {
            //make a smooth transition from 2000k to 0
            if(sunRiseTemp <= 2255 && brightness > 0)
                neoPixelPtr->setBrightness(brightness--);
        } else {
            return (direction = 0);
        }
        lastUpdate = currentMillis;
        sunRiseTemp += direction;
        colorAll(kelvinToRGB(sunRiseTemp));
        return true;
    } else {
        return false;
    }
}

// Set the starting temp and direction of the sun
void SunRiseLamp::rise() {
    sunRiseTemp = 2000;
    direction = 1;
    brightness = 0;
    neoPixelPtr->setBrightness(brightness);
}

void SunRiseLamp::rise(int totalTime) {
    if(totalTime >= 15)
        colorInterval = (totalTime * 1000) / 1500;
    rise();
}


// Set the starting temp and direction of the sun
void SunRiseLamp::set() {
    sunRiseTemp = 3500;
    direction = -1;
    brightness = 255;
    neoPixelPtr->setBrightness(brightness);
}

// Convert kelvin to RGB
uint32_t SunRiseLamp::kelvinToRGB(int kelvin) {
    if(kelvin <= 2000)
        return 0;
    int temp = kelvin / 100;
    int red = 255, green, blue = 0;

    if( temp <= 66 ) {
        green = 99.4708025861 * log(temp) - 161.1195681661;
        if( temp > 19) {
            blue = 138.5177312231 * log(temp - 10) - 305.0447927307;
        }
    } else {
        red = 329.698727446 * pow(temp - 60, -0.1332047592);
        green = 288.1221695283 * pow(temp - 60, -0.0755148492);
        blue = 255;
    }

    return Adafruit_NeoPixel::Color(red, green, blue);
}

int SunRiseLamp::clamp(int n) {
    int x=n>255?255:n;
    return x<0?0:x;
}

// Set all pixels in the strip to a solid color
void SunRiseLamp::colorAll(uint32_t c) {
  for(uint16_t i = 0; i < neoPixelPtr->numPixels(); i++) {
    neoPixelPtr->setPixelColor(i, c);
  }
  neoPixelPtr->show();
}


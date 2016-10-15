#ifndef SunRiseLamp_h
#define SunRiseLamp_h

#include "application.h"
#include "neopixel/neopixel.h"
#include "math.h"

class SunRiseLamp {
public:
    SunRiseLamp(int totalTime, int pixelCount, int pixelPin, int pixelType);
    void begin();
    bool update();
    void rise();
    void rise(int totalTime); // total time for sunrise
    void set();
    uint32_t kelvinToRGB(int kelvin);
    int clamp(int x);
    void colorAll(uint32_t c);

private:
    Adafruit_NeoPixel* neoPixelPtr = NULL;
    unsigned int  colorInterval;
    unsigned long lastUpdate;
    int direction = 0;
    int sunRiseTemp;
    int brightness;
};

#endif


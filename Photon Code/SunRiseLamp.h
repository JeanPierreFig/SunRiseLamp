#ifndef SunRiseLamp_h
#define SunRiseLamp_h

#include "application.h"
#include "neopixel/neopixel.h"
#include "math.h"




class SunRiseLamp {
public:
    SunRiseLamp() {};
    void begin(int totalTime, int pixelCount, int pixelPin, int pixelType);	// total time for sunrise
    bool update();
    void rise();
    void set();
    void kelvinToRGB(int kelvin);
    int  clamp(int x,int min,int max);
    
private:
    Adafruit_NeoPixel* pixelStringPtr = NULL;
    int colorInterval;
    int lastUpdate;
    int colorIndex = 0;
    int direction = 0;
    int _pixelCount;
    int _pixelPin;
    int _pixelType;
    int sunRiseTemp;
    int r;
    int g;
    int b;
    int brightness;
    
    
};

#endif
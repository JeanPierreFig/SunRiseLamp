#include <application.h>

#include "SunRiseLamp.h"
#include "neopixel/neopixel.h"


void SunRiseLamp::begin(int totalTime, int pixelCount, int pixelPin, int pixelType)
{
    _pixelCount = pixelCount;
    _pixelPin = pixelPin;
    _pixelType = pixelType;
    pixelStringPtr = new Adafruit_NeoPixel(_pixelCount, _pixelPin, _pixelType);
    colorInterval = (totalTime * 1000) /1500;
    lastUpdate = millis();
    colorIndex = 0;
    pixelStringPtr->begin();
    pixelStringPtr->setBrightness(0);
    r = 0;
    g = 0;
    b = 0;
    sunRiseTemp = 0;
    brightness = 0;
    
    
    pixelStringPtr->show();
    delay(5000);
}

bool SunRiseLamp::update()
{
    bool updateLeds = false;
    
    int currentMillis = millis();
    if (currentMillis - lastUpdate > colorInterval)
    {
        
        
        if (direction == 1 && sunRiseTemp != 3500){
            
            //make the the smooth transition from 0 to 2255
            if( brightness != 255 ){
                
                pixelStringPtr->setBrightness(brightness);
                brightness++;
                
            }
            //set the color temp and call the convertion funtion
            sunRiseTemp++;
            kelvinToRGB(sunRiseTemp);
            
            updateLeds = true;
        }
        else if (direction == -1 && sunRiseTemp != 2000)
        {
            //make the the smooth transition from 2000k to 0
            if(sunRiseTemp <= 2255 && brightness !=0){
                pixelStringPtr->setBrightness(brightness);
                brightness--;
            }
            sunRiseTemp--;
            kelvinToRGB(sunRiseTemp);
            
            if(sunRiseTemp <= 2000){
                
                r = 0;
                g = 0;
                b = 0;
            }
            
            updateLeds = true;
        }
        else
        {
            lastUpdate = currentMillis;
            return direction = 0;
        }
        lastUpdate = currentMillis;
    }
    if(updateLeds)
    {
        
        
        for (int i = 0; i < _pixelCount; i++)
        {
            //we decleard r g and b in .h file
            pixelStringPtr->setPixelColor(i, r, g, b);
            
        }
        pixelStringPtr->show();
        
        
    }
    return true;
}

void SunRiseLamp::rise()
{
    //set the starting tep and diraction of the sun
    sunRiseTemp = 2000;
    direction = 1;
}

void SunRiseLamp::set()
{
    //set the starting bightnees and diraction of the sun
    brightness = 255;
    pixelStringPtr->setBrightness(255);
    sunRiseTemp = 3500;
    direction = -1;
}



//Convert kelvien to RGB

void SunRiseLamp::kelvinToRGB(int kelvin){
    
    int temp = kelvin / 100;
    
    int red, green, blue;
    
    if( temp <= 66 ){
        
        red = 255;
        
        green = temp;
        green = 99.4708025861 * log(green) - 161.1195681661;
        
        
        if( temp <= 19){
            
            blue = 0;
            
        } else {
            
            blue = temp-10;
            blue = 138.5177312231 * log(blue) - 305.0447927307;
            
        }
        
    } else {
        
        red = temp - 60;
        red = 329.698727446 * pow(red, -0.1332047592);
        
        green = temp - 60;
        green = 288.1221695283 * pow(green, -0.0755148492 );
        
        blue = 255;
        
    }
    
    
    
    r = clamp(red,   0, 255);
    g = clamp(green, 0, 255);
    b = clamp(blue,  0, 255);
    
    
    
}

int SunRiseLamp::clamp(int x,int min,int max ){
    
    if(x<min){ return min; }
    if(x>max){ return max; }
    
    return x;
}








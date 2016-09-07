// Created by Jean-Pierre Figaredo

#include "application.h"
#include "neopixel/neopixel.h"
#include "SunRiseLamp.h"

SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D0              //<<<<<<<<<<< check here
#define PIXEL_COUNT 14           //<<<<<<<<<<< check here
#define PIXEL_TYPE WS2812B      //<<<<<<<<<<< check here
#define PIXEL_BRIGHTNESS 70    //<<<<<<<<<<< check here

#define SUN_RISE_HOUR 6
#define SUN_SET_HOUR 18

#define Sun_RISE_LENGTH_IN_SEC 60  // Set this for how many seconds you wish to take to rise or set

SunRiseLamp sunriseLeds;
int lastHour = 24;

void setup()
{
  Particle.function("test", testSunMachine);
  Serial.begin(9600);
  sunriseLeds.begin(Sun_RISE_LENGTH_IN_SEC, PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);
  
  
}

void loop()
{
  sunriseLeds.update();
 
  int currentHour = Time.hour();
  if (currentHour == SUN_RISE_HOUR && currentHour != lastHour)
  {
    sunriseLeds.rise();
  }
  else if (Time.hour() == SUN_SET_HOUR && currentHour != lastHour)
  {
    sunriseLeds.set();
  }
  
  
  lastHour = currentHour;
}

int testSunMachine(const char* data)
{
  if(strstr(data, "set"))
  {
    Serial.println("Manually told to Set");
    sunriseLeds.set();
    return 0;
  }
  else if(strstr(data, "rise"))
  {
    Serial.println("Manually told to Rise");
    sunriseLeds.rise();
    return 1;
  }
  return -1;
}

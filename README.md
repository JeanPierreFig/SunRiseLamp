<p align="center">
<img src=https://cloud.githubusercontent.com/assets/13212319/18433365/1abbac9e-78b5-11e6-8289-19ff168eb87d.jpg?style=centerme
</p>

# SunRiseLamp
The goal of this project is to create a Sun Rise lamp so you can wake up more naturally.

#I would like to thank.
 BulldogLowell over at community.particle.io 

## Getting started 

First go to the particle web IDE. Create a new project and call it `SunRise`.

<img width="300" alt="screen shot 2016-08-10 at 11 00 29 am" src="https://cloud.githubusercontent.com/assets/13212319/17558915/3b67c142-5eea-11e6-83aa-3cfd603c193e.png">

After that, open SunRiseLamp.ino in a text editor and copy and paste the code into your new project in the web IDE.   NOTE: If there is a better way to implement this please notify me.


![giphy-4](https://cloud.githubusercontent.com/assets/13212319/17559402/1aeb3ece-5eec-11e6-87eb-8d5da6d47a61.gif)

<img width="463" alt="screen shot 2016-09-07 at 1 20 49 am" src="https://cloud.githubusercontent.com/assets/13212319/18300732/fa4d5364-7499-11e6-9370-8ec25e748857.png">

Now create new files in the Web IDE and add name them `SunRiseLamp.h` and `SunRiseLamp.cpp`

Copy the code from their corresponding files in your text editor and paste it into the new files you created in the web IDE.


Now go to the Library tab. Search for the neopixel library and add it to the new project. 

![giphy-5](https://cloud.githubusercontent.com/assets/13212319/17560024/689d8756-5eee-11e6-9831-14239eefb488.gif)

 If you have a WS2812b/neopixel strip connected to you photon you can flash the code
 
 if you want to change the parameters it's super simple. just change the value of does.
 
`#define PIXEL_PIN D0`
`#define PIXEL_COUNT 14`
`#define PIXEL_TYPE WS2812`
`#define PIXEL_BRIGHTNESS 70`
 




## Hardware

The Neopixels run on 5v logic but the Photon is 3v logic. A solution for this problom woud be a Logic Level Converter  from 3v to 5v, but if you're like me then you want to start now with what you have on hand Breadboard, strip and photon. The strips do work on 3v it's really not recomended, but they do work. Just don't try to turn on 60 LEDs. It worked for me with 14 LEDs at 70%  brightness. 

This is very simple connection. Again this is NOT the recommended way of doing it but it works. 
![breadboad](https://cloud.githubusercontent.com/assets/13212319/17562271/1a82aa9c-5ef8-11e6-8340-d7e90686b70f.jpg)

Now you can flash the photon.

![giphy-6](https://cloud.githubusercontent.com/assets/13212319/17564354/2f8e4dfc-5f01-11e6-9fc7-504189bbd58d.gif)

## Generate SunRise Hex

If you want to create your own Sunrise gradient, I created a little Processing program that will take an image and give you an array of hex vaules that you can copy and paste directly to the Web IDE.

First if you don't have Processing, you need to to download the software (it's a great program to do image/video processing with the IDE, and it's very similar to the Arduino IDE).

https://processing.org

Then in the GenerateSunRiseHex folder open the GenerateSunRiseHex.pde file and run the program. It will ask you for a image after that just click on "generate Hex" 

![giphy-7](https://cloud.githubusercontent.com/assets/13212319/17565992/9ff5d03c-5f07-11e6-8c4a-3a7f8ebba7a8.gif)

In the Processing IDE console all your hex are waiting for you to copy them to the web IDE.

![giphy-8](https://cloud.githubusercontent.com/assets/13212319/17569569/cbc4d8ac-5f16-11e6-9814-3e20d45e3520.gif)

## TODO 

 1. Ios app
 2. pcb
 3. lamp frame
 4. ...
 





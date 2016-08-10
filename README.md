
![sunriseimage]
(https://cloud.githubusercontent.com/assets/13212319/17459474/cb04972a-5c07-11e6-8d16-a966f8d0235e.png)

# SunRiseLamp
This projects goal is to create a Sun Rise lamp. So you can wake up more naturally.

## Getting started 

First go to the particle web IDE. There create a new project and call it SunRise.

<img width="300" alt="screen shot 2016-08-10 at 11 00 29 am" src="https://cloud.githubusercontent.com/assets/13212319/17558915/3b67c142-5eea-11e6-83aa-3cfd603c193e.png">

After that open the SunRiseLamp.ino and copy the code to the new project in the web IDE.   NOTE: If there is a better way to implement this please notify me.


![giphy-4](https://cloud.githubusercontent.com/assets/13212319/17559402/1aeb3ece-5eec-11e6-87eb-8d5da6d47a61.gif)

Just one more step.

Now go to the Library tab. Search for the neopixel library and add it to the new project. 

![giphy-5](https://cloud.githubusercontent.com/assets/13212319/17560024/689d8756-5eee-11e6-9831-14239eefb488.gif)

 If you have a WS2812b/neopixel strip connected to you photon you can flash the code



## hardware

The neopixel are 5v logic but the photon is 3v logic. A solution for this problom woud be a Logic Level Converter  from 3v to 5v, but if you're like me then you want to start now with what you have on hand Breadboard, strip and photon. The strips do work on 3v it's really not recomended, but they do work. Just don't try to turn on 60 led. It worked for me at 14 led with 70%  brightness. 

This is very simple connection. Again this is NOT the recommended way of doing it but it works. 
![breadboad](https://cloud.githubusercontent.com/assets/13212319/17562271/1a82aa9c-5ef8-11e6-8340-d7e90686b70f.jpg)

now you can flash the photon.

![giphy-6](https://cloud.githubusercontent.com/assets/13212319/17564354/2f8e4dfc-5f01-11e6-9fc7-504189bbd58d.gif)



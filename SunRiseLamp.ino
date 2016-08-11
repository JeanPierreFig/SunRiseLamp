// Created by Jean-Pierre Figaredo

#include "application.h"



// use for Build IDE


SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D0
#define PIXEL_COUNT 14
#define PIXEL_TYPE WS2812
#define PIXEL_BRIGHTNESS 70

#define SUN_RISE_HOUR 6

// 300 sec = 5 min example: 60*5=300 if 30 min 60*30 = 1800
#define Sun_RISE_LENGTH_IN_SEC 300


Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);



const char * HexArray[] = {
"000000",
"030102",
"080403",
"0C0704",
"120A07",
"170C08",
"1E0F0A",
"25140D",
"2B1710",
"311A12",
"3A1E13",
"422217",
"482718",
"502B1B",
"592E1E",
"603222",
"663622",
"6C3924",
"733C27",
"784029",
"80442C",
"85472E",
"8C4A30",
"904D32",
"965134",
"9B5436",
"A15637",
"A55A3B",
"AA5E3E",
"AF603F",
"B36340",
"B66643",
"BA6843",
"BD6B46",
"BE6C46",
"C06E48",
"C26E49",
"C4704B",
"C6734B",
"C8754D",
"C9764C",
"CA774D",
"CB784E",
"CD7A50",
"CE7D52",
"CF7E51",
"D07F52",
"D28154",
"D38255",
"D48356",
"D68558",
"D58759",
"D7895B",
"D88A5A",
"D88C5B",
"D98D5C",
"DA8E5D",
"D98F5E",
"DB9160",
"DB9361",
"DC9462",
"DD9563",
"DD9764",
"DE9865",
"DF9966",
"DE9B67",
"DF9C68",
"DF9D69",
"E09E6A",
"DFA06B",
"E1A26D",
"E0A36D",
"E1A46E",
"E1A56F",
"E2A670",
"E3A771",
"E1A871",
"E3AA73",
"E3AC74",
"E4AD75",
"E3AF76",
"E3AF76",
"E3B077",
"E4B178",
"E4B178",
"E4B379",
"E5B47A",
"E3B57A",
"E5B67E",
"E6B77F",
"E6B77F",
"E6B980",
"E7BA81",
"E5BB81",
"E5BA83",
"E6BB84",
"E5BC84",
"E6BD85",
"E6BD85",
"E6BF86",
"E6BF86",
"E7C089",
"E5C089",
"E6C18A",
"E6C18A",
"E6C18A",
"E6C38B",
"E6C38D",
"E7C48E",
"E5C48E",
"E6C58F",
"E6C590",
"E6C590",
"E6C791",
"E6C791",
"E6C693",
"E5C793",
"E6C894",
"E7C995",
"E7C995",
"E7C997",
"E5C997",
"E6CA98",
"E6CA9A",
"E6CA9A",
"E5CB9A",
"E6CC9B",
"E6CB9C",
"E6CB9C",
"E6CB9C",
"E7CC9D",
"E5CD9F",
"E5CD9F",
"E5CD9F",
"E5CDA1",
"E5CDA1",
"E6CEA2",
"E6CEA2",
"E5CEA4",
"E6CFA5",
"E6CFA5",
"E5CFA6",
"E5CFA6",
"E5CFA6",
"E5CFA8",
"E3D0A8",
"E3D0A8",
"E3D0A8",
"E2D0AA",
"E3D1AB",
"E3D1AD",
"E3D1AD",
"E1D1AD",
"E0D0AC",
"E1D1AF",
"E0D2AF",
"E0D2AF",
"E0D1B0",
"DFD2B0",
"DFD2B0",
"DFD2B0",
"DFD2B2",
"DDD2B2",
"DDD2B2",
"DDD2B4",
"DDD2B4",
"DBD2B3",
"DBD2B5",
"DBD2B5",
"DBD2B5",
"D9D2B6",
"D9D2B6",
"D9D2B6",
"D8D3B6",
"D8D2B8",
"D8D2B8",
"D6D2B7",
"D6D2B9",
"D6D2B9",
"D4D2B9",
"D4D2B9",
"D4D2BB",
"D2D2BA",
"D2D2BA",
"D2D1BC",
"D0D2BC",
"D0D2BC",
"D0D2BC",
"CFD2BD",
"CED1BC",
"CED1BC",
"CDD2BC",
"CDD2BE",
"CDD2BE",
"CBD3BE",
"CBD2C0",
"CAD1BF",
"C9D2BF",
"C9D2C1",
"C9D2C1",
"C6D1C0",
"C7D2C1",
"C5D2C0",
"C5D2C1",
"C5D2C1",
"C3D1C2",
"C4D2C3",
"C3D1C4",
"C1D1C4",
"C1D1C4",
"C0D0C3",
"BFD1C5",
"BFD1C5",
"BED0C4",
"BCD0C5",
"BCD0C5",
"BCD0C5",
"BBD0C7",
"BACFC6",
"B9D0C6",
"B8CFC5",
"B9D0C8",
"B6D0C7",
"B6D0C7",
"B5CEC8",
"B4CFC8",
"B4CFC8",
"B2CFCA",
"B1CEC9",
"B1CEC9",
"B0CFC9",
"AFCEC9",
"AECEC9",
"AECEC9",
"AECEC9",
"ADCDCA",
"ABCECA",
"ABCDCC",
"A9CDCB",
"A9CDCB",
"A7CECB",
"A5CDCC",
"A5CDCC",
"A3CDCB",
"A1CDCC",
"A1CDCC",
"9FCDCD",
"9FCDCD",
"9DCDCD",
"9CCCCE",
"9ACCCD",
"98CBCC",
"98CBCE",
"95CBCD",
"94CBCE",
"94CBCE",
"91CBCD",
"90CBCF",
"8FCACE",
"8ECBCE",
"8BCACF",
"8BCACF",
"89CACE",
"87CAD0",
"86C9CF",
"85CACF",
"84C9D0",
"82C9CF",
"80C9D0",
"80C9D0",
"7EC9CF",
"7EC9CF",
"7BC8D0",
"7AC9D0",
"79C8CF",
"78C8D1",
"76C9D1",
"75C8D0",
"74C9D0",
"73C7D1",
"71C8D1",
"71C8D1",
"6FC8D0",
"6EC6D0",
"6EC6D0",
"6DC7D0",
"6CC6D1",
"6AC6D1",
"6AC6D1",
"68C6D0",
"68C6D0",
"68C6D0",
"66C7D0",
"66C6D2",
"65C5D1",
"64C6D1",
"65C5D1",
"65C5D1",
"65C5D1",
"65C5D1",
};




void setup()
{
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  
  //comment this out if you don't want your sunrise immediately
   sunRise();
  
   
}
void loop()
{
    
  if(Time.hour() == SUN_RISE_HOUR){
      
      //Make the led start the sequence
       sunRise();
  }

}

void sunRise(){
    
    //loop through all the colors in the array
    for(int i=0; i<=299; i++ ){
    
    //This will make the sun rise 
     int time = (Sun_RISE_LENGTH_IN_SEC / 300)*1000;
     delay(time);
    
    String hexstring = HexArray[i];
    
   //convert the hex color into RGB values for the neopixel function 
   int number = (int)strtol(hexstring, NULL, 16);

     int r = number >> 16;
     int g = number >> 8 & 0xFF;
     int b = number & 0xFF;
     
   //Set all pixels to the same color and after the loop is done show it
   for(int p=0; p<strip.numPixels(); p++) {
       
      strip.setPixelColor(p,r,g,b);
      strip.setBrightness(PIXEL_BRIGHTNESS);
      
    }
    strip.show();
     
    
     
    }
     
}





#include "M5Atom.h"
#include <FastLED.h>
#define BRIGHTNESS 30 //constant value for brightness
const long interval = 1000; // interval of blinking

void setup(){
  M5.begin(true, false, true)
  FastLED.setBrightness(BRIGHTNESS); setting constant brightness
}

uint8_t FSM = 0;

void loop(){
  if(M5.Btn.wasPressed()){
    
    switch (FSM){
      case 0: // LED is black=off 
        M5.dis.drawpix(0, 0x000000);
        break; 
      case 1: // LED is blinking Red 
        M5.dis.drawpix(0, 0xf00000);
        break;  
      
    }

     FSM++;
        if (FSM >= 4)
        {
            FSM = 0;
        }
  }
  delay(50);
  M5.update();
}

#include "M5Atom.h"
#include <FastLED.h>
#define BRIGHTNESS 20 //constant value for brightness
#define NUM_LEDS 25 

//const long interval = 1000; // interval of blinking
//const int buttonpin = 39;

float accX = 0, accY = 0, accZ = 0;

void setup() {
  M5.begin(true, false, true);
  M5.IMU.Init();
  FastLED.setBrightness(BRIGHTNESS); //setting constant brightness

  //pinMode(buttonpin, INPUT);
}

uint8_t FSM = 0;

void loop() {
  
  //M5.IMU.getAccelData(&accX, &accY, &accZ);
  switch (FSM) {
    case 0: // LED is black=off
      M5.dis.fillpix(0x000000);
      break;
    case 1: // LED is blinking Red
      M5.dis.fillpix(0x00ff00);
      delay(10);
      M5.dis.fillpix(0x000000);
      delay(50);
      break;
    case 2: //LED is blinkind White 
      M5.dis.fillpix(0xffffff);
      delay(10);
      M5.dis.fillpix(0x000000);
      delay(50);
      break;
    case 3: //bracking REAR RED 
      M5.dis.fillpix(0x00ff00);
      break;
    case 4: //bracking FRONT WHITE
      M5.dis.fillpix(0xffffff);
      break;

      
  }
  if (M5.Btn.wasPressed()) {
    FSM++;
    if (FSM > 4)
    {
      FSM = 0;
    }
  }
  
  M5.update();
}

///hghg

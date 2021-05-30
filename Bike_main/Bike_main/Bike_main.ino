#include "M5Atom.h"
#include <FastLED.h>
#define BRIGHTNESS 30 //constant value for brightness
//const long interval = 1000; // interval of blinking
//const int buttonpin = 39;

float accX = 0, accY = 0, accZ = 0;

void setup() {
  M5.begin(true, false, true);
  FastLED.setBrightness(BRIGHTNESS); //setting constant brightness

  //pinMode(buttonpin, INPUT);
}

uint8_t FSM = 0;

void loop() {

  switch (FSM) {
    case 0: // LED is black=off
      M5.dis.drawpix(0, 0x000000);
      break;
    case 1: // LED is blinking Red
      M5.dis.drawpix(0, 0xf00000);
      break;
    case 2: //LED is blinkind White 
      M5.dis.drawpix(0, 0xf00000);
      break;
    case 3: //bracking 
      M5.dis.drawpix(0, 0xf00000);
      break;
    case 4:
      M5.dis.drawpix(0, 0xf00000);
      break;

      //M5.IMU.getAccelData(&accX, &accY, &accZ);
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

#include <HID-Project.h>
#include <HID-Settings.h>

unsigned int currentMatrix = 0;
unsigned int newMatrix = 0;
unsigned int matrixPin = A5;

unsigned int currentShifter = 0;
unsigned int newShifter = 0;
unsigned int xShifterPin = A4;
unsigned int yShifterPin = A3;
unsigned int rShifterPin = 2;

unsigned int currentPedalsA = 0;
unsigned int currentPedalsB = 0;
unsigned int currentPedalsC = 0;
unsigned int newPedalsA = 0;
unsigned int newPedalsB = 0;
unsigned int newPedalsC = 0;
unsigned int aPedalsPin = A0;
unsigned int bPedalsPin = A1;
unsigned int cPedalsPin = A2;

unsigned int matrixBias = 0;
unsigned int shifterBias = 13;

unsigned int getMatrix() {
  unsigned int val = analogRead(matrixPin);
  if     (val > 754)              return  1;
  else if(val > 402 && val < 754) return  2;
  else if(val > 277 && val < 402) return  3;
  else if(val > 211 && val < 277) return  4;
  else if(val > 171 && val < 211) return  5;
  else if(val > 143 && val < 171) return  6;
  else if(val > 123 && val < 143) return  7;
  else if(val > 108 && val < 123) return  8;
  else if(val >  96 && val < 108) return  9;
  else if(val >  86 && val <  96) return 10;
  else if(val >  78 && val <  86) return 11;
  else if(val >  72 && val <  78) return 12; 
  else return 0;
}

unsigned int getShifter() {
  unsigned int xShifter = analogRead (xShifterPin);
  unsigned int yShifter = analogRead (yShifterPin);
  unsigned int rShifter = digitalRead(rShifterPin);

  //553 mediana
  if        (yShifter > 800){ //1,3,5
    if      (xShifter > 100 && xShifter < 275) { return 1; }
    else if (xShifter > 275 && xShifter < 545) { return 3; }
    else if (xShifter > 545 && xShifter < 990) { return 5; }
    else                         { return 0; }
  } else if (yShifter < 300){ //2,4,6
    if      (xShifter > 100 && xShifter < 275) { return 2; }
    else if (xShifter > 275 && xShifter < 545) { return 4; }
    else if (xShifter > 545 && xShifter < 990) { 
                          if(rShifter == 1)     { return 7; }
                          else                  { return 6; }}
    else                                       {  return 0; }
  } else {
    return 0;
  } 
}

unsigned int getAccelerator() {
  unsigned int aPedals = analogRead(aPedalsPin);
  return aPedals;
  if     (aPedals > 900)                   return 1023;
  else if(aPedals > 800 && aPedals <= 900) return map(aPedals, 800, 900, 950, 1023);
  else if(aPedals > 700 && aPedals <= 800) return map(aPedals, 700, 800, 550,  750);
  else if(aPedals > 600 && aPedals <= 700) return map(aPedals, 600, 700, 400,  550);
  else if(aPedals > 500 && aPedals <= 600) return map(aPedals, 500, 600, 250,  400);
  else if(aPedals > 400 && aPedals <= 500) return map(aPedals, 400, 500, 150,  250);
  else if(aPedals > 300 && aPedals <= 400) return map(aPedals, 300, 400, 100,  150);
  else if(aPedals > 200 && aPedals <= 300) return map(aPedals, 200, 300,   0,  100);
  else if(aPedals > 100 && aPedals <= 200) return map(aPedals, 100, 200,   0,    0);
  else                                     return    0;
}

unsigned int getBrake() {
  unsigned int bPedals = analogRead(bPedalsPin);
  return bPedals;
  if     (bPedals > 900)                   return 1023;
  else if(bPedals > 800 && bPedals <= 900) return map(bPedals, 800, 900, 950, 1023);
  else if(bPedals > 700 && bPedals <= 800) return map(bPedals, 700, 800, 550,  750);
  else if(bPedals > 600 && bPedals <= 700) return map(bPedals, 600, 700, 400,  550);
  else if(bPedals > 500 && bPedals <= 600) return map(bPedals, 500, 600, 250,  400);
  else if(bPedals > 400 && bPedals <= 500) return map(bPedals, 400, 500, 150,  250);
  else if(bPedals > 300 && bPedals <= 400) return map(bPedals, 300, 400, 100,  150);
  else if(bPedals > 200 && bPedals <= 300) return map(bPedals, 200, 300,   0,  100);
  else if(bPedals > 100 && bPedals <= 200) return map(bPedals, 100, 200,   0,    0);
  else                                     return    0;
}

unsigned int getClunch() {
  unsigned int cPedals = analogRead(cPedalsPin);
  return cPedals;
  if     (cPedals > 900)                   return 1023;
  else if(cPedals > 800 && cPedals <= 900) return map(cPedals, 800, 900, 950, 1023);
  else if(cPedals > 700 && cPedals <= 800) return map(cPedals, 700, 800, 550,  750);
  else if(cPedals > 600 && cPedals <= 700) return map(cPedals, 600, 700, 400,  550);
  else if(cPedals > 500 && cPedals <= 600) return map(cPedals, 500, 600, 250,  400);
  else if(cPedals > 400 && cPedals <= 500) return map(cPedals, 400, 500, 150,  250);
  else if(cPedals > 300 && cPedals <= 400) return map(cPedals, 300, 400, 100,  150);
  else if(cPedals > 200 && cPedals <= 300) return map(cPedals, 200, 300,   0,  100);
  else if(cPedals > 100 && cPedals <= 200) return map(cPedals, 100, 200,   0,    0);
  else                                     return    0;
}

unsigned int normalize16(unsigned int val){
  return map(val, 0, 1023, -0x7FFF, 0x7FFF);
}

unsigned int normalize8(unsigned int val){
  return map(val, 0, 1023, -0x7F, 0x7F);
}

void setup() {
  Gamepad.begin();
  Gamepad.releaseAll();
}

void loop() {
  newShifter = getShifter();
  newMatrix  = getMatrix();
  newPedalsA = getAccelerator();
  newPedalsB = getBrake();
  newPedalsC = getClunch();
  if( newShifter != currentShifter || 
      newMatrix  != currentMatrix  ||
      newPedalsA != currentPedalsA ||
      newPedalsB != currentPedalsB ||
      newPedalsC != currentPedalsC ){
    Gamepad.releaseAll();

    currentShifter = newShifter;
    if(newShifter != 0){
      Gamepad.press(newShifter+shifterBias);
    }

    currentMatrix = newMatrix;
    if(newMatrix != 0){
      Gamepad.press(newMatrix+matrixBias);
    }

    currentPedalsA = newPedalsA;
    currentPedalsB = newPedalsB;
    currentPedalsC = newPedalsC;
    Gamepad.rxAxis(normalize16(newPedalsA));
    Gamepad.ryAxis(normalize16(newPedalsB));
    Gamepad.rzAxis(normalize8(newPedalsC));

    Gamepad.write();
  }
  delay(100);
}

/* United States of Buttons demo.
 * Matt Ronan 2018
 * 
 * This library makes it easy to process any kind of button/switch in complex ways.
 * It moves thru either 7,6,or 4 states depending on what your application calls for.
 * 
 * SevenStateButton: 
 *  0 = idle (constant)
 *  1 = pressed  (one-shot)
 *  2 = held (constant)
 *  3 = reach long hold threshold (one-shot)
 *  4 = held (constant)
 *  5 = released after short press (one-shot)
 *  6 = released after long press (one-shot)
 * 
 * SixStateButton:
 *  0 = idle (constant)
 *  1 = pressed  (one-shot)
 *  2 = held (constant)
 *  3 = held (constant)
 *  4 = released after short press (one-shot)
 *  5 = released after long press (one-shot)
 *  
 *  FourStateButton:
 *  0 = idle (constant)
 *  1 = pressed  (one-shot)
 *  2 = held (constant)
 *  3 = released (one-shot)
 *  
 */

#include <UnitedStatesOfButtons.h>

int buttonPin = A7;

SevenStateButton testButton1(buttonPin,1); 
SixStateButton   testButton2(buttonPin,1);
FourStateButton  testButton3(buttonPin,1);

int buttonToUse = 1;

void setup() {
  
}

void loop() {
  
  testButton1.update();
  testButton2.update();
  testButton3.update();

  if(buttonToUse == 1){
    //Seven-State button switch block
    switch(testButton1.state()){
      case 0: //idle
              break;
      case 1: Serial.println("button pressed");
              break;
      case 2: //held (constant)
              break;
      case 3: Serial.println("hit long hold thresh");
              break;
      case 4: //held (constant)
              break;
      case 5: Serial.println("button released (short press)");
              break;
      case 6: Serial.println("button released (long press)");
              break;
    }
  }
  else if(buttonToUse == 2){
    //Six-State button switch block
    switch(testButton2.state()){
      case 0: //idle
              break;
      case 1: Serial.println("button pressed");
              break;
      case 2: //held (constant)
              break;
      case 3: //held (constant)
              break;
      case 4: Serial.println("button released (short press)");
              break;
      case 5: Serial.println("button released (long press)");
              break;
    }
  }
  else{
    //Four-State button switch block
    switch(testButton3.state()){
      case 0: //idle
              break;
      case 1: Serial.println("button pressed");
              break;
      case 2: //held (constant)
              break;
      case 3: Serial.println("button released");
              break;
    }
  }
}

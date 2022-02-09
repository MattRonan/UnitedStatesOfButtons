/* United States of Buttons
 * Matt Ronan 2018
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
 * FourStateButton:
 *  0 = idle (constant)
 *  1 = pressed  (one-shot)
 *  2 = held (constant)
 *  3 = released (one-shot)
 *  
 * ThreeStateButton:
 *  0 = idle (constant)
 *  1 = pressed  (one-shot)
 *  2 = held (constant)
 *
 * TwoStateButton:
 *  0 = idle (constant)
 *  1 = pressed  (constant)
 *
 * (All buttons track double-clicks)
 */

#include "UnitedStatesOfButtons.h"
#include "Arduino.h"

//--------------These defaults typically work for most situations
#define defaultStickyLowTime 50
#define defaultRetriggerWait 100
#define defaultLongPressThreshold 500
#define defaultDoubleClickThreshold 250
//----------------------------------------------------

//-----------------------------------------------------------------Seven State Button-------------------------
SevenStateButton::SevenStateButton(int pin, int pullup){
  _pin = pin;
  if(pullup){pinMode(_pin,INPUT_PULLUP);}
  else{pinMode(_pin,INPUT);}
  doubleClickState = 0;
  stickyLowTime = defaultStickyLowTime;
  retriggerWait = defaultRetriggerWait;
  longPressThreshold = defaultLongPressThreshold;
  doubleClickThreshold = defaultDoubleClickThreshold;
};

int SevenStateButton::getPin(){
  return _pin;
}

int SevenStateButton::state(){
  return buttonState;
}

int SevenStateButton::doubleClick(){
  return doubleClickState;
}

void SevenStateButton::update(){
  
  if(doubleClickState == 1){ doubleClickState = 0;}
  
  if(buttonState == 1){ //this is outside a digital read of the pin so that no matter what, one shots only last one update cycle
    buttonState = 2; //button held state
  }
  else if(buttonState == 3){ 
    buttonState = 4; //button held state
  }
  
  if(digitalRead(_pin) == 1){ //button voltage high (not pressed)
    if(millis() >= buttonReleaseTracker + stickyLowTime){
      if(buttonState != 0){
        if(buttonState == 1 || buttonState == 2){ //released after short press
          buttonState = 5; //one-shot short press release state
        }
        else if(buttonState == 3 || buttonState == 4){ //released after long press
          buttonState = 6; //one-shot long press release state
        }
        else if(buttonState == 5 || buttonState == 6){
          buttonState = 0; //back to idle
        }
      }
    }
  } 
  else{ //button voltage low (presssed)
    if(buttonState == 0 && buttonPressedAt + retriggerWait < millis()){
      if(millis() - buttonPressedAt <= doubleClickThreshold){ doubleClickState = 1;} //doubleClick one-shot
      buttonPressedAt = millis();
      buttonState = 1; //one-shot pressed state
    }
    else if(buttonState == 1){
      buttonState = 2; //button held state
    }
    else if(buttonState == 2 && millis() > buttonPressedAt + longPressThreshold ){
      buttonState = 3; //button held for a 'long' time
    }  
    else if(buttonState == 3){
      buttonState = 4; //one-shot reached long hold threshold
    }
    buttonReleaseTracker = millis(); //sticky low effect
  } 
}

//-----------------------------------------------------------------Six State Button-------------------------
SixStateButton::SixStateButton(int pin, int pullup){
  _pin = pin;
  if(pullup){pinMode(_pin,INPUT_PULLUP);}
  else{pinMode(_pin,INPUT);}
  doubleClickState = 0;
  stickyLowTime = defaultStickyLowTime;
  retriggerWait = defaultRetriggerWait;
  longPressThreshold = defaultLongPressThreshold;
  doubleClickThreshold = defaultDoubleClickThreshold;
};

int SixStateButton::getPin(){
  return _pin;
}

int SixStateButton::state(){
  return buttonState;
}

int SixStateButton::doubleClick(){
  return doubleClickState;
}

void SixStateButton::update(){
  
  if(doubleClickState == 1){ doubleClickState = 0;}
  
  if(buttonState == 1){ //this is outside a digital read of the pin so that no matter what, one shots only last one update cycle
    buttonState = 2; //button held state
  }
  
  if(digitalRead(_pin) == 1){ //button voltage high (not pressed)
    if(millis() >= buttonReleaseTracker + stickyLowTime){
      if(buttonState != 0){
        if(buttonState == 1 || buttonState == 2){ //released after short press
          buttonState = 4; //one-shot short press release state
        }
        else if(buttonState == 3){ //released after long press
          buttonState = 5; //one-shot long press release state
        }
        else if(buttonState == 4 || buttonState == 5){
          buttonState = 0; //back to idle
        }
      }
    }
  } 
  else{ //button voltage low (presssed)
    if(buttonState == 0 && buttonPressedAt + retriggerWait < millis()){
      if(millis() - buttonPressedAt <= doubleClickThreshold){ doubleClickState = 1;} //doubleClick one-shot
      buttonPressedAt = millis();
      buttonState = 1; //one time pressed state
    }
    else if(buttonState == 2 && millis() > buttonPressedAt + longPressThreshold ){
      buttonState = 3; //button held for a 'long' time
    }  
    buttonReleaseTracker = millis(); //sticky low effect
  }
}


//-----------------------------------------------------------------Four State Button-------------------------
FourStateButton::FourStateButton(int pin, int pullup){
  _pin = pin;
  if(pullup){pinMode(_pin,INPUT_PULLUP);}
  else{pinMode(_pin,INPUT);}
  doubleClickState = 0;
  stickyLowTime = defaultStickyLowTime;
  retriggerWait = defaultRetriggerWait;
  longPressThreshold = defaultLongPressThreshold;
  doubleClickThreshold = defaultDoubleClickThreshold;
};

int FourStateButton::getPin(){
  return _pin;
}

int FourStateButton::state(){
  return buttonState;
}

int FourStateButton::doubleClick(){
  return doubleClickState;
}

void FourStateButton::update(){
  
  if(doubleClickState == 1){ doubleClickState = 0;}
  
  if(buttonState == 1){ //this is outside a digital read of the pin so that no matter what, one shots only last one update cycle
    buttonState = 2; //button held state
  }
  
  if(digitalRead(_pin) == 1){ //button voltage high (not pressed)
    
    if(millis() >= buttonReleaseTracker + stickyLowTime){
      if(buttonState != 0){
        if(buttonState == 1 || buttonState == 2){ //released after press
          buttonState = 3; //one-shot release state
        }
        else if(buttonState == 3){ //reset to idle
          buttonState = 0; 
        }
      }
    }
  } 
  else{ //button voltage low (presssed)
    if(buttonState == 0 && buttonPressedAt + retriggerWait < millis()){
      if(millis() - buttonPressedAt <= doubleClickThreshold){ doubleClickState = 1;} //doubleClick one-shot
      buttonPressedAt = millis();
      buttonState = 1; //one-shot pressed state
    }
    buttonReleaseTracker = millis(); //sticky low effect
  }
}

//-----------------------------------------------------------------Three State Button-------------------------
ThreeStateButton::ThreeStateButton(int pin, int pullup){
  _pin = pin;
  if(pullup){pinMode(_pin,INPUT_PULLUP);}
  else{pinMode(_pin,INPUT);}
  doubleClickState = 0;
  stickyLowTime = defaultStickyLowTime;
  retriggerWait = defaultRetriggerWait;
  doubleClickThreshold = defaultDoubleClickThreshold;
};

int ThreeStateButton::getPin(){
  return _pin;
}

int ThreeStateButton::state(){
  return buttonState;
}

int ThreeStateButton::doubleClick(){
  return doubleClickState;
}

void ThreeStateButton::update(){
  
  if(doubleClickState == 1){ doubleClickState = 0;}
  
  if(buttonState == 1){ //this is outside a digital read of the pin so that no matter what, one shots only last one update cycle
      buttonState = 2; //button held state
  }
  
  if(digitalRead(_pin) == 1){ //button voltage high (not pressed)
    
    if(millis() >= buttonReleaseTracker + stickyLowTime){
      if(buttonState == 1 || buttonState == 2){ //released after press
        buttonState = 0; //back to idle
      }
    }
  } 
  else{ //button voltage low (presssed)
    if(buttonState == 0 && buttonPressedAt + retriggerWait < millis()){
      if(millis() - buttonPressedAt <= doubleClickThreshold){ doubleClickState = 1;} //doubleClick one-shot
      buttonPressedAt = millis();
      buttonState = 1; //one-shot pressed state
    }
    buttonReleaseTracker = millis(); //sticky low effect
  }
}

//-----------------------------------------------------------------Two State Button-------------------------
TwoStateButton::TwoStateButton(int pin, int pullup){
  _pin = pin;
  if(pullup){pinMode(_pin,INPUT_PULLUP);}
  else{pinMode(_pin,INPUT);}
  doubleClickState = 0;
  stickyLowTime = defaultStickyLowTime;
  retriggerWait = defaultRetriggerWait;
  doubleClickThreshold = defaultDoubleClickThreshold;
};

int TwoStateButton::getPin(){
  return _pin;
}

int TwoStateButton::state(){
  //TwoStateButton is identical to ThreeStateButton except that when state is 2 it'll return 1 when queried, so that it always reads either 0 or 1 for the user.
  //Thats cause for double click functionality, we need state 1 to be a one shot, meaning we need 3 states, even though the user will only see 2 of them. 
  if(buttonState == 2){ 
    return 1;
  }
  else{
    return buttonState;
  }
}

int TwoStateButton::doubleClick(){
  return doubleClickState;
}

void TwoStateButton::update(){
  
  if(doubleClickState == 1){ doubleClickState = 0;}
  
  if(buttonState == 1){ //this is outside a digital read of the pin so that no matter what, one shots only last one update cycle
    buttonState = 2; //button held state
  }
  
  if(digitalRead(_pin) == 1){ //button voltage high (not pressed)
    
    if(millis() >= buttonReleaseTracker + stickyLowTime){
      if(buttonState == 1 || buttonState == 2){ //released after press
        buttonState = 0; //back to idle
      }
    }
  } 
  else{ //button voltage low (presssed)
    if(buttonState == 0 && buttonPressedAt + retriggerWait < millis()){
      if(millis() - buttonPressedAt <= doubleClickThreshold){ doubleClickState = 1;} //doubleClick one-shot
      buttonPressedAt = millis();
      buttonState = 1; //one-shot pressed state
    }
    buttonReleaseTracker = millis(); //sticky low effect
  }
}





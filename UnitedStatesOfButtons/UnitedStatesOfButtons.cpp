/* United States of Buttons
 * Matt Ronan 2018
 * 
 * 
 *
 *
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

#include "UnitedStatesOfButtons.h"
#include "Arduino.h"

//-----------------------------------------------------------------Seven State Button-------------------------
SevenStateButton::SevenStateButton(int pin, int pullup){
	_pin = pin;
	if(pullup){pinMode(_pin,INPUT_PULLUP);}
	else{pinMode(_pin,INPUT);}
	stickyLowTime = 50;
	retriggerWait = 100;
	longPressThreshold = 500;
};

int SevenStateButton::getPin(){
	return _pin;
}

int SevenStateButton::state(){
	return buttonState;
}

void SevenStateButton::update(){
	
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
				buttonState = 0;
			}
		  }
		}
		else{ //temporary fix.  If we're in here it's cause the button read low for a blip (but LESS than stickyLowTime) preventing it from moving to next state, but then flips back to LOW so we dont end and get a release
			   //the result is a couple updates where state is 1 for example.
			if(buttonState == 1){ buttonState = 2;}
			if(buttonState == 3){ buttonState = 4;}
		}
	  } 
	  else{ //button voltage low (presssed)
		if(buttonState == 0 && buttonPressedAt + retriggerWait < millis()){
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
	stickyLowTime = 50;
	retriggerWait = 100;
	longPressThreshold = 500;
};

int SixStateButton::getPin(){
	return _pin;
}

int SixStateButton::state(){
	return buttonState;
}

void SixStateButton::update(){
	
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
				buttonState = 0;
			}
		  }
		}
		else{ //temporary fix.  If we're in here it's cause the button read low for a blip (but LESS than stickyLowTime) preventing it from moving to next state, but then flips back to LOW so we dont end and get a release
			   //the result is a couple updates where state is 1 for example.
			if(buttonState == 1){ buttonState = 2;}
		}
	  } 
	  else{ //button voltage low (presssed)
		if(buttonState == 0 && buttonPressedAt + retriggerWait < millis()){
			buttonPressedAt = millis();
			buttonState = 1; //one time pressed state
		  }
		  else if(buttonState == 1){
			buttonState = 2; //button held state
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
	stickyLowTime = 50;
	retriggerWait = 100;
	longPressThreshold = 500;
};

int FourStateButton::getPin(){
	return _pin;
}

int FourStateButton::state(){
	return buttonState;
}

void FourStateButton::update(){
	
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
			buttonPressedAt = millis();
			buttonState = 1; //one-shot pressed state
		  }
		  else if(buttonState == 1){
			buttonState = 2; //button held state
		  }
		  buttonReleaseTracker = millis(); //sticky low effect
	  }
}



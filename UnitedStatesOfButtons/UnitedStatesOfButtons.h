/* United States of Buttons
 * Matt Ronan 2018 
 */

#ifndef UnitedStatesOfButtons_h
#define UnitedStatesOfButtons_h

#include "Arduino.h"

class SevenStateButton
{
	public:
		SevenStateButton(int pin,int pullup);
    void update();
    int state();
		int doubleClick();
		int getPin();
    int stickyLowTime;
		unsigned long longPressThreshold;
		unsigned long retriggerWait;
		unsigned long doubleClickThreshold;
	
	private:
    int _pin;
		int doubleClickState;
		int buttonState;
		unsigned long buttonPressedAt;
		unsigned long buttonReleaseTracker;
};

class SixStateButton
{
	public:
		SixStateButton(int pin,int pullup);
    void update();
    int state();
		int doubleClick();
		int getPin();
    int stickyLowTime;
		unsigned long longPressThreshold;
		unsigned long retriggerWait;
		unsigned long doubleClickThreshold;
	
	private:
    int _pin;
		int doubleClickState;
		int buttonState;
		unsigned long buttonPressedAt;
		unsigned long buttonReleaseTracker;
	
};

class FourStateButton
{
	public:
		FourStateButton(int pin,int pullup);
    void update();
    int state();
		int doubleClick();
		int getPin();
    int stickyLowTime;
		unsigned long longPressThreshold;
		unsigned long retriggerWait;
		unsigned long doubleClickThreshold;
	
	private:
    int _pin;
		int doubleClickState;
		int buttonState;
		unsigned long buttonPressedAt;
		unsigned long buttonReleaseTracker;
	
};

class ThreeStateButton
{
	public:
		ThreeStateButton(int pin,int pullup);
		void update();
		int state();
		int doubleClick();
		int getPin();
		int stickyLowTime;
		unsigned long retriggerWait;
		unsigned long doubleClickThreshold;
	
	private:
    int _pin;
		int doubleClickState;
		int buttonState;
		unsigned long buttonPressedAt;
		unsigned long buttonReleaseTracker;
	
};

class TwoStateButton
{
	public:
		TwoStateButton(int pin,int pullup);
    void update();
    int state();
		int doubleClick();
		int getPin();
    int stickyLowTime;
		unsigned long retriggerWait;
		unsigned long doubleClickThreshold;
	
	private:
    int _pin;
		int doubleClickState;
		int buttonState;
		unsigned long buttonPressedAt;
		unsigned long buttonReleaseTracker;
	
};
#endif

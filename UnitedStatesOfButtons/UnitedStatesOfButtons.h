#ifndef UnitedStatesOfButtons_h
#define UnitedStatesOfButtons_h

#include "Arduino.h"

class SevenStateButton
{
	public:
	
	SevenStateButton(int pin,int pullup);
    void update();
    int state();
	int getPin();
	
    int stickyLowTime;
	unsigned long longPressThreshold;
	unsigned long retriggerWait;
	
	private:
    int _pin;
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
	int getPin();
	
    int stickyLowTime;
	unsigned long longPressThreshold;
	unsigned long retriggerWait;
	
	private:
    int _pin;
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
	int getPin();
	
    int stickyLowTime;
	unsigned long longPressThreshold;
	unsigned long retriggerWait;
	
	private:
    int _pin;
	int buttonState;
	unsigned long buttonPressedAt;
	unsigned long buttonReleaseTracker;
	
};

#endif

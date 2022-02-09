# UnitedStatesOfButtons

A variety of multi-state buttons in C++/Arduino.  Also tracks double-clicks.

Some states are one-shots, meaning that the state will occur for only one update cycle, allowing events to be triggered, things to be reset, etc.
A 7-state button is the most thorough, but lower state buttons are included for simpler applications.

SevenStateButton: 
0 = idle (constant)
1 = pressed  (one-shot)
2 = held (constant)
3 = reach long hold threshold (one-shot)
4 = held (constant)
5 = released after short press (one-shot)
6 = released after long press (one-shot)

SixStateButton:
0 = idle (constant)
1 = pressed  (one-shot)
2 = held (constant)
3 = held (constant)
4 = released after short press (one-shot)
5 = released after long press (one-shot)
  
FourStateButton:
0 = idle (constant)
1 = pressed  (one-shot)
2 = held (constant)
3 = released (one-shot)
   
ThreeStateButton:
0 = idle (constant)
1 = pressed  (one-shot)
2 = held (constant)
 
TwoStateButton:
0 = idle (constant)
1 = pressed  (constant)

# UnitedStatesOfButtons

A variety of multi-state buttons in C++/Arduino.  Also tracks double-clicks.

![helpGif](https://user-images.githubusercontent.com/11184076/153303388-15d9661e-30c5-473a-9218-d7ee5116a0c6.gif)

(Animation shows a 6-state button)

The maximum number of states is 7, minimum is 2. Some states are one-shots, meaning that the state will occur for only one update cycle, allowing events to be triggered, things to be reset, etc. A 7-state button is the most thorough, but lower-state buttons are included for convenience in simpler applications (see source for full explanation).



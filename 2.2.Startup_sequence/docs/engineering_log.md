

\### `engineering\_log.md`



```markdown

\# Engineering Log



\## Project



Alarm State Machine Practice



Part of the learning and development work for:



\*\*Project 2 - Reactor Startup Sequencer\*\*



\---



\## Objective



Build a small state-machine system that could:



1\. Wait in an idle state.

2\. Detect a button press.

3\. Begin an 8-second countdown.

4\. Display the countdown on a 16x2 LCD.

5\. Enter an alarm state automatically.

6\. Activate a buzzer.

7\. Return to idle after another button press.



The project was also used to practice `millis()` before applying the same timing

architecture to the larger Reactor Startup Sequencer.



\---



\## State Architecture



The system uses:



```cpp

enum systemstate {

&#x20; IDLESTATE,

&#x20; ARMED,

&#x20; ALARM

};


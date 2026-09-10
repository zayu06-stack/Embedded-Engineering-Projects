\# Alarm State Machine Practice



A small Arduino state-machine project created as part of the development work for

Project 2: Reactor Startup Sequencer.



The purpose of this exercise was to practice non-blocking timing using `millis()`,

state transitions using an `enum`, button edge detection, LCD output, and buzzer

control before applying the same concepts to the full Reactor Startup Sequencer.



\## Hardware



\- Arduino Uno

\- 16x2 LCD

\- Pushbutton

\- Passive buzzer

\- Breadboard

\- Jumper wires



\## System States



The system has three states:



```text

IDLESTATE

&#x20;   |

&#x20;   | Button press

&#x20;   v

ARMED

&#x20;   |

&#x20;   | 8 seconds elapsed

&#x20;   v

ALARM

&#x20;   |

&#x20;   | Button press

&#x20;   v

IDLESTATE


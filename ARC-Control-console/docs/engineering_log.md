\# Engineering Log



\## 7 September 2026



\### Goal



Build an Arduino-based control console combining an LCD, button, potentiometer, LEDs, and buzzer into one system.



\### Progress



\- Implemented system ON/OFF toggle using a push button

\- Added LCD standby and online states

\- Added potentiometer input

\- Mapped potentiometer input to 0-100% power

\- Added PWM LED brightness control

\- Added startup and shutdown buzzer tones

\- Refactored startup behavior into a separate function



\### Problems Encountered



\#### Button input stuck LOW



The button input initially remained LOW continuously.



\*\*Diagnosis:\*\*  

Disconnected the GPIO input from the button circuit. The input returned HIGH, confirming the Arduino pin and code were functioning correctly.



\*\*Root cause:\*\*  

Button wiring was placed on breadboard holes that were electrically connected.



\*\*Fix:\*\*  

Repositioned the button wiring and used `INPUT\_PULLUP`.



\#### Potentiometer reading stuck at maximum



The analog input temporarily remained at 1023.



\*\*Root cause:\*\*  

Loose jumper connection.



\*\*Fix:\*\*  

Reseated the potentiometer connection.



\#### LCD contrast



The LCD contrast potentiometer was later reused for analog input, requiring a separate contrast solution.



\### What I Learned



\- Breadboard connectivity must be traced electrically, not visually

\- `INPUT\_PULLUP` makes button wiring simpler

\- Analog inputs can be diagnosed using Serial Monitor

\- PWM output uses `analogWrite()`

\- State variables can control complete system behavior

\- Functions help separate system behaviors from the main loop


#include<LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int buzzer = 9;
int button = 8 ;
unsigned long previoustime = 0;
bool systemon = false;
int lastbuttonstate = HIGH;


enum systemstate {
  IDLESTATE,
  ARMED,
  ALARM
};

systemstate currentstate = IDLESTATE;


void setup() {
  lcd.begin(16, 2);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
  
  int buttonstate = digitalRead(button);
  Serial.println(buttonstate);
  unsigned long currenttime=millis();
  if (buttonstate == LOW && lastbuttonstate == HIGH) {
    if (currentstate == IDLESTATE) {
      currenttime = millis();
      currentstate = ARMED;
    } else {
      currentstate = IDLESTATE;
      currenttime = millis();
    }
    previoustime = currenttime;
    
  }
  lastbuttonstate = buttonstate;
  unsigned long elapsed = currenttime - previoustime;
  int countdown = 8 - (elapsed/1000);

  switch (currentstate) {
    case IDLESTATE:
      lcd.setCursor(0, 0);
      lcd.print("IDLE            ");
      noTone(buzzer);
      break;

    case ARMED:
      Serial.println(elapsed);
      if (elapsed < 8000) {
        lcd.setCursor(0, 0);
        lcd.print("Armed:          ");
        noTone(buzzer);
          
          lcd.setCursor(7,0);
          lcd.print(countdown);
          }
         
         else {
          currentstate = ALARM;
        }
        break;

      case ALARM:
      lcd.setCursor(0,0);
        lcd.print("ALARMMM!!!!!!");
        
        tone(buzzer,1500);

        break;



      }

  }

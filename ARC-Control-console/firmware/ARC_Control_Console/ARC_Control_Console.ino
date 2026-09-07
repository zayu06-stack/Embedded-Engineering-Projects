
#include <LiquidCrystal.h>
int led1 = 9;
int led2 = 12;
int buzzer = 11;
int pot = A0;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int button = 8;
int lastbuttonstate = HIGH;
bool systemon = false;

void setup() {
  lcd.begin(16, 2);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT_PULLUP);

}

void loop() {
  int potv = analogRead(pot);
  int power = map(potv, 0, 1023, 0, 100);
  int brightness = map(potv, 0, 1023, 0, 255);
  int buttonstate = digitalRead(button);
  if (buttonstate == LOW && lastbuttonstate == HIGH) {
    systemon = !systemon;

    if (systemon) {
      startupsequence();
    } else {
      shutdownsequence();

    }
  }
  lastbuttonstate = buttonstate;
  if (systemon) {
    lcd.setCursor(0, 0);
    lcd.print("ARC CORE ONLINE ");
    analogWrite(led1, brightness);
    digitalWrite(led2, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Power:");
    lcd.print(power);
    lcd.print("   ");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("ARC Core Standby");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    analogWrite(led1, 0);
    digitalWrite(led2, LOW);
  }
}



void startupsequence() {
  tone(buzzer, 1000, 150);
  delay(150);
  tone(buzzer, 2000, 150);
}

void shutdownsequence() {
  tone(buzzer, 2000, 150);
  delay(150);
  tone(buzzer, 1000, 150);
}

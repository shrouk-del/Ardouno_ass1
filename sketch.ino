#include <LiquidCrystal_I2C.h>

int redLED = 8;
int yellowLED= 7;
int greenLED = 6;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  lcd.begin(16, 2);
  lcd.backlight();
}

void loop() {
  digitalWrite(redLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("STOP");
  delay(5000);

  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(greenLED, LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("GET READY");
  delay(2000);

  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WALK");
  delay(5000);
}
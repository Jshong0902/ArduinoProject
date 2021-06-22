//AT+ROLE=1
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

#define f1 9
#define f2 10
#define LCD1 18
#define LCD2 19
SoftwareSerial BT(2, 3);

char data = 0;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(f1, OUTPUT);
  pinMode(f2, OUTPUT);
  lcd.begin();
  lcd.clear();
  lcd.backlight();
}

void loop() {
  if (BT.available() > 0) {
    data = BT.read();
  }
  if (data=='a'){
    analogWrite(f2, 75);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Wind Count 1");
    delay(100);
  }
  if (data=='b'){
    analogWrite(f2, 150);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Wind Count 2");
    delay(100);
  }
  if (data=='c'){
    analogWrite(f2, 220);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Wind Count 3");
    delay(100);
  }
  if (data=='d'){
    analogWrite(f2, 0);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("stop");
    delay(100);
  }
}

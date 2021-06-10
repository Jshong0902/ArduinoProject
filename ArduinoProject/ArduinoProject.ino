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
}

void loop() {
  if (BT.available() > 0) {
    data = BT.read();
  }
  if (data=='a'){
    digitalWrite(f1, 1);
  }
  if (data=='d'){
    digitalWrite(f1, 0);
  }
}

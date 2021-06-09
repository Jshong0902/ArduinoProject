#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

#define fanpin1 7
#define fanpin2 8
#define BTtx 2
#define BTrx 3
#define LCD1 18
#define LCD2 19
SoftwareSerial BT(2, 3);

char data = 0;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(fanpin1, OUTPUT);
  pinMode(fanpin2, OUTPUT);
  lcd.begin();
}

void loop() {
  if (BT.available()) {
    Serial.write(BT.read());
  }
  if (BT.available()) {
    BT.write(Serial.read());
  }

}

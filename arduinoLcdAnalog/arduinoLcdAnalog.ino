#include <LiquidCrystal_I2C.h>
int A = 9;
int B = 10;
int moter = 10;
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  lcd.begin();
  lcd.clear();
  lcd.backlight();
  lcd.print("Wind : 0");
  lcd.setCursor(0, 1);
  lcd.print("time : 0");
  Serial.begin(9600);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  analogWrite(A, 0);
  analogWrite(B, 0); 
  Serial.println("Wind : press 1, Time : press 2");
}

void loop()
{

  int wind_num;
  int time_num;
  int type = 0;
  int settinging = 0;
  if (Serial.available())
  {
    type = Serial.parseInt();
    settinging = 1;
    while (settinging != 0)
    {
      if (type == 1)
      {
        Serial.println("Set wind power : ");
        while (settinging != 0)
        {
          if (Serial.available())
          {
            wind_num = Serial.parseInt();
            if (wind_num > 10)
            {
              Serial.println("Max : 10. Please retry.");
              break;
            }
            else
            {
              analogWrite(B, wind_num*25);
              lcd.setCursor(7, 0);
              settinging = 0;
              type = 0;
              lcd.print(wind_num);
              lcd.print("        ");
            }
          }
        }
      }
      else if (type == 2)
      {
        Serial.println("Set timer : ");
        while (settinging != 0)
        {
          if (Serial.available())
          {
            time_num = Serial.parseInt();
            lcd.setCursor(7, 1);
            settinging = 0;
            type = 0;
            lcd.print(time_num);
            lcd.print("        ");
          }
        }
      }
      else
      {
        Serial.println("Wrong type");
        settinging = 0;
        type = 0;
      }
    }
    Serial.println("Wind : press 1, Time : press 2");
  }

}

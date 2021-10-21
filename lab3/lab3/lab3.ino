#include <LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 4, 5, 6 ,7);

void setup()
{
  lcd.begin(16, 2); // размеры дисплея
}

void loop()
{
  lcd.print("I love AUES");
  delay(3000);
  lcd.clear();
  lcd.print("Created by T.K.");
  delay(3000);
  lcd.clear();
}

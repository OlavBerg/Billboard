#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int lcdNumOfColumns = 16;
const int lcdNumOfRows = 2;

void setup() {
  lcd.begin(lcdNumOfColumns, lcdNumOfRows);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    
    String message = Serial.readStringUntil('\n');
    int numOfScrollIterations = lcdNumOfColumns + message.length();
    
    while (!Serial.available()) {
      lcd.clear();
      lcd.setCursor(lcdNumOfColumns, 0);
      lcd.print(message);

      for (int i = 0; i < numOfScrollIterations && !Serial.available(); i++) {
        lcd.scrollDisplayLeft();
        delay(250);
      }
    }
  }
}

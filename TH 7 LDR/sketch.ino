#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello");
  delay(1000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  int N = analogRead(A0);
  float voltage = (N*5)/1023.0;
  float percent = (voltage/4.92) * 100;
  float percent_lux = constrain(percent, 0.0, 100.0);
  lcd.setCursor(0,0);
  displayV(voltage);
  lcd.setCursor(0,1);
  displayP(percent_lux);
}

void displayV(float voltage) {
  lcd.print("Voltage:");
  lcd.print(voltage);
  lcd.print("V");
}
void displayP(float percent){
  lcd.print("Brightness:");
  if(percent<100){
      lcd.print(percent, 1);
  } else{
    lcd.print(percent, 0);
  }
  lcd.print("% ");
}
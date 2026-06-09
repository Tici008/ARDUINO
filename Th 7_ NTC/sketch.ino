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
  float a = (4.66-0.56)/(-24-80);
  float b = (4.66-(a*-24));
  float temp = (voltage-b)/a;
  lcd.setCursor(0,0);
  displayV(voltage);
  lcd.setCursor(0,1);
  displayT(temp);
}

void displayV(float voltage) {
  lcd.print("Voltage:");
  lcd.print(voltage);
  lcd.print("V");
}
void displayT(float temp){
  lcd.print("Temp:");
  if (temp >79.94 || temp <-23.94 ){
    lcd.print(temp, 0);
  } else{
    lcd.print(temp);
  }

  lcd.write(0xDF);
  lcd.print("C        ");
}
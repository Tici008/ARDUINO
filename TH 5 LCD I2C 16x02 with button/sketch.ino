#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int btn[2] = {2, 3};
const int nextBtn = 9;
bool state = false;
String password = "";
bool lastState = LOW; 
volatile bool isKeyPressed = false;
volatile char lastCharPressed = ' ';
void setup() {
  // put your setup code here, to run once:
  pinMode(nextBtn, INPUT);
  pinMode(btn[0], INPUT);
  pinMode(btn[1], INPUT);
  lcd.init();
  lcd.backlight();
  lcd.cursor();
  lcd.setCursor(0, 0);
  lcd.print("Hello");
  attachInterrupt(digitalPinToInterrupt(btn[0]), oneDisplay, RISING );
  attachInterrupt(digitalPinToInterrupt(btn[1]), twoDisplay, RISING );

}


void loop() {

  //1 va 2
  if(isKeyPressed) {
    isKeyPressed = false;
    lcd.print(lastCharPressed);
  }
  //Enter
  bool currentState = digitalRead(nextBtn);
  if(currentState == HIGH && lastState == LOW){
    if (!state) {
    lcd.clear();
    lcd.print("Password");
    lcd.setCursor(0, 1);
    state = true;
  } else {
    if (password.length() == 0) {
      lcd.clear();
      lcd.print("Please enter");
      lcd.setCursor(0, 1);
      lcd.print("your password");
      delay(3000);
      //----
      lcd.clear();
      lcd.print("Password");
      lcd.setCursor(0, 1);
    } else {
      if (password == "1122") {
        //Welcome
        lcd.clear();
        lcd.print("Welcome");
      } else {
        //Access Denied
        lcd.clear();
        lcd.print("Access Denied");
        delay(2000);
        //reset mk
        lcd.clear();
        lcd.print("Password");
        password = "";
        lcd.setCursor(0,1);
      }
    }
  }
  }
  lastState = currentState;

}


void oneDisplay() {
  if (state) {
    password += '1';
    lastCharPressed = '1';
    isKeyPressed = true;
  }

}
void twoDisplay() {
  if (state) {
    password+= '2';
    lastCharPressed = '2';
    isKeyPressed = true;
  }
}

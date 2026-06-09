#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
const int upBtn = 2;
const int downBtn = 3;
volatile int count = 0;
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  oled.clearDisplay();
  oled.fillRect(10, 16, 108, 32, WHITE);
  pinMode(upBtn, INPUT);
  pinMode(downBtn, INPUT);
  attachInterrupt(digitalPinToInterrupt(upBtn), upInterrupt, RISING);
  attachInterrupt(digitalPinToInterrupt(downBtn), downInterrupt, RISING);

  oled.setTextColor(BLACK, WHITE);
  oled.setTextSize(2);

  oled.setCursor(26, 24);
  oled.print("Welcome");
  oled.display();
  delay(1000);

  //----------
  oled.clearDisplay();
  oled.setCursor(16, 8);
  oled.setTextColor(WHITE);
  oled.print("COUNTING");
  oled.fillRect(10, 30, 108, 32, WHITE);
  oled.setTextColor(BLACK, WHITE);
  oled.setCursor(26, 24);
  oled.display();
}

void loop() {
  // put your main code here, to run repeatedly:
  display(count);
}
void display(int num){
  oled.fillRect(46 , 38, 36, 16,WHITE);
  String length = String(count);
  int chars = length.length();
  int xPosi = 10 + ((108-12*chars)/2);
  int yPosi = 30 + ((32-16)/2);
  oled.setCursor(xPosi, yPosi);
  oled.print(count);
  oled.display();
}
void upInterrupt() {
  if(count == 999){
    count = 0;
  } else{
    count+= 1;
  }
}
void downInterrupt() {
  if(count==0){
    count =  999;
  } else{
    count -= 1;
  }
}
#include <SoftwareSerial.h>;
SoftwareSerial BT(2, 3); 

void setup() {
  Serial.begin(9600);
  BT.begin(9600); 
}

void loop() {
  if (BT.available() > 0) {
    char dienthoai = BT.read();
    Serial.print(dienthoai);
  };

  if(Serial.available()>0){
    char maytinh = Serial.read();
    BT.print(maytinh)
  }
}
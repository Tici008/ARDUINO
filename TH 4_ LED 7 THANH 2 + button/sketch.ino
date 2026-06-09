const int pin[8] = { 4, 5, 6, 7, 8, 9, 10, 11};
const int code7seg[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90 };
const int upBtn = 2;
const int downBtn = 3;
const int ledHangChuc = 12;
const int ledHangDonVi = 13;
volatile int count = 0;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 8; i++) {
    pinMode(pin[i], OUTPUT);
    digitalWrite(pin[i], HIGH);
  };
  pinMode(upBtn, INPUT);
  pinMode(downBtn, INPUT);
  pinMode(ledHangChuc, OUTPUT);
  pinMode(ledHangDonVi, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(upBtn), upProcess, RISING);
  attachInterrupt(digitalPinToInterrupt(downBtn), downProcess, RISING);


}

void loop() {
  // put your main code here, to run repeatedly:
  quetLed(count);



}

void display(int num) {
  byte bitSet;
  for (int i = 0; i < 8; i++) {
    //11000000
    bitSet = bitRead(code7seg[num], i);
    digitalWrite(pin[i], bitSet);
  };
}
void quetLed (int count) {
  int hangChuc = count / 10;
  int hangDonVi = count % 10;

  digitalWrite(ledHangChuc, LOW);
  digitalWrite(ledHangDonVi, LOW);
  //-------
  display(hangChuc);
  digitalWrite(ledHangChuc, HIGH);
  delay(5);

  //-----
  digitalWrite(ledHangChuc, LOW);
  digitalWrite(ledHangDonVi, LOW);
  //----
  display(hangDonVi);
  digitalWrite(ledHangDonVi, HIGH);
  delay(5);
}
void upProcess() {
  if (count == 99) {
    count = 0;
  } else {
    count += 1;
  }
}
void downProcess() {
  if (count == 0) {
    count = 99;
  } else {
    count -= 1;
  }
}


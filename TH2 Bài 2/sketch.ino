int LED_PINS[8] = {1,2,3,4,5,6,7,8};
void setup() {
  // put your setup code here, to run once:
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 8; i++){
    digitalWrite(LED_PINS[i], HIGH);
    delay(200);
  }
  for (int i = 0; i < 8; i++){
    digitalWrite(LED_PINS[i], LOW);
    delay(200);
  }
}

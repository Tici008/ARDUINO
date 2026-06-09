int LED_PINS[] = {1,2,3,4,5,6,7,8};
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
  int l = 0;
  int r = 7;
  while (r != 3){
    digitalWrite(LED_PINS[l], HIGH);
    digitalWrite(LED_PINS[r], HIGH);
    delay (200);
    l += 1;
    r -= 1;
  };
  delay(1000);
  while (l < 8 ){
    digitalWrite(LED_PINS[l], LOW);
    digitalWrite(LED_PINS[r], LOW);
    delay(200);
    l+= 1;
    r-= 1;
  }
  
}

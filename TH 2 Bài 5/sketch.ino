int LED_PINS[] = {1,2,3,4,5,6,7,8};
int nums = 1;
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
  for (int i = 0; i<nums; i++ ){
    digitalWrite(LED_PINS[i], HIGH);
  };
  delay(200);
  if (nums < 8 ){
    int k = nums;
    while (k != 8){
      digitalWrite(LED_PINS[k], HIGH);
      digitalWrite(LED_PINS[k-nums], LOW);
      delay(200);
      k+= 1;
    };
    for (int i = 7; i> k - nums - 1; i-- ){
      digitalWrite(LED_PINS[i], LOW);
    };
    nums += 1;
  } else{
      for (int i = 0; i<8; i++ ){
        digitalWrite(LED_PINS[i], LOW);
        delay(100);
      };

  }
  
  
}

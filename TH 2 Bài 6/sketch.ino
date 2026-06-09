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
  if (nums < 9 ){
    digitalWrite(LED_PINS[0], HIGH);
    delay(1000);
    int k = 0;
    while (k != 8 - nums){
      digitalWrite(LED_PINS[k+1], HIGH);
      digitalWrite(LED_PINS[k], LOW);
      delay(1000);
      k+= 1;
    };
    
    nums += 1;
    k = 0;
  } else{
      for (int i = 0; i<8; i++ ){
        digitalWrite(LED_PINS[i], LOW);
        delay(100);
      };

  }
  
  
}

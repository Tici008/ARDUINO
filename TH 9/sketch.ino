
const int ledPin = 18; 

void setup() {
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600); 
  
  Serial.println("He thong da san sang! Nhap '1' de BAT, '0' de TAT.");
}

void loop() {
  if (Serial.available() > 0) {
    
    char incomingChar = Serial.read();
    
    if (incomingChar == '1') {
      digitalWrite(ledPin, HIGH);  
      Serial.println("Da BAT den LED!");
    } 
    else if (incomingChar == '0') {
      digitalWrite(ledPin, LOW);  
      Serial.println("Da TAT den LED!");
    }
  }
}
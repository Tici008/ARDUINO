int LED_PINS[] = {1, 2, 3, 4, 5, 6, 7, 8};
bool flag = false;
const int btn = 9;
bool lastState = LOW;


unsigned long lastTime = 0;
int ledIndex = 0;
int stepLED1 = 0;

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }
  pinMode(btn, INPUT);
}

void loop() {
  bool currentState = digitalRead(btn);

  if (currentState == HIGH && lastState == LOW) {
    flag = !flag;
    delay(50); // debounce
    for (int i = 0; i < 8; i++) {
      digitalWrite(LED_PINS[i], LOW);
    }
    ledIndex = 0;
    stepLED1 = 0;
  }
  lastState = currentState;

  if (!flag) {
    LED1_NonBlocking();
  } else {
    LED2_NonBlocking();
  }
}

void LED2_NonBlocking() {
  if (millis() - lastTime >= 200) {
    lastTime = millis(); 

    if (ledIndex < 8) {
      digitalWrite(LED_PINS[ledIndex], HIGH);
      ledIndex++;
    }
    else if (ledIndex >= 8 && ledIndex < 16) {
      digitalWrite(LED_PINS[ledIndex - 8], LOW);
      ledIndex++;
    }
    else {
      ledIndex = 0;
    }
  }
}

void LED1_NonBlocking() {
  if (stepLED1 < 4) {
    if (millis() - lastTime >= 200) {
      lastTime = millis();
      digitalWrite(LED_PINS[stepLED1], HIGH);
      digitalWrite(LED_PINS[7 - stepLED1], HIGH);
      stepLED1++;
    }
  }
  else if (stepLED1 == 4) {
    if (millis() - lastTime >= 1000) {
      lastTime = millis();
      stepLED1++; 
    }
  }
  else if (stepLED1 >= 5 && stepLED1 < 9) {
    if (millis() - lastTime >= 200) {
      lastTime = millis();
      int i = 8 - stepLED1;
      digitalWrite(LED_PINS[i], LOW);
      digitalWrite(LED_PINS[7 - i], LOW);
      stepLED1++;
    }
  }
  else {
    stepLED1 = 0;
  }
}
int button = 10;  
int buttonState = 0;

void setup() {
  Serial.begin(9600);  
  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(button, INPUT_PULLUP); 
}

void loop() {
  if (Serial.available() > 0) {
    int command = Serial.parseInt();  

    if (command >= 1 && command <= 5) {
      switch (command) {
        case 1:
          step1();
          break;
        case 2:
          step2();
          break;
        case 3:
          step3();
          break;
        case 4:
          step4();
          break;
        case 5:
          step5();
          break;
        default:
          break;
      }
    }
  }
}

void step1() {
  for (int i = 2; i <= 9; i++) {
    digitalWrite(i, HIGH);
  }
}

void step2() {
  for (int i = 2; i <= 9; i++) {
    if (i % 2 == 1) {
      digitalWrite(i, HIGH);
    } else {
      digitalWrite(i, LOW);
    }
  }
}

void step3() {
    for (int i = 3; i <= 9; i += 2) {
      digitalWrite(i, HIGH);
    }
    delay(500);

    for (int i = 2; i <= 9; i++) {
      digitalWrite(i, LOW);
    }
  for (int i = 2; i <= 9; i += 2) {
      digitalWrite(i, HIGH);
    }
    delay(500);

    for (int i = 2; i <= 9; i++) {
      digitalWrite(i, LOW);
    }

}


void left() {
  for (int i = 2; i <= 9; i++) {
    digitalWrite(i, HIGH);
    delay(500);
    digitalWrite(i, LOW);
  }
}

void right() {
  for (int i = 9; i >= 2; i--) {
    digitalWrite(i, HIGH);
    delay(500);
    digitalWrite(i, LOW);
  }
}

void step4() {
  left();
  right();
}


void step5() {
  buttonState = digitalRead(button);  

  if (buttonState == HIGH) {  
    left();
    right();
    
  } else {
    for (int i = 2; i <= 9; i++) {
      digitalWrite(i, LOW);
    }
  }
}

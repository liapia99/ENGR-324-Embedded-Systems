// Pin assignments for motors
const int enA = 5;
const int in1 = 2;
const int in2 = 3;
const int enB = 6;
const int in3 = 7;
const int in4 = 8;

// Pin assignments for channels
const int ch1Pin = A0; // Throttle (Speed)
const int ch2Pin = A1; // Left/Right Strength
const int ch3Pin = A2; // Direction (Forward/Backward) and Emergency Brake
const int ch4Pin = A3; // Left/Right Movement

int pwm;
int pA;
int pB;

int speed;
int direction = 0;
int turn = 0;

 // Set motor speeds based on direction, speed, and turn
int m1Speed = (speed + turn) * direction; // Motor 1 speed
int m2Speed = (speed - turn) * direction; // Motor 2 speed

void setup() {
  Serial.begin(9600);

  // Set motor pins as output
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  // Read PWM values from channels
  int ch1Value = pulseIn(ch1Pin, HIGH, 25000); // Throttle (Speed)
  int ch2Value = pulseIn(ch2Pin, HIGH, 25000); // Left/Right Strength
  int ch3Value = pulseIn(ch3Pin, HIGH, 25000); // Direction (Forward/Backward) and Emergency Brake
  int ch4Value = pulseIn(ch4Pin, HIGH, 25000); // Left/Right Movement


  // Calculate throttle control
  
  if (ch1Value <= 988) {
    speed = 0; // Stop if ch1Value is 988 or lower
  } else {
    // Gradual speed increase
    speed = map(ch1Value, 988, 2012, 50, 255); 
    speed = constrain(speed, 50, 255); 
  }

  // Determine direction based on ch3Value
  
  if (ch3Value < 1400) {
    direction = 1; // Forward if ch3Value is less than 1400
  } else if (ch3Value > 1700) {
    direction = -1; // Backward if ch3Value is greater than 1700
  }

  // Emergency brake logic based on ch3 value
  if (ch3Value >= 1400 && ch3Value <= 1700) {
    mpower(1, 0); // Stop motor 1
    mpower(2, 0); // Stop motor 2
    delay(20); 
    return; 
  }

  // Calculate turning based on ch2Value and ch4Value only if the car is moving
  
  if (speed != 0) {
    if (ch4Value < 1490 && ch4Value >= 988) {
      // Turn left
      speed = 50;
      turn = map(ch2Value, 988, 2012, 0, 255); // Tilting left
    } else if (ch4Value > 1520 && ch4Value <= 2012) {
      // Turn right
      speed = 50;
      turn = map(ch2Value, 988, 2012, 0, 255); // Tilting right
    } else {
      // No turn
      turn = 0;
    }
  }

 
  mpower(1, m1Speed);
  mpower(2, m2Speed);

  delay(20); 
}

void mpower(int motor, int spd) {
  int rotation = 0;
  if (spd > 0) {
    rotation = 1; // Forward
  } else if (spd < 0) {
    rotation = -1; // Backward
    spd = -spd; 
  } else {
    rotation = 0; // Stop
  }
  if (spd > 255) {
    spd = 255; // Limit max speed
  }



  if (motor == 1) {
    pwm = enA;
    pA = in1;
    pB = in2;
  } else if (motor == 2) {
    pwm = enB;
    pA = in3;
    pB = in4;
  } else {
    return; // Invalid motor number
  }

  analogWrite(pwm, spd); // Set PWM speed

  if (rotation == 1) {
    digitalWrite(pA, HIGH); // Motor forward
    digitalWrite(pB, LOW);
  } else if (rotation == -1) {
    digitalWrite(pA, LOW); // Motor backward
    digitalWrite(pB, HIGH);
  } else {
    digitalWrite(pA, LOW); // Stop motor
    digitalWrite(pB, LOW);
  }
}

// Pin assignments for motors
const int enA = 5;
const int in1 = 2;
const int in2 = 3;
const int enB = 6;
const int in3 = 7;
const int in4 = 8;

// Pin assignments for channels
const int ch1Pin = A0; // Throttle (Speed)
const int ch2Pin = A1; // Left/Right Movement
const int ch3Pin = A2; // Direction (Forward/Backward)


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
  int ch2Value = pulseIn(ch2Pin, HIGH, 25000); // Left/Right Movement
  int ch3Value = pulseIn(ch3Pin, HIGH, 25000); // Direction (Forward/Backward)



  // Emergency brake logic based on ch3 value
  if (ch3Value >= 1400 && ch3Value <= 1700) {
    mpower(1, 0); // Stop motor 1
    mpower(2, 0); // Stop motor 2
    delay(20); // Small delay for stability
    return; // Exit loop early
  }
 // Calculate throttle control
  int speed;
  if (ch1Value <= 988) {
    speed = 0; // Stop if ch1Value is 988 or lower
  } else {
    // Gradual speed increase
    speed = map(ch1Value, 988, 2012, 50, 255); // Throttle range: 988 to 2012 -> 50 to 255
    speed = constrain(speed, 50, 255); // Limit speed to valid range
  }

  // Determine direction based on ch3Value
  int direction = 0;
  if (ch3Value < 1400) {
    direction = -1; // Forward if ch3Value is less than 1400
  } else if (ch3Value > 1700) {
    direction = 1; // Backward if ch3Value is greater than 1700
  }

  // Calculate left/right movement only if the car is moving (speed != 0)
  int turn = 0;
  if (speed != 0) {
    if (ch2Value < 1490 && ch2Value >= 988) {
      // Slightly turn left
      turn = map(ch2Value, 988, 1490, -50, 0); // Tilting left
    } else if (ch2Value < 988) {
      // Spin left
      turn = map(ch2Value, 0, 988, -255, -50); // Spinning left
    } else if (ch2Value > 1520 && ch2Value <= 2012) {
      // Slightly turn right
      turn = map(ch2Value, 1520, 2012, 0, 50); // Tilting right
    } else if (ch2Value > 2012) {
      // Spin right
      turn = map(ch2Value, 2012, 4095, 50, 255); // Spinning right
    }
  }

  // Set motor speeds based on direction, speed, and turn
  int m1Speed = speed + turn; // Motor 1 speed
  int m2Speed = speed - turn; // Motor 2 speed

  mpower(1, m1Speed);
  mpower(2, m2Speed);

  delay(20); // Small delay for stability
}

void mpower(int motor, int spd) {
  int rotation = 0;
  if (spd > 0) {
    rotation = 1; // Forward
  } else if (spd < 0) {
    rotation = -1; // Backward
    spd = -spd; // Make speed positive for PWM
  } else {
    rotation = 0; // Stop
  }
  if (spd > 255) {
    spd = 255; // Limit maximum speed
  }

  int pwm;
  int pA;
  int pB;

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
    digitalWrite(pA, HIGH); // Motor backwards
    digitalWrite(pB, LOW);
  } else if (rotation == -1) {
    digitalWrite(pA, LOW); // Motor forwards
    digitalWrite(pB, HIGH);
  } else {
    digitalWrite(pA, LOW); // Stop motor
    digitalWrite(pB, LOW);
  }
}

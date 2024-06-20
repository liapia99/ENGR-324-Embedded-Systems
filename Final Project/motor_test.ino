// Pin assignments for motors
const int enA = 5;
const int in1 = 2;
const int in2 = 3;
const int enB = 6;
const int in3 = 7;
const int in4 = 8;

// Pin assignments for channels
const int ch1Pin = A0; // Speed
const int ch2Pin = A1; // Direction (right/left)
const int ch3Pin = A2; // Forward/Backward
const int ch4Pin = A3; // Emergency Brake

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
  int ch1Value = pulseIn(ch1Pin, HIGH, 25000); // Speed
  int ch2Value = pulseIn(ch2Pin, HIGH, 25000); // Direction (right/left)
  int ch3Value = pulseIn(ch3Pin, HIGH, 25000); // Forward/Backward
  int ch4Value = pulseIn(ch4Pin, HIGH, 25000); // Emergency Brake

  // Debugging: Print channel values
  Serial.print("Ch1: ");
  Serial.print(ch1Value);
  Serial.print(" | Ch2: ");
  Serial.print(ch2Value);
  Serial.print(" | Ch3: ");
  Serial.print(ch3Value);
  Serial.print(" | Ch4: ");
  Serial.println(ch4Value);

  // Emergency brake logic
  if (ch4Value > 1500) {
    // Stop all motors
    mpower(1, 0);
    mpower(2, 0);
    return; // Exit the loop early
  }

  // Throttle control
  int speed = (ch1Value > 1000) ? map(ch1Value, 1000, 2000, 0, 255) : 0;

  // Forward/Backward control
  int direction = 0;
  if (ch3Value > 1520) {
    direction = 1; // Forward
  } else if (ch3Value < 1490) {
    direction = -1; // Backward
  }

  // Turning control
  int turn = 0;
  if (ch2Value < 1490) {
    turn = map(ch2Value, 1000, 1490, -255, 0); // Turning left
  } else if (ch2Value > 1520) {
    turn = map(ch2Value, 1520, 2000, 0, 255); // Turning right
  }

  int m1Speed = constrain(speed * direction + turn, -255, 255);
  int m2Speed = constrain(speed * direction - turn, -255, 255);

  Serial.print("m1Speed: ");
  Serial.print(m1Speed);
  Serial.print(" | m2Speed: ");
  Serial.println(m2Speed);

  mpower(1, m1Speed);
  mpower(2, m2Speed);
}

void mpower(int motor, int spd) {
  int rotation = 0;
  if (spd > 0) {
    rotation = 1;
  } else if (spd < 0) {
    rotation = -1;
    spd *= -1;
  }
  if (spd > 255) {
    spd = 255;
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
    return;
  }

  if (rotation == 0) {
    digitalWrite(pA, LOW);
    digitalWrite(pB, LOW);
  } else if (rotation == 1) {
    digitalWrite(pA, HIGH);
    digitalWrite(pB, LOW);
  } else if (rotation == -1) {
    digitalWrite(pA, LOW);
    digitalWrite(pB, HIGH);
  }
  analogWrite(pwm, spd);
}

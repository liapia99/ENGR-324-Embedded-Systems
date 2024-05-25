const int ledPin = 6; 

void setup() {
  Serial.begin(9600); 
  pinMode(ledPin, OUTPUT); 
}

void loop() {
  int brightnessValue;
  int pwmValue;
 
  Serial.println("Please enter the brightness value for the LED (0-100): ");
  while (Serial.available() == 0) {
  }
  brightnessValue = Serial.parseInt();

  if (brightnessValue < 0) {
    brightnessValue = 0;
  } else if (brightnessValue > 100) {
    brightnessValue = 100;
  }

  pwmValue = map(brightnessValue, 0, 100, 0, 255);
  analogWrite(ledPin, pwmValue);

  Serial.print("LED brightness value: ");
  Serial.println(brightnessValue);
  Serial.print("LED PWM value: ");
  Serial.println(pwmValue);

  delay(1000);
}

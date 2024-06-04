const int left = 9; 
const int right = 10; 
const int front = 11; 
const int back = 6; 
const int stop = 5; 


void setup() {
  Serial.begin(9600); 
  pinMode(left, OUTPUT); 
  pinMode(right, OUTPUT); 
  pinMode(front, OUTPUT); 
  pinMode(back, OUTPUT); 
  pinMode(stop, OUTPUT); 
}

void loop() {
  digitalWrite(left, LOW);
  digitalWrite(right, HIGH);
  digitalWrite(front, HIGH);
  digitalWrite(back, HIGH);
  digitalWrite(stop, HIGH);
  //int brightnessValue;
  //int pwmValue;
 
  //Serial.println("Please enter the brightness value for the LED (0-100): ");
  //while (Serial.available() == 0) {
  //}
  //brightnessValue = Serial.parseInt();

  //if (brightnessValue < 0) {
  //  brightnessValue = 0;
  //} else if (brightnessValue > 100) {
  //  brightnessValue = 100;
  //}

  //pwmValue = map(brightnessValue, 0, 100, 0, 255);
  //analogWrite(ledPin, pwmValue);

  //Serial.print("LED brightness value: ");
  //Serial.println(brightnessValue);
 // Serial.print("LED PWM value: ");
 // Serial.println(pwmValue);

  //delay(1000);
}

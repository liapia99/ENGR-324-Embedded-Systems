
const int analogInputPin = A0; 
const int thresholdVoltage = 100; 

const int ledPin1 = 13; 

void setup() {
  pinMode(analogInputPin, INPUT);
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  
}

void loop() {
  int voltage = analogRead(analogInputPin);
  Serial.println(voltage); 
  
  
  if (voltage > thresholdVoltage) { 
    digitalWrite(ledPin1, HIGH); 
  } else {
    digitalWrite(ledPin1, LOW);
  }
}

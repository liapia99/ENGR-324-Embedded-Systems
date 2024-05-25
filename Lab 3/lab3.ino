const int analog = A0; 
int sensorValue = 0;      
float voltage = 0;       

void setup() {
  Serial.begin(9600); 
  pinMode(analog, INPUT); 
}

void loop() {
  sensorValue = analogRead(analog);
  
  voltage = sensorValue * (5.0 / 1023.0);
  
  Serial.print("ADC: ");
  Serial.println(sensorValue);
  Serial.print("Actual analog measured voltage: ");
  Serial.print(voltage);

  while (true) {}
}

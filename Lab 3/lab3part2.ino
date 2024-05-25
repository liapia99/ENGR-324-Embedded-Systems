const int potPin = A0;  
const int ledPin = 11;   
int poten_Value = 0;       
int duty_Cycle = 0;      
int percentage = 0;     

void setup() {
  Serial.begin(9600);     
  pinMode(potPin, INPUT); 
  pinMode(ledPin, OUTPUT);
}

void loop() {

  poten_Value = analogRead(potPin);
  
  duty_Cycle = map(poten_Value, 0, 1023, 0, 255);
  
  percentage = map(duty_Cycle, 0, 255, 0, 100);
  
  Serial.print("The Potentiometer ADC value is ");
  Serial.println(poten_Value);
  Serial.print("The Potentiometer duty cycle value is ");
  Serial.println(duty_Cycle);
  Serial.print("The Potentiometer duty cycle percentage is ");
  Serial.print(percentage);
  Serial.println(" %");
  
  analogWrite(ledPin, duty_Cycle);
  
  delay(1000);
}

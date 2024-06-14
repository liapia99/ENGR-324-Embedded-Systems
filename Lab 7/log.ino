int pot = A0;

void setup() {
  Serial.begin(9600);
  Serial.println("CLEARDATA");
  Serial.println("LABEL,Time,Started Time,Date,Analog Value,POT%");
  Serial.println("RESETTIMER");
}

void loop() {
  int pot_val = analogRead(pot);
  int pot_percentage = map(pot_val, 0, 1023, 0, 100);
  unsigned long currentMillis = millis(); // Time since Arduino started

  unsigned long seconds = currentMillis / 1000;
  unsigned long minutes = seconds / 60;
  unsigned long hours = minutes / 60;
  
  String currentTime = String(hours) + ":" + String(minutes % 60) + ":" + String(seconds % 60);
  String startedTime = "0:0:0"; 
  String currentDate = "YYYY-MM-DD"; 
  
  // Print data to Serial
  Serial.print("DATA,");
  Serial.print(currentTime);
  Serial.print(",");
  Serial.print(startedTime);
  Serial.print(",");
  Serial.print(currentDate);
  Serial.print(",");
  Serial.print(pot_val);
  Serial.print(",");
  Serial.println(pot_percentage);
  
  // Delay for 1.5 seconds
  delay(1500);
}

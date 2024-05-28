void setup() {
  Serial.begin(9600);
}

void loop() {
  for (float t = -2 * PI; t <= 2 * PI; t += 0.01) {
    Serial.print("line1:");
    Serial.print(2 * cos((3 * t) - (PI / 3)));
    Serial.print("\t");

    Serial.print("line2:");
    if (t == 0) {
      Serial.println(1);
    } else {
      Serial.println(sin(t * PI) / t);
    }
    delay(10); 
  }
  while (true) {
  }
}

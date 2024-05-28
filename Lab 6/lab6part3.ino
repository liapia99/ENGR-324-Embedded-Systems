void setup() {
  DDRD = 0xFF; 
}

void loop() {
  
  uint8_t segmentValues[] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x67, // 9
    0x77, // A
    0x7C, // b
    0x39, // C
    0x5E, // d
    0x79, // E
    0x71  // F
  };

  for (int i = 0; i < 16; i++) {
    PORTD = segmentValues[i]; 
    delay(500); 
  }
}

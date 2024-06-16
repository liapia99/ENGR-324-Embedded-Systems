#include <IRremote.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int IR_TRANSMIT_PIN = 3;
const int BUTTON_ON = 2;
const int BUTTON_VOLU = 4;
const int BUTTON_VOLD = 5;
const int BUTTON_MUT = 6;
//const int BUTTON_INP = A0;

IRsend irsend;
LiquidCrystal_I2C lcd(0x27, 16, 2);

//const int thresholdVoltage = 20;      

void setup() {
  //inMode(BUTTON_INP, INPUT);
  Serial.begin(9600);
  pinMode(BUTTON_ON, INPUT_PULLUP);
  pinMode(BUTTON_VOLU, INPUT_PULLUP);
  pinMode(BUTTON_VOLD, INPUT_PULLUP);
  pinMode(BUTTON_MUT, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();
  irsend.begin(IR_TRANSMIT_PIN); // Corrected initialization
}

void loop() {
  //int voltage = analogRead(BUTTON_INP);
//
  //if (voltage < thresholdVoltage) { 
    //unsigned long sCode = 0xE0E040BF; // Example Samsung code for input
    //rial.print("Transmitting Samsung code: 0x");
    //Serial.println(sCode, HEX);
    //lcd.clear();
    //lcd.print("Input Change");
    //sendSamsungCode(sCode);
    //delay(5000);
 // }
 
  if (digitalRead(BUTTON_ON) == LOW) {
    unsigned long sCode = 0xFFFFFFFF; // Samsung code for Power
    Serial.print("Transmitting Samsung code: 0x");
    Serial.println(sCode, HEX);
    lcd.clear();
    lcd.print("Power");
    sendSamsungCode(sCode);
    delay(5000); // wait for 0.5 seconds before sending the next code
  }
    
  if (digitalRead(BUTTON_VOLU) == LOW) {
    unsigned long sCode = 0xE9E70E8C; // Samsung code for Volume Up
    Serial.print("Transmitting Samsung code: 0x");
    Serial.println(sCode, HEX);
    lcd.clear();
    lcd.print("Volume Up");
    sendSamsungCode(sCode);
    delay(5000); // wait for 0.5 seconds before sending the next code
  }
    
  if (digitalRead(BUTTON_VOLD) == LOW) {
    unsigned long sCode = 0xE9E70E8C; // Samsung code for Volume Down
    Serial.print("Transmitting Samsung code: 0x");
    Serial.println(sCode, HEX);
    lcd.clear();
    lcd.print("Volume Down");
    sendSamsungCode(sCode);
    delay(5000); // wait for 0.5 seconds before sending the next code
  }
    
  if (digitalRead(BUTTON_MUT) == LOW) {
    unsigned long sCode = 0xE9E70E8C; // Samsung code for Mute
    Serial.print("Transmitting Samsung code: 0x");
    Serial.println(sCode, HEX);
    lcd.clear();
    lcd.print("Mute");
    sendSamsungCode(sCode);
    delay(5000); // wait for 0.5 seconds before sending the next code
  }

  // Modify and add other codes as necessary.
}

void sendSamsungCode(unsigned long code) {
  for (int i = 0; i < 3; i++) {
    irsend.sendNEC(code, 32); // send the code using the NEC protocol with 32 bits
    delay(4000); // delay between each transmission
  }
}

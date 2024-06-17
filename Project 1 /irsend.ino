#include <IRremote.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int IR_TRANSMIT_PIN = 3;
const int BUTTON_ON = 2;
const int BUTTON_VOLU = 4;
const int BUTTON_VOLD = 5;
const int BUTTON_MUT = 6;
const int BUTTON_INP = 7;

IRsend irsend;
LiquidCrystal_I2C lcd(0x27, 16, 2);    

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_INP, INPUT_PULLUP);
  pinMode(BUTTON_ON, INPUT_PULLUP);
  pinMode(BUTTON_VOLU, INPUT_PULLUP);
  pinMode(BUTTON_VOLD, INPUT_PULLUP);
  pinMode(BUTTON_MUT, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();
  irsend.begin(IR_TRANSMIT_PIN); 
}

void loop() {

  if (digitalRead(BUTTON_INP) == LOW) { 
    unsigned long sCode = 0x20DFD02F; 
    Serial.print("Transmitting LG code: 0x");
    Serial.println(sCode, HEX);
    lcd.clear();
    lcd.print("Input");
    sendLGCode(sCode);
    delay(5000);
  }
 
  if (digitalRead(BUTTON_ON) == LOW) {
    unsigned long sCode = 0x20DF10EF; 
     Serial.print("Transmitting LG code: 0x");
    Serial.println(sCode, HEX);
    lcd.clear();
    lcd.print("Power");
    sendLGCode(sCode);
    delay(5000);
  }
    
  if (digitalRead(BUTTON_VOLU) == LOW) {
    unsigned long sCode = 0x20DF40BF; 
    Serial.print("Transmitting LG code: 0x");
    Serial.println(sCode, HEX);
    lcd.clear();
    lcd.print("Volume Up");
    sendLGCode(sCode);
    delay(5000);
  }
    
  if (digitalRead(BUTTON_VOLD) == LOW) {
    unsigned long sCode = 0x20DFC03F; 
    Serial.print("Transmitting LG code: 0x");
    Serial.println(sCode, HEX);
    lcd.clear();
    lcd.print("Volume Down");
    sendLGCode(sCode);
    delay(5000);
  }
    
  if (digitalRead(BUTTON_MUT) == LOW) {
    unsigned long sCode = 0x20DF906F; 
    Serial.print("Transmitting LG code: 0x");
    Serial.println(sCode, HEX);
    lcd.clear();
    lcd.print("Mute");
    sendLGCode(sCode);
    delay(5000); 
  }

}

void sendLGCode(unsigned long code) {
  for (int i = 0; i < 3; i++) {
    irsend.sendNEC(code, 32); 
    delay(40); 
  }
}

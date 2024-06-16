#include <IRremote.h>

const int IR_RECEIVE_PIN = 2;

IRrecv irrecv(IR_RECEIVE_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print("Received SONY code: 0x");
    Serial.println(results.value, HEX);

    // Print raw timing data
    Serial.println("Raw timing data:");
    for (int i = 0; i < results.rawlen; i++) {
      Serial.print(results.rawbuf[i] * USECPERTICK);
      Serial.print(" ");
    }
    Serial.println();

    irrecv.resume();
  }
}

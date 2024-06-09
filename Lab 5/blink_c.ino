#define MS_DELAY 3000

void setup() {
    // Set digital pin 13 to output mode
    DDRB |= _BV(DDB5);
}

void loop() {
    // Set digital pin 13 to HIGH
    PORTB |= _BV(PORTB5);
    // Wait for 3000 ms
    delay(MS_DELAY);
    // Set digital pin 13 to LOW
    PORTB &= ~_BV(PORTB5);
    // Wait for 3000 ms
    delay(MS_DELAY);
}

//https://www.instructables.com/Arduino-and-Port-Manipulation/
//https://extremeelectronics.co.in/avr-tutorials/programming-in-c-tips-for-embedded-development/

void setup() {
// red led pin 13
DDRB = DDRB | 0b00100000; // 4 bytes
PORTB = PORTB & 0b00000000; // 2 bytes
// green led  pin 5
DDRD = DDRD | 0b00100000; // 4 bytes
PORTD = PORTD & 0b00000000; // 2 bytes
// yellow led  pin A5
DDRC = DDRC | 0b00100000; // 4 bytes
PORTC = PORTC & 0b00000000; // 2 bytes
} 
void loop() {
// red led on others off
PORTB = PORTB | 0b00100000; // set bit with bitwise OR
PORTD = PORTD & 0b11011111; // clear bit with bitwise AND
PORTC = PORTC & 0b11011111;
delay(500);
// yellow led on others off
PORTB = PORTB & 0b11011111;
PORTD = PORTD & 0b11011111;
PORTC = PORTC | 0b00100000; // 2 bytes
delay(500);
// green led on others off
PORTD = PORTD | 0b00100000;
PORTB = PORTB & 0b11011111;
PORTC = PORTC & 0b11011111;
delay(500); // 170 bytes
// 8 bytes
} 

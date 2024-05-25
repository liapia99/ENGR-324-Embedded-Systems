void setup() {
// red led 
DDRB = DDRB | 0b00100000; // 4 bytes
PORTB = PORTB & 0b00000000; // 2 bytes
// green led  
DDRD = DDRD | 0b00100000; // 4 bytes
PORTD = PORTD & 0b00000000; // 2 bytes
// yellow led  
DDRC = DDRC | 0b00100000; // 4 bytes
PORTC = PORTC & 0b00000000; // 2 bytes
} 
void loop() {
// all three on
PORTB = PORTB | 0b00100000;
PORTC = PORTC | 0b00100000;
PORTD = PORTD | 0b00100000; 

delay(500);
// all three off
PORTB = PORTB & 0b11011111;
PORTD = PORTD & 0b11011111;
PORTC = PORTC & 0b11011111;
delay(500); 

} 

void setup() {

DDRD = 0xFF;  

} 
void loop() {
PORTD = 0x3F; //Displaying 0
delay (1000);
PORTD = 0x6; //Displaying 1
delay (1000);
PORTD = 0x5B; //Displaying 2
delay (1000);
PORTD = 0x4F; //Displaying 3
delay (1000);
PORTD = 0x66; //Displaying 4
delay (1000);
PORTD = 0x6D; //Displaying 5
delay (1000);
PORTD = 0x7D; //Displaying 6
delay (1000);
PORTD = 0x7; //Displaying 7
delay (1000);
PORTD = 0x7F; //Displaying 8
delay (1000);
PORTD = 0x67; //Displaying 9
delay (1000);
}

//dp g f e d c b a
//00000110 1

//01011011 2

//01001111 3

//01100110 4

//01101101 5

//01111101 6

//00000111 7

//01111111 8

//01100111 9



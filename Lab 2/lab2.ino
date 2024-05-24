#include <LiquidCrystal_I2C.h>
#include <Ultrasonic.h>

#define echoPin 2
#define trigPin 3

long duration;
float distance_cm;
float distance_in;

LiquidCrystal_I2C lcd(0x27, 16, 2); 

Ultrasonic ultrasonic(trigPin, echoPin); 

void setup() { 
lcd.init(); 
lcd.clear();
lcd.setCursor (0,0);
lcd.backlight(); 

pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);
 
}

void loop() {

digitalWrite(trigPin, LOW);
delay(50);
digitalWrite(trigPin, HIGH);
delay(50);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);

distance_cm = duration * 0.0344 / 2;
distance_in = distance_cm / 2.54;

lcd.clear(); 
lcd.setCursor(0, 0); // Set cursor to first box 
        
lcd.print("Distance:"); 

lcd.setCursor(10,0); // Set cursor for print below
lcd.print(distance_cm); // print cm output value 

lcd.setCursor(13, 0); // move cursor 
lcd.print("cm"); // print "cm" 

lcd.setCursor(10, 1);
lcd.print(distance_in); 
lcd.setCursor(13, 1); 
lcd.print("in"); 

delay(100);

}

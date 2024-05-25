#include <Ultrasonic.h>

#define trigPin 7
#define echoPin 6
#define soundbuzzer 3

long duration;
int distance_cm;


Ultrasonic ultrasonic(trigPin, echoPin); 

const int ledPin1 = 11; 
const int ledPin2 = 10; 
const int ledPin3 = 9; 

void setup() { 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(soundbuzzer, OUTPUT);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance_cm = duration * 0.0344 / 2;

  if (distance_cm <= 5) { 
    digitalWrite(ledPin1, LOW); 
    digitalWrite(ledPin2, LOW); 
    digitalWrite(ledPin3, HIGH); 
    tone(soundbuzzer, 50);
    delay(500);

  } else if (distance_cm >= 6 && distance_cm <= 20) {
    digitalWrite(ledPin1, LOW); 
    digitalWrite(ledPin2, HIGH); 
    digitalWrite(ledPin3, LOW); 
    noTone(soundbuzzer);
  
  } else {
    digitalWrite(ledPin1, HIGH); 
    digitalWrite(ledPin2, LOW); 
    digitalWrite(ledPin3, LOW); 
    noTone(soundbuzzer);
    
  }
}

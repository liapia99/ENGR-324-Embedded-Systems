#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 

// Variables
volatile unsigned long startTime = 0;
volatile unsigned long elapsedTime = 0;
volatile unsigned int revolutions = 0;
int wheelCircumference = 3; 

void setup() {
    attachInterrupt(digitalPinToInterrupt(2), wheelInterrupt, RISING); 
    revolutions = 0;
    startTime = millis();

    lcd.init(); 
    lcd.backlight(); 
    lcd.setCursor(0,0); 
    lcd.print("ENGR-324 PROJECT");
    lcd.setCursor(2, 1); 
    lcd.print("SPEEDOMETER");
    delay(1000);

    Serial.begin(9600); 
    Serial.println("CLEARDATA"); 
    Serial.println("LABEL,Date,Time,Start Time,Elapsed Time,Speed (km/h),Speed (MPH),RPM"); // Define column headers in Excel file
}

// Interrupt Service Routine 
void wheelInterrupt() {
    if ((millis() - startTime) > 10) { 
        elapsedTime = millis() - startTime;
        startTime = millis();
        revolutions++;
    }
}

void loop() {
    float elapsedTimeSec = elapsedTime / 1000.0; 
    float rpm = (revolutions / elapsedTimeSec) * 60.0; 
    float speedKmh = (wheelCircumference * revolutions / elapsedTimeSec) * 3.6; 
    float speedMph = speedKmh * 0.621371192; 

    
    lcd.setCursor(0, 0); 
    lcd.print("Speed: ");
    lcd.print(speedKmh);
    lcd.print(" km/h");
    lcd.setCursor(0, 1); 
    lcd.print("RPM: ");
    lcd.print(rpm);

    // Send data to PLX-DAX
    Serial.print("DATA,DATE,TIME,");
    Serial.print(startTime); // Start time
    Serial.print(",");
    Serial.print(elapsedTimeSec); // Elapsed time
    Serial.print(",");
    Serial.print(speedKmh); // Speed in km/h
    Serial.print(",");
    Serial.print(speedMph); // Speed in MPH
    Serial.print(",");
    Serial.println(rpm); // RPM

    // Reset revolutions for next measurement
    revolutions = 0;
    delay(1000); 
}

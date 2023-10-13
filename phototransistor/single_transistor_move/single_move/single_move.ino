#include <Servo.h>
Servo servoLeft;
Servo servoRight;
void setup() {
    // Play a tone to show program is starting
    tone(4, 3000, 1000);
    delay(1000);

    // Servos moved to 10 & 11 for more accurate results
    // Try using 12 & 13 as well to see what happens
    servoLeft.attach(11);
    servoRight.attach(10);

    // Full speed forward for 3 seconds
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1300); 
}

void loop() {
  float stoppingVoltage = 3.5;
  if(volts(A3) > stoppingVoltage){
   servoLeft.detach();
    servoRight.detach();
    }  
}
float volts (int adPin){
  return float (analogRead(adPin)) *5 /1024.0;
}
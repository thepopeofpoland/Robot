#include <Arduino.h>
#include <Servo.h>

Servo servoLeft;

void setup() {
    servoLeft.attach(11);
    servoLeft.writeMicroseconds(1500);
}

void loop() {
    // put your main code here, to run repeatedly:
}
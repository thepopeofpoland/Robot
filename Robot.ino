#include <Arduino.h>
#include <servo.h>
Servo leftServo;
Servo rightServo;
void setup() {
    leftServo.attach(11);
    rightServo.attach(10);
    leftServo.writeMicroseconds(1500);
    rightServo.writeMicroseconds(1500);
}

void loop() {}
#include <Servo.h>
Servo servoLeft;
Servo servoRight;
void setup() {
    // Set the whisker pins to input
    pinMode(7, INPUT);
    pinMode(5, INPUT);

    // Adds LED option
    pinMode(8, OUTPUT);
    pinMode(2, OUTPUT);

    // Play a tone to show program is starting
    tone(4, 3000, 1000);
    delay(1000);

    // Attach the servos ( verify your pin number !)
    servoLeft.attach(11);
    servoRight.attach(10);
}
void loop() {
    // Save each whisker ’s value
    byte whiskerLeft = digitalRead(5);
    byte whiskerRight = digitalRead(7);

    // Navigate and turn
    if (whiskerLeft == 0 && whiskerRight == 0) {
        backward(1000);
        turnLeft(800);  // Turn about 120 degrees
        digitalWrite(2, HIGH);
        digitalWrite(8, HIGH);

    } else if (whiskerLeft == 0) {
        backward(1000);
        turnRight(400);  // Turn about 60 degrees
        digitalWrite(8, HIGH);

    } else if (whiskerRight == 0) {
        backward(1000);
        turnLeft(400);  // Turn about 60 degrees
        digitalWrite(2, HIGH);

    } else {
        forward(20);
        digitalWrite(8, LOW);
        digitalWrite(2, LOW);
    }
}

void forward(int time) {
    // These numbers may be different for you to go straight
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1300);
    delay(time);
}
void turnLeft(int time) {
    servoLeft.writeMicroseconds(1300);
    servoRight.writeMicroseconds(1300);
    delay(time);
}
void turnRight(int time) {
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1700);
    delay(time);
}
void backward(int time) {
    servoLeft.writeMicroseconds(1300);
    servoRight.writeMicroseconds(1700);
    delay(time);
}
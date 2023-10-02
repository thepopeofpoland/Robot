# Notes for Robotics work

## 9-11
- Got the setup working with the Arduino IDE software. couldn't get VSCode to work due to no Arduino IDE support.
```Arduino
void setup() {
  Serial.begin(9600);
  Serial.print("Hello?");
}

void loop() {
  // put your main code here, to run repeatedly:

}
```
## 9-13
### Activity 2
- got the loop code running.
```Arduino
void setup() {
    Serial.begin(9600);
    Serial.print("Hello?\n");
    Serial.print("whats a matter you?");
}

void loop() {
    Serial.print("Hello?\n");
    delay(1000);
}
```
Incorporated println() into program.
```Arduino
void loop() {
    Serial.println("Hello?\n");
    delay(1000);
}
```
### Activity 3
- Added the storage of variables and the printing of the stored variables.

```Arduino
    int a = 42;
    char c = 'm';
    float root2 = sqrt(2.0);

    Serial.println(a);
    Serial.println(c);
    Serial.println(root2);s
```
### Activity 4
- Worked on math operators in Arduino
```Arduino
  int a = 89;
  int b = 42;
  int c = a + b;

  Serial.println(a);
  Serial.println(b);
  Serial.println("a + b = ");
  Serial.println(c);
```

### Lab 1.2
- built up the arduino and shield together and assembled the led setup. 
Look at LED.ino in the LED folder to see the code used to light the lights. 
- Q1. the breadboard is a set of interconnected holes that allows you to place a wire or other component into 1 of 5 holes that are all interconnected to share power or pass power along without needing more wires
- Q2. Without ```pinMode(xx,OUTPUT)``` you get super faint output from the LED
- Q3. When you pass HIGH and LOW into the function it changes the output from sending higher power to sending lower power. HIGH has enough power to overcome the resistor and LOW does not.

### lab 2
- Got the BOE built the way it is supposed to be.
- the two servos are centered.
- When i mess with the values in the writeMicroseconds() function if its greater than the 1500 that i centered on it rotates counter-clockwise. if the value is lower it rotates clockwise.
```arduino
#include <Servo.h>
  Servo leftServo;
  Servo rightServo;
void setup() {
  leftServo.attach(11);
  rightServo.attach(10);
  leftServo.writeMicroseconds(1500);
  rightServo.writeMicroseconds(1500);
}

void loop() {}
```
# 10-02

## lab 3
- Got the speaker to make a police siren using the code in speaker.ino.
- retested the wheels with the provided code from the lab PDF and it didn't go in a straight line. It spun slightly to the left.
```arduino
#include<Servo.h>
Servo servoLeft;
Servo servoRight;
void setup () {
// Play a tone to show program is starting
tone(4, 3000, 1000);
delay(1000);
// Servos moved to 10 & 11 for more accurate results
// Try using 12 & 13 as well to see what happens
servoLeft.attach (11);
servoRight.attach (10);
// Full speed forward for 3 seconds
servoLeft.writeMicroseconds (1700);
servoRight.writeMicroseconds (1300);
delay(3000);
servoLeft.detach ();
servoRight.detach ();
}
void loop () {
}
```
- Servo issue has been discovered. I am using two different kinds of servos. I feel dumb. Servo has been swapped out so they now match and are centered on 1500.
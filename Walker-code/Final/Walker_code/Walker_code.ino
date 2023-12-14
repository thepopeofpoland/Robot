#include <Servo.h>

Servo FRtop;     // pin 10
Servo FRbottom;  // pin 12
Servo FLtop;     // pin 11
Servo FLbottom;  // pin 13

Servo BRtop;     // pin 6
Servo BRbottom;  // pin 4
Servo BLtop;     // pin 7
Servo BLbottom;  // pin 5

int FRtopcenter = 67;
int FRbottomcenter = 10;
int FLtopcenter = 115;
int FLbottomcenter = 140;

// back legs
int BRtopcenter = 42;
int BRbottomcenter = 10;
int BLtopcenter = 100;
int BLbottomcenter = 123;

void setup() {
    // put your setup code here, to run once:
    FRtop.attach(10);
    FLtop.attach(11);
    FLbottom.attach(13);
    FRbottom.attach(12);
    BRtop.attach(6);
    BLtop.attach(7);
    BLbottom.attach(5);
    BRbottom.attach(4);

    FRtop.write(FRtopcenter);
    FRbottom.write(FRbottomcenter);
    FLtop.write(FLtopcenter);
    FLbottom.write(FLbottomcenter);
    BRtop.write(BRtopcenter);
    BRbottom.write(BRbottomcenter);
    BLtop.write(BLtopcenter);
    BLbottom.write(BLbottomcenter);
    delay(5000);
}

void loop() {
    // put your main code here, to run repeatedly:
    long tLeft = rcTime(9);
    long tRight = rcTime(8);
    maneuver(tLeft, tRight);
}

void maneuver(long tLeft, long tRight) {
    walk();
    if (tRight > 2000) {
        turnLeft();
        delay(250);
        turnLeft();
    }
    if (tLeft > 2000) {
        turnRight();
        delay(250);
        turnRight();
    }
}

void turnLeft() {
    FRbottom.write(50);
    delay(500);
    FRtop.write(82);
    delay(500);
    FRbottom.write(0);
    delay(500);
    BRbottom.write(50);
    delay(500);
    BRtop.write(57);
    delay(500);
    BRbottom.write(0);
    delay(500);
    FRtop.write(FRtopcenter);
    FRbottom.write(FRbottomcenter);
    BRtop.write(BRtopcenter);
    BRbottom.write(BRbottomcenter);
}
void turnRight() {
    FLbottom.write(100);
    delay(500);
    FLtop.write(100);
    delay(500);
    FLbottom.write(180);
    delay(500);
    BLbottom.write(83);
    delay(500);
    BLtop.write(85);
    delay(500);
    BLbottom.write(180);
    delay(500);
    FLtop.write(FLtopcenter);
    FLbottom.write(FLbottomcenter);
    BLtop.write(BLtopcenter);
    BLbottom.write(BLbottomcenter);
}
void walk() {
    FRBLsteps();
    delay(500);
    FLBRsteps();
    delay(500);
}
long rcTime(int pin) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
    delay(1);
    pinMode(pin, LOW);
    long time = micros();
    while (digitalRead(pin))
        ;
    time = micros() - time;
    return time;
}
void FRBLsteps() {
    FRbottom.write(50);
    BLbottom.write(83);
    delay(500);
    FRtop.write(82);
    BLtop.write(85);
    delay(500);
    FRbottom.write(0);
    BLbottom.write(180);
    delay(500);
    FRtop.write(FRtopcenter);
    FRbottom.write(FRbottomcenter);
    BLtop.write(BLtopcenter);
    BLbottom.write(BLbottomcenter);
}
void FLBRsteps() {
    FLbottom.write(100);
    BRbottom.write(50);
    delay(500);
    FLtop.write(100);
    BRtop.write(57);
    delay(500);
    FLbottom.write(180);
    BRbottom.write(0);
    delay(500);
    FLtop.write(FLtopcenter);
    FLbottom.write(FLbottomcenter);
    BRtop.write(BRtopcenter);
    BRbottom.write(BRbottomcenter);
}
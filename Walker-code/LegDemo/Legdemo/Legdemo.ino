#include <Servo.h>
Servo turretServo;

Servo FRtop;
Servo FRbottom;
Servo FLtop;
Servo FLbottom;

Servo BRtop;
Servo BRbottom;
Servo BLtop;
Servo BLbottom;

// Servo left > 90 goes backwards
// Servo right < 90 goes backwards

int sequence[] = {45, 63, 81, 99, 117, 135, 117, 99, 81, 63};
int i = 0;
//front legs
int FRtopcenter = 60;
int FRbottomcenter = 30;
int FLtopcenter = 120;
int FLbottomcenter = 125;

//back legs
int BRtopcenter = 60;
int BRbottomcenter = 30;
int BLtopcenter = 105;
int BLbottomcenter = 125;

void setup() {
    // turretServo.attach(12);
    FRtop.attach(10);
    FLtop.attach(11);
    // FLbottom.attach(8); need to finish wiring properly for the bottom servos
    // FRbottom.attach(6);
    BRtop.attach(6);
    BLtop.attach(8);
    // BLbottom.attach(8);
    // BRbottom.attach(6);

    BRtop.write(BRtopcenter);
    BRbottom.write(BRbottomcenter);
    BLtop.write(BLtopcenter);
    BLbottom.write(BLbottomcenter);
    delay(5000);

    }
// Servo left > 90 goes backwards
// Servo right < 90 goes backwards
void loop() {
  maneuver();
  // turretServo.write(sequence[i]);
}

long ping(int pin) {
    // Set the pin to output
    pinMode(pin, OUTPUT);
    // Stay LOW for 2 us
    digitalWrite(pin, LOW);
    delayMicroseconds(2);
    // Send a 5 us HIGH pulse
    digitalWrite(pin, HIGH);
    delayMicroseconds(5);
    digitalWrite(pin, LOW);
    // Set the pin to input and measure echo time pulse from PING
    pinMode(pin, INPUT);
    long duration = pulseIn(pin, HIGH, 25000);
    return duration;
}
int convert(long duration) {
    int conversion = 29;
    return duration / conversion / 2;
}
 void maneuver() {
    long num = ping(13);
     walk();
    if (convert(num) < 50) {
        turn();
    }
 }

void walk() {
    FRstep();
    BLstep();
    delay(500);
    FLstep();
    BRstep();
}

void FRstep(){
  FRbottom.write(45);
  delay(500);
  FRtop.write(96);
  delay(500);
  FRbottom.write(0);
  delay(500);
  FRtop.write(FRtopcenter);
  FRbottom.write(FRbottomcenter);
}

void BRstep(){
    BRbottom.write(45);
    delay(500);
    BRtop.write(96);
    delay(500);
    BRbottom.write(0);
    delay(500);
    BRtop.write(BRtopcenter);
    BRbottom.write(BRbottomcenter);
}

void FLstep(){
  FLbottom.write(110);
  delay(500);
  FLtop.write(96);
  delay(500);
  FLbottom.write(180);
  delay(500);
  FLtop.write(FLtopcenter);
  FLbottom.write(FLbottomcenter);
}

void BLstep(){
    BLbottom.write(110);
    delay(500);
    BLtop.write(72);
    delay(500);
    BLbottom.write(180);
    delay(500);
    BLtop.write(BLtopcenter);
    BLbottom.write(BLbottomcenter);
}

void turn() {
    FRstep();
    BRstep();
    delay(250);
}
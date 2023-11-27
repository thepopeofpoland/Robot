#include <Servo.h>
Servo turretServo;
Servo servoFR;  // front right
Servo servoBR;  // back right
Servo servoFL;  // front left
Servo servoBL;  // back left

// Servo left > 90 goes backwards
// Servo right < 90 goes backwards

int sequence[] = {45, 63, 81, 99, 117, 135, 117, 99, 81, 63};
int i = 0;
int FRcenter = 84;
int BRcenter = 86;
int FLcenter = 89;
int BLcenter = 87;

int FRforward = 96;
int FLforward = 74;
int BRforward = 104;
int BLforward = 72;

void setup() {
    // turretServo.attach(12);
    servoFR.attach(10);
    servoFL.attach(11);
    servoBL.attach(8);
    servoBR.attach(6);

    servoFR.write(FRcenter);
    servoFL.write(FLcenter);
    servoBR.write(BRcenter);
    servoBL.write(BLcenter);
    delay(5000);
}
// Servo left > 90 goes backwards
// Servo right < 90 goes backwards
void loop() {
  servoFL.write(FLforward);
  delay(1000);
  servoFR.write(FRforward);
  delay(1000);
  servoBL.write(BLforward);
  delay(1000);
  servoBR.write(BRforward);
  delay(1000);

  servoBR.write(BRcenter);
  servoBL.write(BLcenter);
  servoFR.write(FRcenter);
  servoFL.write(FLcenter);
  delay(5000);

  // walk();
    // maneuver();
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
    // servoFL.write(FLforward);
    // servoBL.write(BLforward);
    // servoFR.write(FRcenter);
    // servoBR.write(BRcenter);
    // delay(2000);
    servoFL.write(FLforward);
    servoBR.write(BRforward);
    servoFR.write(FRcenter);
    servoBL.write(BLcenter);
    delay(2000);

    servoFL.write(FLcenter);
    servoBR.write(BRcenter);
    servoBL.write(BLforward);
    servoFR.write(FRforward);
    delay(2000);
}

void turn() {
    servoFL.write(FLforward);
    servoBL.write(BLforward);
    delay(2000);
    servoFL.write(FLcenter);
    servoBL.write(BLcenter);
    delay(2000);
}
#include<Servo.h>
Servo turretServo;
Servo servoFR_BL; // front right and back left
Servo servoFL_BR; // front left and back right
int turretAngle = 180;
//Servo left > 90 goes backwards
//Servo right < 90 goes backwards

int sequence[] = {45, 63, 81, 99, 117, 135, 117, 99, 81, 63};
int i = 0;

void setup() {
    turretServo.attach(12);
    servoFR_BL.attach(10);
    servoFL_BR.attach(11);
    turretServo.write(0);
    servoFR_BL.write(90);
    servoFL_BR.write(95);
}
//Servo left > 90 goes backwards
//Servo right < 90 goes backwards
void loop() {
    long num = ping(13);
    turretServo.write(sequence[i]);
    maneuver();
    if(convert(num)<50){
      turn();
    }
    ++i;
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
void maneuver(){
    servoFR_BL.write(105);
    delay(2000);
    servoFL_BR.write(80);
    delay(2000);
    servoFR_BL.write(90);
    delay(2000);
    servoFL_BR.write(95);
    delay(2000);
    servoFR_BL.write(75);
    delay(2000);
    servoFL_BR.write(110);
    delay(2000);
}
void turn(){

}
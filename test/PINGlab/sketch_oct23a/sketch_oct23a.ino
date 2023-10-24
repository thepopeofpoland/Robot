#include <Servo.h>
Servo turretServo;
int turretAngle = 0;
void setup() {
    Serial.begin(9600);
    turretServo.attach(12);
    turretServo.write(turretAngle);
    
}
void loop() {
    long num = ping(13);  // PING is in pin 13
    turretServo.write(turretAngle);
    Serial.println(convert(num));
    delay(500);
    turretAngle +=45;
    
    
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
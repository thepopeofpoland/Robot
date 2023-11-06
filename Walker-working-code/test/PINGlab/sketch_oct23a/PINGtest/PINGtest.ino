
#include <Servo.h>
Servo turretServo;
Servo servoRight;
Servo servoLeft;
int turretAngle = 0;

int sequence[] = {45, 63, 81, 99, 117, 135};
int i = 0;
void setup() {
    Serial.begin(9600);
    turretServo.attach(12);
    servoRight.attach(10);
    servoLeft.attach(11);
    turretServo.write(turretAngle);
}
void loop() {
    long num = ping(13);  // PING is in pin 13
    maneuver(200,200);
    turretServo.write(sequence[i]);
    Serial.println(convert(num));
    if(convert(num) < 50){
      maneuver(200, -200); // turns the bot to the right.
      Serial.println("too close to item.");
    }
    delay(500);
    if (i == 5) {
        i = 0;
    } else {
        ++i;
    }
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
void maneuver(int speedLeft, int speedRight)
{
  // Call maneuver with just 1 ms blocking; servos will keep going indefinitely.
  maneuver(speedLeft, speedRight, 1);              
}
void maneuver(int speedLeft, int speedRight, int msTime)
{
  servoLeft.writeMicroseconds(1500 + speedLeft);   // Set Left servo speed
  servoRight.writeMicroseconds(1500 - speedRight); // Set right servo speed
  if(msTime==-1)                                   // if msTime = -1
  {                                  
    servoLeft.detach();                            // Stop servo signals
    servoRight.detach();   
  }
  delay(msTime);                                   // Delay for msTime
}
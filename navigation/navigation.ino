#include <Servo.h>
Servo servoLeft;
Servo servoRight;
Servo servoTurret;

int ccwLim = 1520;
int rtAngle = 900;

void setup() {
    // Play a tone to show program is starting
    tone(4, 3000, 1000);
    delay(1000);

    // Servos moved to 10 & 11 for more accurate results
    // Try using 12 & 13 as well to see what happens
    servoLeft.attach(11);
    servoRight.attach(10);
    servoTurret.attach(12);

    // Full speed forward for 3 seconds
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1300);
    turret(170);

    delay(3000);

    servoLeft.detach();
    servoRight.detach();
}

void loop() {}
void turret(int degreeVal)
{
  int usPulseTime = ccwLim - rtAngle + (degreeVal * 10);
  servoTurret.writeMicroseconds(usPulseTime);
  //Serial.println(usPulseTime, DEC);
}
void setup() {
    // Play a tone to show program is starting
    tone(4, 3000, 1000);
    delay(1000);

    pinMode(7, INPUT);
    pinMode(5, INPUT);

    pinMode(8, OUTPUT);
    pinMode(2, OUTPUT);

    Serial.begin(9600);
}
void loop() {
    byte whiskerLeft = digitalRead(5);
    byte whiskerRight = digitalRead(7);

    Serial.print(whiskerLeft);
    Serial.println(whiskerRight);

    if (whiskerLeft == 0) {
        digitalWrite(8, HIGH);
    } else {
        digitalWrite(8, LOW);
    }
    if (whiskerRight == 0) {
        digitalWrite(2, HIGH);
    } else {
        digitalWrite(2, LOW);
    }

    delay(50);
}

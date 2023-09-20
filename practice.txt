void setup() {
    Serial.begin(9600);
    Serial.print("Hello?\n");
    Serial.println("whats a matter you?");
    int a = 89;
    int b = 42;
    int c = a + b;

    Serial.println(a);
    Serial.println(b);
    Serial.println("a + b = ");
    Serial.println(c);
}

void loop() {
    // no code
}
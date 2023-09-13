# Notes for Robotics work

## 9-11
Got the setup working with the Arduino IDE software. couldn't get VSCode to work due to no Arduino IDE support.
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
got the loop code running.
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
Added the storage of variables and the printing of the stored variables.

```Arduino
    int a = 42;
    char c = 'm';
    float root2 = sqrt(2.0);

    Serial.println(a);
    Serial.println(c);
    Serial.println(root2);s
```
### Activity 4
Worked on math operators in Arduino
```Arduino
  int a = 89;
  int b = 42;
  int c = a + b;

  Serial.println(a);
  Serial.println(b);
  Serial.println("a + b = ");
  Serial.println(c);
```

### Activity 5

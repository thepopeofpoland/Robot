void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("A3 = ");
  Serial.print(volts(A3));
  Serial.println(" volts");
  delay(1000);
}
float volts(int adPin){
  return float (analogRead(adPin)) *5.0 / 1024.0;
}
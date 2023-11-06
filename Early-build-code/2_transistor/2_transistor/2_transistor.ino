void setup() {
  // put your setup code here, to run once:
  tone(4,3000,1000);
  delay (1000);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  long decayTime = getDecayTime(6);

  Serial.print("time = ");
  Serial.print(decayTime);
  Serial.println((" us"));

  delay(1000);
}

long getDecayTime(int pin){
  //charge the capacitor
  pinMode(pin,OUTPUT);
  digitalWrite(pin, HIGH);
  delay(1);

  //read from pin and wait for the voltage to drop
  pinMode(pin, INPUT);
  digitalWrite(pin,LOW);
  long time= micros();
  while(digitalRead(pin));
  time = micros() - time;
  return time;
}

//LEDの点滅
//writer:tonegawa
int led1 = 6;
void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT)
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led1, HIGH);
  delay(500);
  disitalWrite(led1, LOW);
  delay(500);
}

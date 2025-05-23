int ledPin = 5;
int buttonApin = 8;
int buttonBpin = 9;

byte leds = 0;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);  
  pinMode(buttonBpin, INPUT_PULLUP);  
  Serial.begin(9600);
}

void loop() 
{
  if (digitalRead(buttonApin) == LOW && digitalRead(buttonBpin) == LOW)//どちらも押されている
  {
    Serial.print("(1,1)");
    digitalWrite(ledPin, HIGH);
  }
  if (digitalRead(buttonApin) == HIGH && digitalRead(buttonBpin) == HIGH)//どちらも押されていない
  {
    Serial.print("(0,0)");
    digitalWrite(ledPin, LOW);
  }
  if (digitalRead(buttonApin) == LOW && digitalRead(buttonBpin) == HIGH)//Aが押されていて、Bが押されていない
  {
    Serial.print("(1,0)");
    digitalWrite(ledPin, HIGH);
  }
  if (digitalRead(buttonApin) == HIGH && digitalRead(buttonBpin) == LOW)//Aが押されていなくて、Bが押されている
  {
    Serial.print("(0,1)");
    digitalWrite(ledPin, LOW);
  }
  Serial.print("\n");
  delay(100);
}
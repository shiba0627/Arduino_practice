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
  }
  if (digitalRead(buttonApin) == HIGH && digitalRead(buttonBpin) == HIGH)//どちらも押されていない
  {
    Serial.print("(0,0)");
  }
  if (digitalRead(buttonApin) == LOW && digitalRead(buttonBpin) == HIGH)//Aが押されていて、Bが押されていない
  {
    Serial.print("(1,0)");
  }
  if (digitalRead(buttonApin) == HIGH && digitalRead(buttonBpin) == LOW)//Aが押されていなくて、Bが押されている
  {
    Serial.print("(0,1)");
  }
  Serial.print("\n");
  delay(100);
}
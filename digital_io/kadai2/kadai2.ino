int ledPin = 5;
int buttonApin = 8;
int buttonBpin = 9;

const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output

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
  Serial.print("(");
  Serial.print(analogRead(X_pin));
  Serial.print(",");
  Serial.print(analogRead(Y_pin));
  Serial.print(",");
  if (digitalRead(buttonApin) == LOW && digitalRead(buttonBpin) == LOW)//どちらも押されている
  {
    
    Serial.print("1,1)\n");
    digitalWrite(ledPin, HIGH);
  }
  if (digitalRead(buttonApin) == HIGH && digitalRead(buttonBpin) == HIGH)//どちらも押されていない
  {
    Serial.print("0,0)\n");
    digitalWrite(ledPin, LOW);
  }
  if (digitalRead(buttonApin) == LOW && digitalRead(buttonBpin) == HIGH)//Aが押されていて、Bが押されていない
  {
    Serial.print("1,0)\n");
    digitalWrite(ledPin, HIGH);
  }
  if (digitalRead(buttonApin) == HIGH && digitalRead(buttonBpin) == LOW)//Aが押されていなくて、Bが押されている
  {
    Serial.print("0,1)\n");
    digitalWrite(ledPin, LOW);
  }
  delay(100);
}
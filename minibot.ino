/* 
LED VERSION
GRW WRG wir beim tvr tuscan
linkslenkung steuert das linke rad, rechtslenkung das rechte
*/
// vars
int linkslenkung = 9;  // ist da drauf wegen pwm
int rechtslenkung = 10;
int hintenrechts = 11;
int hintenlinks = 3;
int weiss = 8;
int gelblinks = 5;
int gelbrechts = 6;
int rot = 7;
int echo = 2;
int trigger = 4;
long entfernung;
long zeit;

void setup() {
  randomSeed(analogRead(0));
  pinMode(linkslenkung, OUTPUT);
  pinMode(rechtslenkung, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
}

void loop() {
  // random var
  int randomnum = random(2);

  // echo
  digitalWrite(trigger, LOW);
  delay(5);
  digitalWrite(trigger, HIGH);
  delay(10);
  digitalWrite(trigger, LOW);
  zeit = pulseIn(echo, HIGH);
  float entfernung = 0.03432 * zeit / 2;

  // if statement
  if (entfernung < 25) {
    if (randomnum == 1) {
      // bremslicht an
      digitalWrite(rot, HIGH);

      // weisses licht an
      digitalWrite(weiss, HIGH);

      // hinten
      analogWrite(linkslenkung, 0);
      analogWrite(rechtslenkung, 0);
      analogWrite(hintenrechts, 255);
      analogWrite(hintenlinks, 225);
      delay(1500);
      analogWrite(hintenrechts, 0);
      analogWrite(hintenlinks, 0);

      // weisses licht aus
      digitalWrite(weiss, LOW);
      
      // bremslicht aus
      digitalWrite(rot, LOW);

      // blinker links
      digitalWrite(gelblinks, HIGH);
      delay(150);
      digitalWrite(gelblinks, LOW);
      delay(150);
      digitalWrite(gelblinks, HIGH);
      delay(150);
      digitalWrite(gelblinks, LOW);
      delay(150);
      digitalWrite(gelblinks, HIGH);
      delay(150);
      digitalWrite(gelblinks, LOW);

      // lenkung links
      analogWrite(rechtslenkung, 255);
      delay(125);
    } else {
      // bremslicht an
      digitalWrite(rot, HIGH);

      // weisses licht an
      digitalWrite(weiss, HIGH);

      // hinten
      analogWrite(linkslenkung, 0);
      analogWrite(rechtslenkung, 0);
      analogWrite(hintenrechts, 255);
      analogWrite(hintenlinks, 225);
      delay(3000);
      analogWrite(hintenrechts, 0);
      analogWrite(hintenlinks, 0);

      // weisses licht aus
      digitalWrite(weiss, LOW);
      
      // bremslicht aus
      digitalWrite(rot, LOW);

      // blinker links
      digitalWrite(gelbrechts, HIGH);
      delay(150);
      digitalWrite(gelbrechts, LOW);
      delay(150);
      digitalWrite(gelbrechts, HIGH);
      delay(150);
      digitalWrite(gelbrechts, LOW);
      delay(150);
      digitalWrite(gelbrechts, HIGH);
      delay(150);
      digitalWrite(gelbrechts, LOW);

      // lenkung rechts
      analogWrite(linkslenkung, 225);
      delay(125);
    }
  } else {
    analogWrite(linkslenkung, 225);   // links ist niedriger als
    analogWrite(rechtslenkung, 255);  // rechts weil der linke motor aus irgendeinem grund stärker ist
  }
}

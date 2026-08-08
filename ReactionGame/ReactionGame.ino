int buttonOld1 = 1;
int buttonOld2 = 1;
int buttonOld3 = 1;
int buttonNew1;
int buttonNew2;
int buttonNew3;
int buttonPin1 = 2;
int buttonPin2 = 3;
int buttonPin3 = 4;
int ledPin1 = 8;
int ledPin2 = 9;
int ledPin3 = 10;
bool ledOnG = false;
bool ledOnY = false;
bool ledOnR = false;

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  randomSeed(analogRead(0));
  Serial.begin(9600);
}

void loop() {
  buttonNew1 = digitalRead(buttonPin1);
  buttonNew2 = digitalRead(buttonPin2);
  buttonNew3 = digitalRead(buttonPin3);

  
  if (ledOnG == false && ledOnY == false && ledOnR == false) {
    int randomNumber = random(0, 3);
    switch (randomNumber)
    {
      case 0:
        digitalWrite(ledPin1, HIGH);
        ledOnG = true;
        break; 
      case 1:
        digitalWrite(ledPin2, HIGH);
        ledOnY = true;
        break; 
      case 2:
        digitalWrite(ledPin3, HIGH);
        ledOnR = true;
        break; 
  }

  
  if(ledOnG == true)
  {
    if(buttonNew1 == 0 && buttonOld1 == 1)
    {
      digitalWrite(ledPin1, LOW);
      ledOnG = false; 
      delay(100);
    }
  }
  else if(ledOnY == true)
  {
    if(buttonNew2 == 0 && buttonOld2 == 1)
    {
      digitalWrite(ledPin2, LOW);
      ledOnY = false;
      delay(100);
    }
  }
  else if(ledOnR == true)
  {
    if(buttonNew3 == 0 && buttonOld3 == 1)
    {
      digitalWrite(ledPin3, LOW);
      ledOnR = false;
      delay(100);
    }
  }

  
  buttonOld1 = buttonNew1;
  buttonOld2 = buttonNew2;
  buttonOld3 = buttonNew3;
}
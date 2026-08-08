int buttonPins[] = {2, 3, 4};
int buttonOld[] = {1, 1, 1};
int ledPins[] = {8, 9, 10};
bool anyledOn = false; 
float startgame;
float reactiontime;
int r;
void setup() 
{
  
  for(int i=0; i<3; i++) 
  {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  
  for(int i=0; i<3; i++) 
  {
    pinMode(ledPins[i], OUTPUT);
  }
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  
  if(anyledOn == false) 
  {
    r = random(0, 3);
    digitalWrite(ledPins[r], HIGH);
    anyledOn = true;
    startgame = millis();
  }

  
  for(int i=0; i<3; i++) 
  {
    int buttonNew = digitalRead(buttonPins[i]);
    if(anyledOn == true && buttonNew == 0 && buttonOld[i] == 1 && i == r) 
    {
      digitalWrite(ledPins[i], LOW);
      anyledOn = false; 
      delay(500);
      reactiontime = millis() - startgame;

    }
    buttonOld[i] = buttonNew; 
    Serial.println(reactiontime);

  }
}
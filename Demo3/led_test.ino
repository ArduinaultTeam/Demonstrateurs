#define LED_R1 2 //connect LED to digital pin2
#define LED_R2 4 //connect LED to digital pin4
#define LED_B 6 //connect LED to digital pin6
#define BUTTON 8 //connect LED to digital pin8

int state = 0;
int previousState = 0;
int ledStep = 0;

void setup() {
  // initialize the digital pin2 as an output.
  pinMode(LED_R1, OUTPUT);
  pinMode(LED_R2, OUTPUT);
  pinMode(LED_B, OUTPUT);
}

void loop() {
  state = digitalRead(BUTTON);
  if (state == 1 && previousState == 0)
    ledStep += 1;

  if (ledStep == 4)
    ledStep = 0;

  switch (ledStep)
  {
    case 0 : digitalWrite(LED_R1, HIGH);
      break;
    case 1 : digitalWrite(LED_R2, HIGH);
      break;
    case 2 : digitalWrite(LED_B, HIGH);
      break;
    case 3 :
      {
        digitalWrite(LED_R1, LOW);
        digitalWrite(LED_R2, LOW);
        digitalWrite(LED_B, LOW);
      }
      break;
  }
  /* Voici la version "compacte" (pour les bons)
    switch (ledStep){
    case 0 : digitalWrite(LED_R1, HIGH);
    case 1 : digitalWrite(LED_R2, HIGH);
    case 2 : digitalWrite(LED_B, HIGH);
    case 3 : digitalWrite(LED_R1, LOW);
      digitalWrite(LED_R2, LOW);
      digitalWrite(LED_B, LOW);
  }*/

  previousState = state;

}

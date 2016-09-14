int etatBouton = 0;
int pinBouton = 2;
int previousEtat = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  etatBouton = digitalRead(pinBouton);
  if (etatBouton != previousEtat)
  {
    if (etatBouton)
    {
      Serial.println("Il est vivant ! VIVAAAAAAAANT !!!!!!");
      digitalWrite(13,HIGH);
    }
    else
    {
      Serial.println("Il est decedu :'((((((( ");
      digitalWrite(13,LOW);
    }
  }
  previousEtat = etatBouton;
  delay(100);
}

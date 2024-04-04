
int echoPin = 5; //Pin responsible for reading the sound wave when they return from the obstacle.
int trigPin = 6; //Pin responsible for generating the sound wave.
int LED=13;
float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT); //OUTPUT because the trigPin emits the sound wave.
  pinMode(echoPin, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  distance = pulseIn(echoPin, HIGH);

//This condition makes the LED turn on when the distance from the obstacle is lower than 500.
//And turns off when the distance from the obstacle is higher than 500.
  
  if (distance < 500)
     digitalWrite(LED, HIGH);
  else
     digitalWrite(LED, LOW);

  Serial.println(duration);
  delay(500);
  

}

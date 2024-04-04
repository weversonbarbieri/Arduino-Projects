
int echoPin = 5; //pin responsible for reading the sound wave when they return from the obstacle.
int trigPin = 6; //pin responsible for generating the sound wave.
int LED=13;
float duration, ditance;

void setup() {
  pinMode(trigPin, OUTPUT); //OUTPUT because the trigPin emit the sound wave.
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

  duration = pulseIn(echoPin, HIGH);

  if (duration < 500)
     digitalWrite(LED, HIGH);
  else
     digitalWrite(LED, LOW);

  Serial.println(duration);
  delay(500);
  

}

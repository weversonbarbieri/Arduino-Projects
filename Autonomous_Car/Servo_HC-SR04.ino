#include <Servo.h>

Servo servo; //this control the servo, either the pin output or the funtion to control the servo.
int Servopos = 0;
int Epin = 5; //this pin reads the ultrasonic wave after returning from the obstacle.
int Tpin = 6; //this pin produces the ultrasonic wave output.
int distance; //the calculated distance will be attributed to this variable.



void setup() {
  servo.attach(3); //this is the arduino pin output to control the servo.
  pinMode(Tpin, OUTPUT); //this function produces the ultrasonic wave output.
  pinMode(Epin, INPUT); //this is the pin where the arduino reads the ultrasonic wave.
  Serial.begin(9600);
}

void loop() {

  digitalWrite(Tpin, LOW); //clean the previous ultrasonic pulse signal.
  delayMicroseconds(2);
  digitalWrite(Tpin, HIGH); //this function sends the ultrasonic pulse and lasts 10 Microseconds.
  delayMicroseconds(10); 
  digitalWrite(Tpin, LOW);

  distance = (pulseIn(Epin, HIGH) / 58); //the fuction pulseIn reads the pulse signal in microsends between LOW and HIGH. In order to have the distance of the obstable in CM, we divide the received signal pulse in μs / 58.  
  Serial.print("Distance in CM = ");
  Serial.println(distance); //print the distance in CM.
  delay(50);

  //This while function reads the distance and while there is an obstable more than 250 CMs, the servo keeps moving right and left to avoid the object hit any obstacle.
  //When the obstacle is less than 250 CMs, the servo stops moving indicating an obstacle was found. 
  while (distance > 250) {

    distance = (pulseIn(Epin, HIGH) / 58);
    Serial.print("Distance in CM = ");
    Serial.println(distance);
    delay(50);

    for (Servopos = 0; Servopos <= 180; Servopos++) { //This loop moves the shaft of the servo from 0 degree to 180 degrees. 
    servo.write(Servopos); //This function is used to generate the arduino output at pin #3 to move the servo according to the position given to the Servopos variable. 
    delay(8);
  }
  

  for (Servopos = 180; Servopos >= 0; Servopos--) { //This loop moves the shaft of the servo from 180 degrees to 0 degree.
    servo.write(Servopos); //This function is used to generate the arduino output at pin #3 to move the servo according to the position given to the Servopos variable.
   delay(8);
  }
  
  }

  
}

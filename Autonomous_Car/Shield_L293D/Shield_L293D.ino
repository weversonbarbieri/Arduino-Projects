#include <AFMotor.h> 

AF_DCMotor motor1 (1);
AF_DCMotor motorturn (3);
AF_DCMotor motor4 (4);

void setup() {
   motor1.setSpeed(255);
   motorturn.setSpeed(255);
   motor4.setSpeed(255);

}

void loop() {
   motor1.run(FORWARD);
   motor4.run(FORWARD);
   delay(2000);

   motor1.run(RELEASE);
   motor4.run(RELEASE);

   motorturn.run(FORWARD);
   delay(1000);

   motor1.run(BACKWARD);
   delay(1000);

   motor1.run(RELEASE);
   motorturn.run(RELEASE);
   
   motor1.run(FORWARD);
   motor4.run(FORWARD);
   delay(2000);

   motor1.run(RELEASE);
   motor4.run(RELEASE);

   motorturn.run(BACKWARD);
   delay(1000);

   motor1.run(BACKWARD);
   delay(1000);

   motor1.run(RELEASE);
   motorturn.run(RELEASE);

   motor1.run(FORWARD);
   motor4.run(FORWARD);
   delay(2000);




}

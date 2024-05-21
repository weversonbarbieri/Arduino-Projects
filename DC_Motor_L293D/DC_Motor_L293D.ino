int MotorPin1 = 1;
int MotorPin2 = 2;

void setup()
{
  pinMode(MotorPin1, OUTPUT);
  pinMode(MotorPin2, OUTPUT);
  
}

void loop(){
  
  digitalWrite(MotorPin1, HIGH);
  digitalWrite(MotorPin2, LOW);
  delay(5000);
  
  digitalWrite(MotorPin1, LOW);
  digitalWrite(MotorPin2, HIGH);
  delay(5000);
  
    
}
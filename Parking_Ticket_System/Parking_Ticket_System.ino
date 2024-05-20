#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(9, 10, 11, 12, 13, 14); //The display show the status of the ticket and the gate.

Servo servo_A;
int sensorv=2; //This button represents a sensor when the drive press the button to get the ticket.
int ledet=4; //After pressing the button, this led turns on.
int sensortr=3;//This 2nd button represents when the driver takes out the ticket.
int sensoropen=6;//This button represents a sensor to confirm the gate is opened, then the display shows its status as opened.
int sensorclose=8;//This button represents a sensor to confirm the gate is closed, then the display shows its status as closed.

void setup(){
  servo_A.attach(5);
  pinMode(sensorv, INPUT_PULLUP);
  pinMode(sensortr, INPUT_PULLUP);
  pinMode(sensoropen, INPUT_PULLUP);
  pinMode(sensorclose, INPUT_PULLUP);
  pinMode(ledet, OUTPUT);
  digitalWrite(ledet, LOW);
  servo_A.write(0);
  lcd.begin(16, 2);
    
}

void loop()
{
  
  
  while(digitalRead(sensorv)==1);
  digitalWrite(ledet, HIGH);
  lcd.setCursor(0,0);
  lcd.print("Remove Ticket");
  
  while(digitalRead(sensortr)==1);
  digitalWrite(ledet, LOW);
  servo_A.write(90);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Ticket Removed");
  
  while(digitalRead(sensoropen)==1);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Gate Opened");
    
    
  while(digitalRead(sensorclose)==1);
  servo_A.write(0);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Gate Closed");
  
   
  
  
}

int Swpin=11; //This pin reads the value 1 (pressed) or 0 (not pressed) from the joystick switch.
int Xpin=A1; //This pin reads the analog value from 0 to 1023 at the X value (from . When the joystick is in the middle, the value should be 512.
int Ypin=A2; //This pin reads the analog value from 0 to 1023 at the X value (from . When the joystick is in the middle, the value should be 512.
int Sval; //Variable to read the state of the switch at pin 2, if 1 or 0.
int Xval; //Variable to read the analog values from A1 pin.
int Yval; // Variable to read the analog values from A2 pin.
int LED=13;
int dt=500;


void setup() {
  Serial.begin(9600);
  pinMode(Swpin, INPUT);
  pinMode(Xpin, INPUT);
  pinMode(Ypin, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(Swpin, HIGH);
}

void loop() {
  Xval = analogRead(Xpin);
  Yval = analogRead(Ypin);
  Sval = digitalRead(Swpin);
  
  delay(dt);

  //This function prints the value read from the A1, A2 and pin #2 during the joystick operation.
  Serial.print("X value = ");
  Serial.println(Xval);
  Serial.print("Y value = ");
  Serial.println(Yval);
  Serial.print("Switch state value = ");
  Serial.println(Sval);
  Serial.println();

  //This function reads the joystick switch value and turn on or off the LED #13 at the Arduino board.
  if (Sval == 1) {
    digitalWrite(LED, LOW);
  }
  else {
    digitalWrite(LED, HIGH);
  }


  

}

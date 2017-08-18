//Created by Justin Nguyen

int toggleDoorFlag = 0;
int toggleDoor = 2;
int magLock = 3;
int heartbeat = 13;
int calcium = A2;
int threshold0 = 500;
int strobe = 7;
int lamp = 9;
boolean beat = true;
int calciumFlag = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(toggleDoor, INPUT);
  pinMode(magLock, OUTPUT);
  pinMode(heartbeat, OUTPUT);
  pinMode(calcium, INPUT);
  pinMode(strobe, OUTPUT);
  pinMode(lamp, OUTPUT);
  digitalWrite(magLock, HIGH);
  Serial.begin(9600);
}

void loop() {
  beat = !beat;
  digitalWrite(heartbeat, beat);

  //Door-to-Door
  toggleDoorFlag = digitalRead(toggleDoor);
  if (toggleDoorFlag) {
    digitalWrite(magLock, HIGH);
  }
  else{
    digitalWrite(magLock, LOW);
  }
 
  //Medicine Cabinet
  calciumFlag = analogRead(calcium);
  Serial.println(calciumFlag);
  if (calciumFlag >= threshold0) {
    digitalWrite(strobe, LOW);
    digitalWrite(lamp, LOW);
  }
  else{
    digitalWrite(strobe, HIGH);
    digitalWrite(lamp, HIGH);
  }
  
  delay(500);
}


int toggleDoorFlag = 0;
int toggleDoor = 2;
int magLock = 3;
int heartbeat = 13;
int calcium = 4;
int notCalcium0 = 5;
int notCalcium1 = 6;
int strobe = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(toggleDoor, INPUT);
  pinMode(magLock, OUTPUT);
  pinMode(heartbeat, OUTPUT);
  pinMode(calcium, INPUT);
  pinMode(notCalcium0, INPUT);
  pinMode(notCalcium1, INPUT);
  pinMode(strobe, OUTPUT);
}

void loop() {
  digitalWrite(magLock, HIGH);
  toggleDoorFlag = digitalRead(toggleDoor);
  if (toggleDoorFlag == HIGH) {
    digitalWrite(magLock, LOW);
  }

  digitalWrite(strobe, LOW);
  if (calcium && !notCalcium0 && !notCalcium1) {
    digitalWrite(strobe, HIGH);
  }
  else{
    digitalWrite(strobe, LOW);
  }
  
  delay(500);
}

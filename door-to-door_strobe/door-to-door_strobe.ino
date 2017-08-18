
int toggleDoorFlag = 0;
int toggleDoor = 2;
int magLock = 3;
int heartbeat = 13;
int calcium = A2;
//int notCalcium0 = A3;
//int notCalcium1 = A4;
int threshold0 = 300;
int threshold1 = 50;
int strobe = 7;
boolean beat = true;

int calciumFlag = 0;
//int fauxFlag0 = 0;
//int fauxFlag1 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(toggleDoor, INPUT);
  pinMode(magLock, OUTPUT);
  pinMode(heartbeat, OUTPUT);
  pinMode(calcium, INPUT);
  //pinMode(notCalcium0, INPUT);
  //pinMode(notCalcium1, INPUT);
  pinMode(strobe, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  beat = !beat;
  digitalWrite(heartbeat, beat);
  Serial.println(analogRead(calcium));
  
  //Door-to-Door
  digitalWrite(magLock, HIGH);
  toggleDoorFlag = digitalRead(toggleDoor);
  if (toggleDoorFlag == HIGH) {
    digitalWrite(magLock, LOW);
  }

  //Medicine Cabinet
  calciumFlag = analogRead(calcium);
  //fauxFlag0 = analogRead(notCalcium0);
  //fauxFlag1 = analogRead(notCalcium1);
  if (calciumFlag >= threshold0 /*&& !(fauxFlag0 >= threshold1) && !(fauxFlag1 >= threshold1)*/) {
    digitalWrite(strobe, LOW);
  }
  else{
    digitalWrite(strobe, HIGH);
  }
  
  delay(500);
}

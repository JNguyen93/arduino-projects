int reed0 = 3;
int reed1 = 4;
int reed2 = 5;
int reed3 = 6;
int reed4 = 7;
int reed5 = 8;
int reed6 = 9;
int LED = 13;
int maglock = 2;
bool flag0 = false;
bool flag1 = false;
bool flag2 = false;
bool flag3 = false;
bool flag4 = false;
bool flag5 = false;
bool flag6 = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(reed0, INPUT);
  pinMode(reed1, INPUT);
  pinMode(reed2, INPUT);
  pinMode(reed3, INPUT);
  pinMode(reed4, INPUT);
  pinMode(reed5, INPUT);
  pinMode(reed6, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  flag0 = digitalRead(reed0);
  flag1 = digitalRead(reed1);
  flag2 = digitalRead(reed2);
  flag3 = digitalRead(reed3);
  flag4 = digitalRead(reed4);
  //flag5 = digitalRead(reed5);
  //flag6 = digitalRead(reed6);
  if(flag0 && flag1 && flag2 && !flag3 && flag4){
    digitalWrite(maglock, LOW);
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(maglock, HIGH);
    digitalWrite(LED, LOW);
  }
  
  delay(500);
}

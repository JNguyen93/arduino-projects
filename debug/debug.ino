int test = A5;

void setup() {
  // put your setup code here, to run once:
  pinMode(test, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(digitalRead(test));
  boolean conn = digitalRead(test);
  if(!conn) {
    Serial.println("Connected");
  }
  delay(500);
}

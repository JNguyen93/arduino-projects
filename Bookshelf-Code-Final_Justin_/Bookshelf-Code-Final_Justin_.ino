/*So I messed with this code a lot trying to get it to work. Take a look and feel free to make changes, I tried
to make it clear what I was thinking but by the end of it I was super frustrated and gave up after a few hours
of just staring at it and trying different things. Feel free to text or call me, I just want this to be done.
Oh also, the mag lock itself is having some trouble, I don't know what's up with that but I didn't have time 
to look. The keypads should be configured, everything's in the suitcase.
*/
//const int laserPin1 = 12; 
//int sensorPin1 = A2; //Top bookshelf (throh)

const int laserPin2 = 4;
int sensorPin2 = A3; //Bottom bookshelf

int sensorPin3 = A4; //Top bookshelf, left side (einthoven)

int magLock = 9;
//const int threshold1 = 1; //So the two sensors need different thresholds due to the ammount of light each on gets.
const int threshold2 = 40;//The top one, sensorPin1, floated around 16-25 when the light was hitting it and it was
const int threshold3 = 100;
//int light1 = 7;           //around 0 with no light.
int light2 = 5;           //these light pins are for the led's that I used for troubleshooting, I powered the 
int light3 = 3;            //bookshelf LED's with the simple 5v and GND on the breadboard.

//int sensorVal1 = 0;
int sensorVal2 = 0;//I declared it out here to see if that was causing a problem, having it to declare it each loop
int sensorVal3 = 0;

//This is very basic, but it should do the trick.
//Remember to attach lots of resistors to the photoresistor,
//and mess around with the threshold values as you see fit. 
//Also, this is only for one laser, but you could easily add 
//a second with the same logic. Also, you can either directly wire
//the control panel button, or you can add it in code. I'll add it 
//if you need me to, just let me know

void setup() {
  //apparently we're not supposed to initialize the light sensors
  pinMode(magLock, OUTPUT);
  pinMode(light2, OUTPUT);
  pinMode(light3, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  //sensorVal1 = digitalRead(sensorPin1);
  //delay(10);
  sensorVal2 = analogRead(sensorPin2);
  delay(10);
  sensorVal3 = analogRead(sensorPin3);
  delay(10);

  Serial.println("Bottom Sensor: ");
  Serial.println(sensorVal2);
  Serial.println("Top Sensor: ");
  Serial.println(sensorVal3);
  
  if ((sensorVal2 >= threshold2) and (sensorVal3 >= threshold3)){ //To make sure both are good to allow passage
    digitalWrite(magLock, HIGH); 
  } else{
    digitalWrite(magLock, LOW);
  }
  //if (sensorVal1 >= threshold1){  //troubleshooting purposes
    //digitalWrite(light1,HIGH);
  //} else {
  //  digitalWrite(light1,LOW); 
  //}
  if(sensorVal2 >= threshold2){
    digitalWrite(light2,HIGH);
  } else {
    digitalWrite(light2,LOW);
  }
  if (sensorVal3 >= threshold3){  // ^^^
   digitalWrite(light3,HIGH);
  } else {
   digitalWrite(light3,LOW);
  }      
  delay(10);//To give it a small break after each loop.
}

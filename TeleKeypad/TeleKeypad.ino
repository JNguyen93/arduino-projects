#include <Keypad.h>

int hookSwitch = 2;
const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns
//define the cymbols on the buttons of the keypads
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {6, 5, 4, 3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {10, 9, 8}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); 

void setup(){
  pinMode(hookSwitch, INPUT);
  Serial.begin(9600);
}
  
void loop(){
  char customKey = customKeypad.getKey();
  int conn = digitalRead(hookSwitch);

  /*if(!conn) {
    Serial.println("Connected");
  }*/
  if (customKey){
    Serial.println(customKey);
  }
}

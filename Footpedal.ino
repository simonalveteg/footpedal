
#include "OneButton.h"

const int nbrButtons = 12;
const int Pins[nbrButtons] = {6,7,8,9,10,16,14,15,18,19,20,21}; // array of pins I want to use
OneButton buttons[nbrButtons];
const int ledPin = 1;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);


  for (int i = 0; i < nbrButtons; i++) {
    buttons[i] = OneButton(Pins[i],true,true);

    buttons[i].attachClick([](){
      Serial.println("b pressed!");
      digitalWrite(ledPin, HIGH);
      delay(50);
      digitalWrite(ledPin, LOW);
    });  
  }
}

void loop() {
  // loop through buttons and tick
  for (int i = 0; i < nbrButtons; i++) {
    buttons[i].tick(); 
  }
  //Serial.println(buttons[0].isLongPressed());
}

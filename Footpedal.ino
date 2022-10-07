
#include "OneButton.h"

const int nbrButtons = 12;
const int Pins[nbrButtons] = {6,7,8,9,10,16,14,15,18,19,20,21}; // array of pins I want to use
OneButton buttons[nbrButtons];

OneButton b = OneButton(21,true,true); // this button works

void setup() {
  Serial.begin(115200);

  // set up all the buttons
  for (int i = 0; i < nbrButtons; i++) {
    OneButton button = OneButton(Pins[i],true,true); // create a button at the pin
    button.attachClick([](){
      Serial.println("Button pressed!");
    });
    buttons[i] = button; // add button to the array
  }

  // attack click to test button
  b.attachClick([](){
      Serial.println("B pressed!");
    });
}

void loop() {
  // loop through buttons and tick
  for (OneButton button: buttons) {
    button.tick();
  }
  b.tick()
}

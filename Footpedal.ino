
#include "OneButton.h"

const int nbrButtons = 12;
const int Pins[nbrButtons] = {6,7,8,9,10,16,14,15,18,19,20,21}; // array of pins I want to use
OneButton buttons[nbrButtons];

void singlePress(void *s) {
  Serial.print("Button ");
  Serial.print((int)s);
  Serial.println(" pressed!");
}

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < nbrButtons; i++) {
    buttons[i] = OneButton(Pins[i],true,true);
    buttons[i].attachClick(singlePress, i);
  }
}

void loop() {
  for (int i = 0; i < nbrButtons; i++) {
    bool isPressed = (digitalRead(Pins[i]) == LOW);
    buttons[i].tick(isPressed); 
  }
}

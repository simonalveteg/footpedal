
#include "OneButton.h"

const int nbrButtons = 12;
const int Pins[nbrButtons] = {6,7,8,9,10,16,14,15,18,19,20,21}; // array of pins I want to use
OneButton buttons[nbrButtons];
const int ledPin = 1;

OneButton b = OneButton(21,true,true);
OneButton b1 = OneButton(20,true,true);
OneButton b2 = OneButton(19,true,true);
OneButton b3 = OneButton(18,true,true);
OneButton b4 = OneButton(17,true,true);

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);


  buttons[0] = b;
  buttons[1] = b1;
  buttons[2] = b2;
  buttons[3] = b3;
  buttons[4] = b4;

  
  buttons[0].attachClick([](){
    Serial.println("b pressed!");
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
  });
  buttons[1].attachClick([](){
    Serial.println("b1 pressed!");
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
  });
  buttons[2].attachClick([](){
    Serial.println("b2 pressed!");
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
  });
  buttons[3].attachClick([](){
    Serial.println("b3 pressed!");
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
  });
  buttons[4].attachClick([](){
    Serial.println("b4 pressed!");
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
  });
}

void loop() {
  // loop through buttons and tick
  for (OneButton button: buttons) {
    button.tick();
  }
  //buttons[0].tick();
  //buttons[1].tick();
  //buttons[2].tick();
  //buttons[3].tick();
  buttons[4].tick();
  //Serial.println(buttons[0].isLongPressed());
}

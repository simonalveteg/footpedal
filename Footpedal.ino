
#include "OneButton.h"
#include "MIDIUSB.h"

#define MIDI_CHANNEL 12
#define BASE_NOTE 0
#define VELOCITY 127

const int nbrButtons = 12;
const int Pins[nbrButtons] = {6,7,8,9,10,16,14,15,18,19,20,21};
OneButton buttons[nbrButtons];

void singlePress(void *s) {
  int btn = (int)s;
  Serial.println("Button " + (String)btn + " pressed!");
  
  int note = BASE_NOTE + 2*btn;
  noteOn(note);
  MidiUSB.flush();
  noteOff(note);
  MidiUSB.flush();
}

void longPress(void *s) {
  int btn = (int)s;
  Serial.println("Button " + (String)btn + " longpressed!");

  int note = BASE_NOTE + 2*btn+1;
  noteOn(note);
  MidiUSB.flush();
  noteOff(note);
  MidiUSB.flush();
}

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < nbrButtons; i++) {
    buttons[i] = OneButton(Pins[i],true,true);
    buttons[i].attachClick(singlePress, i);
    buttons[i].setPressTicks(300);
    buttons[i].attachLongPressStop(longPress, i);
  }
}

void loop() {
  for (int i = 0; i < nbrButtons; i++) {
    bool isPressed = (digitalRead(Pins[i]) == LOW);
    buttons[i].tick(isPressed); 
  }
}

void noteOn(byte pitch) {
  midiEventPacket_t noteOn = {0x09, 0x90 | MIDI_CHANNEL, pitch, VELOCITY};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte pitch) {
  midiEventPacket_t noteOff = {0x08, 0x80 | MIDI_CHANNEL, pitch, VELOCITY};
  MidiUSB.sendMIDI(noteOff);
}

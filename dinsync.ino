#include <MIDI.h>

#define PIN_TRIGGER 4
#define PIN_STARTSTOP 7
#define CLOCK_DIVIDER 12

MIDI_CREATE_DEFAULT_INSTANCE(); // <-- This was missing. "MIDI.read not defined in scope"

void HandleStart() {
	digitalWrite(PIN_STARTSTOP, HIGH);
}
void HandleContinue() {
	digitalWrite(PIN_STARTSTOP, HIGH);
}
void HandleStop() {
	digitalWrite(PIN_STARTSTOP, LOW);
}
void HandleClock() { 
  digitalWrite(PIN_TRIGGER, HIGH); 
  delayMicroseconds(2000); 
  digitalWrite(PIN_TRIGGER, LOW); 
}

// -----------------------------------------------------------------------------

void setup() {
	MIDI.begin(MIDI_CHANNEL_OMNI);
	Serial.begin(115200);
	
	pinMode(PIN_TRIGGER, OUTPUT);
	pinMode(PIN_STARTSTOP, OUTPUT);
	
	digitalWrite(PIN_TRIGGER, LOW);    
  
	MIDI.setHandleStart(HandleStart);
	MIDI.setHandleStop(HandleStop);
	MIDI.setHandleContinue(HandleContinue);
	MIDI.setHandleClock(HandleClock);
}


void loop() {
	MIDI.read();
}

#include <MIDI.h>

#define PIN_TRIGGER 4
#define PIN_STARTSTOP 7
#define CLOCK_DIVIDER 12

uint32_t rightNow = 0;          //  a place to store the time the clock pulse is called
bool clocked = false;           //  says whether a clock pulse has been set (true) or not (false)

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

//  Callback changed to non-blocking timing. Arduino can't respond to MIDI commands
//  if a blocking command like millis() or micros() is counting time.
void HandleClock() {
  rightNow = micros();              //  Measure time handleClock is triggered.
  digitalWrite(PIN_TRIGGER, HIGH);  //  Set DINsync trigger output HIGH.
  clocked = true;                   //  Set flag so loop knows to turn the
                                    //  clock pulse off.
}

//  This new function toggles the clock pulse LOW if clocked variable and 2000uS haven't yet elapsed
void clockPulseTimeout(){
  if(micros() >= rightNow + 2000 && clocked == true){   //  tests the condition
    digitalWrite(PIN_TRIGGER, LOW);                     //  unset PIN_TRIGGER
    clocked = false;                                    //  UNSET clocked.
  }
  //  This timing method ensures there is little chance of losing a stop trigger because 
  //  a clock pulse is high, as it's non-blocking. Should only take 10 or 20uS,
  //  instead of 2000uS that delayMicroseconds(2000) takes to run.
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
  clockPulseTimeout();    //  Calls the new clock pulse timeout function
}

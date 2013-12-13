arduino-din-sync
================

Send DIN (sync24) sync/start/stop from internal MIDI

#Dependencies
* Arduino
* [Arduino MIDI library](http://playground.arduino.cc/Main/MIDILibrary)
* [Hairless MIDIserial](http://projectgus.github.io/hairless-midiserial/] (send MIDI –> Arduino via serial)

#Getting started
![DIN-connections](http://gieskes.nl/master-clock-generator/images/sync24-Schematics.gif)

Wire up as pictured. Connect to Arduino (eg.) 

    PIN_TRIGGER 4
    PIN_STARTSTOP 7
    and ground to GND

Upload code. Boot up hairless midiserial –> send MIDI 
(eg from IAC internal audio or from external sound card with MIDI IN/OUT)

Profit!

---
Thanks [little-scale](http://little-scale.blogspot.se/), [gieskes](http://acid-byte.com/AcidByte/?page_id=65)

#About
Sync your old school gear with your new school gear. TR-606 <3 Ableton Live.

There are some articles on how to do this on the web but this one should be up to date and with start/stop.

#Dependencies
* Arduino
* [Arduino MIDI library](http://playground.arduino.cc/Main/MIDILibrary)
* [Hairless MIDIserial](http://projectgus.github.io/hairless-midiserial/) (send MIDI –> Arduino via serial)

#Getting started
![DIN-connections](http://gieskes.nl/master-clock-generator/images/sync24-Schematics.gif)

Wire up as pictured. Connect to Arduino 

    PIN_TRIGGER 4 / sync
    PIN_STARTSTOP 7 
    and ground to GND

Upload code. Boot up hairless midiserial –> send MIDI 
(eg from IAC internal audio or from external sound card with MIDI IN/OUT)

Profit!

---
Thanks [little-scale](http://little-scale.blogspot.se/), [gieskes](http://acid-byte.com/AcidByte/?page_id=65)

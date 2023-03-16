# Overview over Important Pin Identities
```PB5``` is the pin name of the builtin LED.
```PB7``` is the RX for the USB Serial port.
```PB6``` is the TX for the USB Serial port. 
It is worth noting that the standard Serial definition in Arduino.h does not work as intended on the LoRa-E5-mini.
What worked for us is to declare your own Serial port with the RX and TX pins described above. An example is shown in the main.cpp file. 

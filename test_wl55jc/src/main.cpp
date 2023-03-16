#include <Arduino.h>
#include "HardwareSerial.h"

HardwareSerial mySerial {PB7, PB6};
unsigned long last_millis {0};
bool state {true};
static constexpr unsigned long blink_duration {1000};

void setup(void)
{
    mySerial.begin(115200);
    delay(100);
    pinMode(PB5, OUTPUT);
    mySerial.println(F("Booted!"));

    last_millis = millis();
}

void loop(void)
{

    if (millis() - last_millis > blink_duration){
        state = !state;
        digitalWrite(PB5, state);
        last_millis += blink_duration;

        mySerial.print(F("Loop B)"));
        mySerial.println(millis());
    }

    while (mySerial.available() > 0){
        mySerial.print(mySerial.read());
    }

    
}
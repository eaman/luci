/*
  Luci Class
  RC planes light routines

*/

#include "Arduino.h"
#include "luci.h"

/////////////////////////////////////
// Lampeggiatore
// Constructor
Lampeggiatore::Lampeggiatore(int pin)
{
    ledPin = pin;
    pinMode(ledPin, OUTPUT);
    ledState = LOW;
    previousMillis = 0;
    interval = 500;
};




// Una funzione facente parte di una classe prende il nome di "metodo" della stessa:
void Lampeggiatore::Blink() {
    // Illumina il led a 500ms

    if(millis() - previousMillis > interval) {
        // save the last time you blinked the LED
        previousMillis = millis();

        // if the LED is off turn it on and vice-versa:
        ledState = !ledState ; // Inverti il LED
    }
    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
};

void Lampeggiatore::Blink(long time) {
    // Illumina il led secondo un intervallo passato come argomento

    if(millis() - previousMillis > time) {
        // save the last time you blinked the LED
        previousMillis = millis();

        // if the LED is off turn it on and vice-versa:
        ledState = !ledState ; // Inverti il LED
    }
    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
};

void Lampeggiatore::Blink(long up, long down) {
    // Illumina il ledB precisando ontime e downtime

    if((ledState == HIGH)&& (millis() - previousMillis > up)) {
    // save the last time you blinked the LED
    	previousMillis = millis();
        ledState = LOW  ;
    }
    else if((ledState == LOW)&& (millis() - previousMillis > down)) {
    	previousMillis = millis();
        ledState = HIGH  ;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
};


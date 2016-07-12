/*
  Aero Class
  RC planes light routines

*/

#include "Arduino.h"
#ifndef luci_h
#define luci_h

class Lampeggiatore {
    // Lampeggia un LED utilizzando millis()
    // Variabili
    int ledPin ;           // il numero del LED pin
    int ledState ;         // stato attuale del LED
    long interval ;        // milliseconds di intervallo nel lampeggiare
    long previousMillis ;  // precedente cambio di stato


    // Constructor: come viene instanziato un oggetto facente parte della classe
public:
    Lampeggiatore(int pin);
    void Blink(); 	// Lampeggia ogni 500ms
    void Blink(long interval); // Lampeggia inpostando l'intervallo
    void Blink(long on, long down); // Imposta il tempo acceso e il tempo spento
};




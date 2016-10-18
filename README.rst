Arduino lib
============

Libreria per Arduino per gestione base delle luci utilizzando la funzione ``millis()`` e codice OOP.

Nell'archivio sono disponibili esempi per gestire le funzioni base di blinks, PWM e KnightRider utilizzando la funzione delay, millis, OOP, libreria di per Arduino.



Guida
======

* RST: http://thomas-cokelaer.info/tutorials/sphinx/rest_syntax.html
* GIT: https://git-scm.com/docs/user-manual.html
* Github: https://github.com/eaman/arduino


* millis: https://learn.adafruit.com/multi-tasking-the-arduino-part-1/overview
* OOP:  https://learn.adafruit.com/multi-tasking-the-arduino-part-1/a-classy-solution
* Librerie: https://www.arduino.cc/en/Hacking/LibraryTutorial


Manutenzione
===============

Comandi usati per la gestione del repo.

Scaricare
------------


	git clone https://github.com/eaman/luci


Aggiornare il repo
---------------------

	git pull


Proporre una push request
--------------------------

TODO


Comandi di base
--------------------


* Per clonare: git clone https://github.com/eaman/luci.git
* Stato del repo: git status
* Aggiungere files: git add .
* Commit: git commit
* per caricare: git push


Specificare chiave SSH
--------------------------

In ```vim ~/.ssh/config```::

	host github.com
	 HostName github.com
	 IdentityFile ~/.ssh/github.rsa
	 User git


La chiave e' stata generata con::

	ssh-keygen -t rsa -b 4096 -C "andrea@piffa.net"


Per testare il login::

	ssh -vT git@github.com


Blinks
==========

Gestione del lampeggio di un LED.

PWM
=========

PWMs di un LED.

Gestito da:

* Salvatore
* Michele


KnightRider
==============

Lampeggio in sequenza di una serie di LED, da: https://www.arduino.cc/en/Tutorial/KnightRider

Gestiti da:

* Carmine
* Mario
* Andrea

Esempio funzionante
-------------------

./knight_rider/knight_rider_led_stream/knight_rider_led_stream.ino

Strategia
---------

La velocita' di scansione dei led diminuisce progressivamente, poi raggiunta una
soglia minima aumenta di nuovo.

Per dare un effetto "di inerzia" avremmo voluto usare la modulazione di intensita',
con un led accesso al massimo e gli altri progressivamente meno luminosi;
ma poiche' non tutti i pin di Arduino supportanto la PWM, abbiamo adottato un altro approccio.

Inizialmente viene accesso un solo led, poi (a velocita' intermedia) una coppia di led,
poi (a velocita' ancora superiore) il led selezionato e i due adiacenti.

Esempio di utilizzo
-------------------

::

    KnightRiderLedStream stream1 = KnightRiderLedStream();

    void setup() {
      Serial.begin(9600);
      stream1.initialize(2, 10, 30, 120);
    }

    void loop() {

      long now = millis();
      stream1.tick(now);

      delay(10);
    }

oppure:

::

    KnightRiderLedStream stream1 = KnightRiderLedStream();
    KnightRiderLedStream stream2 = KnightRiderLedStream();

    void setup() {
      Serial.begin(9600);
      stream1.initialize(2, 5, 30, 120);
      stream2.initialize(6, 9, 30, 120);
    }

    void loop() {

      long now = millis();

      stream1.tick(now);
      stream2.tick(now);

      delay(10);
    }

Video dimostrativo:

    https://vimeo.com/180419866

Struttura del repo
======================

delay
----------

Esempi base con funzione delay

millis
--------
Esempi base con funzione millis

oggetti
-----------
Codice OOP


Libreria
---------------

Libreria finale pronta all'uso, dovra' essere disponibile nel PATH di Arduino IDE (es. ``$arduino_sketchbook/Libraries;/usr/share/arduino/libraries``).

Si veda i tutorial:

* https://www.arduino.cc/en/Hacking/LibraryTutorial
* http://playground.arduino.cc/Code/Library

lib.h
~~~~~~~~~

Header file

lib.cpp
~~~~~~~~~~

Main file

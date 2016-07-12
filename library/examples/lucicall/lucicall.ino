/* Luci Call

   Esempio di chiamata della libreria luci.
 
 */
#include "luci.h"


Lampeggiatore ledA(13);


void setup() {
}

void loop()
{
ledA.Blink(1000,200);
}


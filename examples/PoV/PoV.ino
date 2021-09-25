/**
 *  PoV is a very simple persistent of vision display that use ATTiny85
 *  and 5 leds
 **/
#include <Arduino.h>
#include <uPoV.h>

#define LEDS 5

#define LED1 4
#define LED2 3
#define LED3 2
#define LED4 1
#define LED5 0

// led matrix
unsigned char LED[LEDS] = {LED1, LED2, LED3, LED4, LED5};
uPoV pov = uPoV(LED, LEDS);

void setup()
{
    // perform leds test
    for (unsigned char i = 0; i < LEDS; i++)
    {
        digitalWrite(LED[i], HIGH);
        delay(250);
    }

    for (unsigned char i = 0; i < LEDS; i++)
    {
        digitalWrite(LED[(LEDS - 1) - i], LOW);
        delay(250);
    }
}

void loop()
{
    // display message
    pov.display("jacopo sallemi");
}

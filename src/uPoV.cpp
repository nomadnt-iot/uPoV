#include "uPoV.h"

uPoV::uPoV(unsigned char *leds, unsigned char size, unsigned char delayTime, unsigned char charBreak)
{
    _delayTime = delayTime;
    _charBreak = charBreak;
    _leds = leds;
    _size = size;

    for (unsigned char i = 0; i < _size; i++)
    {
        pinMode(_leds[i], OUTPUT);
    }
}

void uPoV::display(const char *msg)
{
    for (unsigned int i = 0; i <= strlen(msg); i++)
    {
        __char(msg[i]);
    }
}

void uPoV::__char(char c)
{
    for (unsigned char i = 0; i < (sizeof(symbols) / sizeof(symbols[0])); i++)
    {
        if (c == pgm_read_byte(&symbols[i].code))
        {
            for (unsigned char j = 0; j < _size; j++)
            {
                // __line(pgm_read_byte(&symbols[i].value[j]));
                __pixel(pgm_read_byte(&symbols[i].value[j]));
                delay(_delayTime);
            }
            // __line(0);
            __pixel(0);
        }
    }

    delay(_charBreak);
}

void uPoV::__line(unsigned char line)
{
    if (line >= 16)
    {
        digitalWrite(_leds[0], HIGH);
        line -= 16;
    }
    else
    {
        digitalWrite(_leds[0], LOW);
    }
    if (line >= 8)
    {
        digitalWrite(_leds[1], HIGH);
        line -= 8;
    }
    else
    {
        digitalWrite(_leds[1], LOW);
    }
    if (line >= 4)
    {
        digitalWrite(_leds[2], HIGH);
        line -= 4;
    }
    else
    {
        digitalWrite(_leds[2], LOW);
    }
    if (line >= 2)
    {
        digitalWrite(_leds[3], HIGH);
        line -= 2;
    }
    else
    {
        digitalWrite(_leds[3], LOW);
    }
    if (line >= 1)
    {
        digitalWrite(_leds[4], HIGH);
        line -= 1;
    }
    else
    {
        digitalWrite(_leds[4], LOW);
    }
}

void uPoV::__pixel(unsigned char line)
{
    for (unsigned char i = 0; i < _size; i++)
    {
        (line & 1 << i) ? digitalWrite(_leds[i], HIGH) : digitalWrite(_leds[i], LOW);
    }
}

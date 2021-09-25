# uPoV

## Description
**uPoV** is a tiny library to drive leds to make Persistent of Vision display.

It is using as less resources as possible and at this point in time is only tested with 5 leds on ATTiny85.

## Introduction


### Low memory requirements

I'm working on a version that is using pure avr-c code but keeping in mind code readability.

## Compatibility

Although so far I've only tested on a couple of ATTiny85 chips, they should support all Atmel chips.

## Description

This section is a WIP

## Examples

```c
#include <uPoV.h>

unsigned char LED[5] = {4, 3, 2, 1, 0};
uPoV pov = uPoV(LED, 5);

void setup()
{
    // your setup code here
}

void loop()
{
    // display message
    pov.display("Hello world!");
}
```
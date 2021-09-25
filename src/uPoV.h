#ifndef _uPoV_H_
#define _uPoV_H_

#include <Arduino.h>
#include "Symbols.h"

class uPoV
{
public:
	/**
	 * class constructor
	 */
	uPoV(unsigned char *leds, unsigned char size, unsigned char delayTime = 2, unsigned char charBreak = 5);

	/**
	 * display message on pov led bar
	 */
	void display(const char *msg);

private:
	/**
	 * delay time between subchar elements
	 */
	unsigned char _delayTime;

	/**
	 * delay time between two chars
	 */
	unsigned char _charBreak;

	/**
	 * leds array
	 */
	unsigned char *_leds;

	/**
	 * size of leds array
	 */
	unsigned char _size;

	/**
	 * display single char
	 */
	void __char(char c);

	/**
	 * display single line of a char
	 */
	void __line(unsigned char line);

	/**
	 * display single line of a char
	 */
	void __pixel(unsigned char line);
};

#endif

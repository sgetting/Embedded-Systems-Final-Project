/*
 * keypad.h
 *
 * Created: 5/16/2012 11:24:44 AM
 *  Author: Scott
 */ 
#ifndef __keypad__
#define __keypad__
#include "avr.h"

#define row_in PINA
#define row_out PORTA
#define row_ddr DDRA
#define rowstart 1

#define col_in PINB
#define col_out PORTB
#define col_ddr DDRB
#define colstart 0

typedef enum key{
	KEYA,
	KEYB,
	KEYC,
	KEYD,
	KEY0,
	KEY1,
	KEY2,
	KEY3,
	KEY4,
	KEY5,
	KEY6,
	KEY7,
	KEY8,
	KEY9,
	KEYstar,
	KEYhash,
	KEYnull
} key;

static const key key_table[4][4] = {
	{KEYD,KEYhash,KEY0,KEYstar},
	{KEYC,KEY9,KEY8,KEY7},
	{KEYB,KEY6,KEY5,KEY4},
	{KEYA,KEY3,KEY2,KEY1}			
};

key get_key();

void get_key2();

#endif
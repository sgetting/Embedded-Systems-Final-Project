/*
 * Lab4.c
 *
 * Created: 5/16/2012 11:19:26 AM
 *  Author: Scott
 */ 

/*

#include "avr.h"
#include "lcd.h"

#include "keypad.h"

short min = 1024;
short max = -1024;
float average = 0;
short current = 0;
short counter = 0;


void reset(void){
	min = 1024;
	max = -1024;
	average = 0;
}

int get_adc(void) {
	SET_BIT(ADCSRA, ADSC);
	
	while(!GET_BIT(ADCSRA, ADIF));
	counter++;
	
	return ADC;
}

int main(void) {
	ini_lcd();
	clr_lcd();
	pos_lcd(0,0);
	puts_lcd2("hi");
}

*/
// int main(void)
// {
// 	ini_lcd();
//     while(1)
//     {
// 		pos_lcd(0,0);
// 		
//         key keyPressed = get_key();
// 		char* output;
// 		switch (keyPressed) {
// 			case KEY0:
// 				output = PSTR("Key 0 pressed.");
// 				break;
// 			case KEY1:
// 				output = PSTR("Key 1 pressed.");
// 				break;
// 			case KEY2:
// 				output = PSTR("Key 2 pressed.");
// 				break;
// 			case KEY3:
// 				output = PSTR("Key 3 pressed.");
// 				break;
// 			case KEY4:
// 				output = PSTR("Key 4 pressed.");
// 				break;
// 			case KEY5:
// 				output = PSTR("Key 5 pressed.");
// 				break;
// 			case KEY6:
// 				output = PSTR("Key 6 pressed.");
// 				break;
// 			case KEY7:
// 				output = PSTR("Key 7 pressed.");
// 				break;
// 			case KEY8:
// 				output = PSTR("Key 8 pressed.");
// 				break;
// 			case KEY9:
// 				output = PSTR("Key 9 pressed.");
// 				break;
// 			case KEYA:
// 				output = PSTR("Key A pressed.");
// 				break;
// 			case KEYB:
// 				output = PSTR("Key B pressed.");
// 				break;
// 			case KEYC:
// 				output = PSTR("Key C pressed.");
// 				break;
// 			case KEYD:
// 				output = PSTR("Key D pressed.");
// 				break;
// 			case KEYhash:
// 				output = PSTR("Key # pressed.");
// 				break;
// 			case KEYstar:
// 				output = PSTR("Key * pressed.");
// 				break;
// 			case KEYnull:
// 				output = PSTR("No Key pressed");
// 				break;
// 		}
// 		puts_lcd(output);
// 		
// 		wait_avr(100);
//     }
// }
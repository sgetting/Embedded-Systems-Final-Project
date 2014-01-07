/*
 * Lab4.c
 *
 * Created: 5/16/2012 11:19:26 AM
 *  Author: Scott
 */ 

#include "avr.h"
#include "lcd.h"
#include "keypad.h"
#include "./fft/ffft.h"

#define TIMER_PERIOD 500
#define VREF 2.56
#define ARRAYSIZE 64
#define DENOMINATOR 1024

int readings [FFT_N];
complex_t butterflyArray[FFT_N];
uint16_t frequencies[FFT_N];
uint16_t averageFrequencies[16];
float min;
float max;

void initADC()
{
	//ADMUX = 0x09; //differential between channel 1 and 0, 10x gain
	ADMUX = 0x09; //single ended input on channel ADSC1
	SET_BIT(ADMUX, REFS0);
	SET_BIT(ADMUX, REFS1);
	
	//RESFO = 1 & REFS1 = 1 : Internal 2.56V ref w/ external capacitor on AREF (32) 
	
	SET_BIT(ADCSRA, ADPS0);
	SET_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS2);	
	
	SET_BIT(ADCSRA, ADEN);
}


int currentGet(void)
{
	SET_BIT(ADCSRA, ADSC);
	while(!GET_BIT(ADCSRA, ADIF));
	return ADC;
}

void getSamples(void)
{
	int counter = 0;
	float result = currentGet();
	min = max = result;
	while (counter < ARRAYSIZE)
	{
		int result = currentGet();
		if (result < min)
		{
			min = result;
		}
		if (result > max)
		{
			max = result;
		}
		readings[counter++] = result;
	}
}

void sortResultsArray(void)
{
	float difference = max - min;	
	float range [9];
	range[0] = 0;
	range[1] = difference * .125;
	range[2] = difference * .250;
	range[3] = difference * .375;
	range[4] = difference * .5;
	range[5] = difference * .625;
	range[6] = difference * .75;
	range[7] = difference * .875;
	range[8] = difference * 1;
	for (int i = 0; i < ARRAYSIZE; i++)
	{
		int counter = 0;
		for (int j = 0; j < 16; j++)
		{
			if (readings[i] < range[1])
			{
				putbar(counter, 0);
			}
			else if (readings[i] < range[2])
			{
				putbar(counter, 1);
			}
			else if (readings[i] < range[3])
			{
				putbar(counter, 2);
			}
			else if (readings[i] < range[4])
			{
				putbar(counter, 3);
			}
			else if (readings[i] < range[5])
			{
				putbar(counter, 4);
			}
			else if (readings[i] < range[6])
			{
				putbar(counter, 5);
			}
			else if (readings[i] < range[7])
			{
				putbar(counter, 6);
			}
			else if (readings[i] <= range[8])
			{
				putbar(counter, 7);
			}
			i++;
			counter++;
		}
		while (get_key() != KEY1)
			;
		wait_avr(50);
	}
}

void displayFrequencies(void)
{
	char args [17];
	for (int i = 0; i < FFT_N; i++)
	{
		clr_lcd();
		pos_lcd(0,0);
		sprintf(args, "%d: %d",i, frequencies[i]);
		puts_lcd2(args);
		while (get_key() != KEY1)
			;
		wait_avr(TIMER_PERIOD);
	}
}

void displayFrequencyBars(void)
{
	int min = 0;
	int max = 250;
	
	for (int i = 1; i < 17; i++)
	{
		if (frequencies[i] < min)
		{
			min = frequencies[i];
		}
		if (frequencies[i] > max)
		{
			max = frequencies[i];
		}
	}
	float difference = max - min;
	float ranges [8];
	ranges[0] = (float) min + difference * .125;
	ranges[1] = (float) min + difference * .25;
	ranges[2] = (float) min + difference * .375;
	ranges[3] = (float) min + difference * .5;
	ranges[4] = (float) min + difference * .625;
	ranges[5] = (float) min + difference * .75;
	ranges[6] = (float) min + difference * .875;
	ranges[7] = (float) min + difference;
	
	for (int i = 1; i < 17; i++)
	{	
		if (frequencies[i] < ranges[0])
		{
			putbar(i, 0);
		}
		else if (frequencies[i] < ranges[1])
		{
			putbar(i, 1);
		}
		else if (frequencies[i] < ranges[2])
		{
			putbar(i, 2);
		}
		else if (frequencies[i] < ranges[3])
		{
			putbar(i, 3);
		}
		else if (frequencies[i] < ranges[4])
		{
			putbar(i, 4);
		}
		else if (frequencies[i] < ranges[5])
		{
			putbar(i, 5);
		}
		else if (frequencies[i] < ranges[6])
		{
			putbar(i, 6);
		}
		else 
		{
			putbar(i, 7);
		}
	}
}

int main ()
{
	ini_lcd();
	clr_lcd();
	pos_lcd(0,0);
	initBars();
	initADC();
	while(1)
	{
		getSamples();
		fft_input(readings, butterflyArray);
		fft_execute(butterflyArray);
		fft_output(butterflyArray,frequencies);
		//displayFrequencies();
		displayFrequencyBars();
		wait_avr(25);
	}
}
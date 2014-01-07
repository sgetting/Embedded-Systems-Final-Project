/*
 * keypad.c
 *
 * Created: 5/16/2012 11:55:42 AM
 *  Author: Scott
 */
#include "keypad.h"

key get_key() {
	char r,c;
	// Initially: set row to input, floating
	for(r = rowstart;r<rowstart+4;r++){
		CLR_BIT(row_ddr,r);
		CLR_BIT(row_out,r);
	}
	// Set col to input, pull-up
	for(c = colstart;c<colstart+4;c++){
		CLR_BIT(col_ddr,c);
		SET_BIT(col_out,c);
	}
	
	for (r = rowstart; r < rowstart + 4; r++)
	{
		// Set row to output, low
		SET_BIT(row_ddr,r);
		for (c = colstart; c < colstart + 4; c++)
		{
			if(!GET_BIT(col_in, c))
			{
				return key_table[r - rowstart][c - colstart];
			}
		}
		// Reset row to input, floating
		CLR_BIT(row_ddr,r);
	}
	return KEYnull;
}


void get_key2() {
	int r,c;
	char buf[30];
	// Initially: set row to input, floating
	for(r = rowstart;r<rowstart+4;r++){
		CLR_BIT(row_ddr,r);
		CLR_BIT(row_out,r);
	}
	// Set col to input, pull-up
	for(c = colstart;c<colstart+4;c++){
		CLR_BIT(col_ddr,c);
		SET_BIT(col_out,c);
	}
	
	for (r = rowstart; r < rowstart + 4; r++)
	{
		// Set row to output, low
		SET_BIT(row_ddr,r);
		for (c = colstart; c < colstart + 4; c++)
		{
			if(!GET_BIT(col_in, c))
			{
				clr_lcd();
				sprintf(buf,"row %d, col %d", r, c);
				pos_lcd(0,0);
				puts_lcd2(buf);
			}
		}
		// Reset row to input, floating
		CLR_BIT(row_ddr,r);
	}
}

/*
 * song.c
 *
 *  Created on: Feb 27, 2013
 *      Author: maserra3
 */

#include "note.h"
#include "song.h"
#include "pit.h"
/*for testing*/
static void busy_delay(int p_delay)
{
	int i, x = 1;
	for (i = 0; i < p_delay; ++i) 
	{
		x = x * 2 + 1;
	}
}

/*test song*/
void play_song(){
			
			
			note(0x06,0);
			busy_delay(1000000);
			
			busy_delay(1000000);
			note(1,0);//c
			
			busy_delay(10000);
			note(0xFF,0);
			
			busy_delay(1000000);
			note(0x01,0);//c
			busy_delay(1000000);
			
			note(0x08,0x00);//g
			busy_delay(1000000);
			
			busy_delay(10000);
			note(0xFF,0);
			
			note(0x08,0);
			busy_delay(1000000);
			
			note(0x0A,0);
			busy_delay(1000000);
			
			busy_delay(10000);
			note(0xFF,0);
			
			note(0x0A,0);
			busy_delay(1000000);
			
			note(0x08,0);
			busy_delay(1000000*2);
			
			note(0x06,0);
			busy_delay(1000000);
			note(0x07,0);
			busy_delay(1000000);
			note(0x08,0);
			busy_delay(1000000);
			note(0x09,0);
			busy_delay(1000000);
			note(0x0A,0);
			busy_delay(1000000);
			note(0x0B,0);
			busy_delay(1000000);
			note(0x0D,0);
			busy_delay(1000000*3);
			
			
}

void song_notes(){
	
	
	note(0x00,0x00);
	//busy_delay(1000000);
	//pit0_isr();
	note(0x01,0x01);
	//busy_delay(1000000);
	note(0x02,0x03);
	//pit0_isr();
	//busy_delay(1000000);
	note(0x03,3);
	//pit0_isr();
	
	//busy_delay(1000000);
	note(0x04,5);
	//busy_delay(1000000);
	note(0x05,5);
	//busy_delay(1000000);
	note(0x06,5);
	//busy_dely(1000000);
	note(0x07,5);
	//busy_delay(1000000);
	note(0x08,3);
	//busy_delay(1000000);
	note(0x09,3);
	//busy_delay(1000000);
	note(0x0A,1);
	//busy_delay(1000000);
	note(0x0B,0);
	//busy_delay(1000000);
	note(0x0D,0);
	//busy_delay(1000000);
}
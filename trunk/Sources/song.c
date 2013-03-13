/*
 * song.c
 *
 *  Created on: Feb 27, 2013
 *      Author: maserra3
 */

#include "note.h"
#include "song.h"
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
	note(0x00);
			busy_delay(500000);
			note(0x01);
			busy_delay(500000);
			note(0x02);
			busy_delay(500000);
			note(0x03);
			busy_delay(500000);
			note(0x04);
			busy_delay(500000);
			note(0x05);
			busy_delay(500000);
			note(0x06);
			busy_delay(500000);
			note(0x07);
			busy_delay(500000);
			note(0x08);
			busy_delay(500000);
			note(0x09);
			busy_delay(500000);
			note(0x0A);
			busy_delay(500000);
			note(0x0B);
			busy_delay(500000);
			note(0x0D);
			busy_delay(500000);
	
}
/*
 * song.c
 *
 *  Created on: Feb 27, 2013
 *      Author: maserra3
 */

#include "note.h"
#include "song.h"
#include "pit.h"

struct songNotes{
	int pitch;
	int length;
	
};

struct songNotes list[256];
int noteCount;
int i;

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
	noteCount = 3;
	
	song_notes();
			
	for (i=0;i<=noteCount;i++)
	{
		if (i >= noteCount){
			i = -1;
		}
		else
		{
			note(list[i].pitch, list[i].length);
		}
	}
			
}

//
void song_notes(){
	
	
	list[0].pitch = 0x01;
	list[0].length = 0x03;
	
	list[1].pitch = 0x0A;
	list[1].length = 0x03;
	
	list[2].pitch = 0x06;
	list[2].length = 0x03;
	
	list[3].pitch = 0x00;
	list[3].length = 0x01;
	

	
	
}
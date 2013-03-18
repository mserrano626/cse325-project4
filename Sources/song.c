/*Source File:	song.c
 *Project Name:	Project 4
 *Name:			Mario Serrano
 *Email:		maserra3@asu.edu
 *Course name:	CSE325 Embedded Microprocessor Systems
 *Semester:		Spring 2013
 */
#include "note.h"
#include "song.h"
#include "pit.h"
#include "pwm.h"

struct songNotes{
	int pitch;
	int length;
	
};

struct songNotes list[256];
int noteCount;
int i;


/*test song*/
void play_song(){
	noteCount = 38;
	
	song_notes();
	
	note(list[i].pitch, list[i].length);
	
	i++;
	i = i % 39;

}


void song_notes(){
	
	//d 8th
	list[0].pitch = 0x03;
	list[0].length = 0x05;
	
	//f 4th
	list[1].pitch = 0x06;
	list[1].length = 0x03;
	
	//g 8th
	list[2].pitch = 0x08;
	list[2].length = 0x05;
	
	//A 8th dot
	list[3].pitch = 0x0A;
	list[3].length = 0x06;
	
	//B 16th
	list[4].pitch = 0x0C;
	list[4].length = 0x07;
	
	//A 8th
	list[5].pitch = 0x0A;
	list[5].length = 0x05;
	
	//g 4th
	list[6].pitch = 0x08;
	list[6].length = 0x03;
	
	//e 8th
	list[7].pitch = 0x05;
	list[7].length = 0x05;
	
	//c 8th dot
	list[8].pitch = 0x01;
	list[8].length = 0x06;
	
	//D 16th
	list[9].pitch = 0x03;
	list[9].length = 0x07;
	
	//E 8th
	list[10].pitch = 0x05;
	list[10].length = 0x05;
	
	//F 4th
	list[11].pitch = 0x06;
	list[11].length = 0x03;
	
	//d 8th
	list[12].pitch = 0x03;
	list[12].length = 0x05;
	
	//d 8th dot
	list[13].pitch = 0x03;
	list[13].length = 0x06;
	
	//c# 16th
	list[14].pitch = 0x02;
	list[14].length = 0x07;
	
	//d 8th
	list[15].pitch = 0x03;
	list[15].length = 0x05;
	
	////////////////////////////////////////////////
	//line 2
	
	//e 4th
	list[16].pitch = 0x05;
	list[16].length = 0x03;
	
	//c# 8th
	list[17].pitch = 0x02;
	list[17].length = 0x05;
	
	//A 4th
	list[18].pitch = 0x0A;
	list[18].length = 0x03;
	
	//D 8th
	list[19].pitch = 0x03;
	list[19].length = 0x05;
	
	//F 4th
	list[20].pitch = 0x06;
	list[20].length = 0x03;
	
	//G 8th
	list[21].pitch = 0x08;
	list[21].length = 0x05;
	
	//A 8th dot
	list[22].pitch = 0x0A;
	list[22].length = 0x06;
	
	//B 16th
	list[23].pitch = 0x0C;
	list[23].length = 0x07;
	
	//A 8th
	list[24].pitch = 0x0A;
	list[24].length = 0x05;
	
	//g 4th
	list[25].pitch = 0x08;
	list[25].length = 0x03;
	
	//e 8th
	list[26].pitch = 0x05;
	list[26].length = 0x05;
	
	//c 8thdot
	list[27].pitch = 0x01;
	list[27].length = 0x06;
	
	//D 16th
	list[28].pitch = 0x03;
	list[28].length = 0x07;
	
	//e 8th
	list[29].pitch = 0x05;
	list[29].length = 0x05;
	
	////////// line 3
	//F 8th dot
	list[30].pitch = 0x06;
	list[30].length = 0x06;
	
	//E 16th
	list[31].pitch = 0x05;
	list[31].length = 0x07;
	
	//D 8th
	list[32].pitch = 0x03;
	list[32].length = 0x05;
	
	//C# 8th dot
	list[33].pitch = 0x02;
	list[33].length = 0x06;
	
	//b 16th
	list[34].pitch = 0x00;
	list[34].length = 0x07;
	
	//c 8th
	list[35].pitch = 0x01;
	list[35].length = 0x05;

	//d 4thdot
	list[36].pitch = 0x03;
	list[36].length = 0x04;
	
	//d 4thdot
	list[37].pitch = 0x03;
	list[37].length = 0x04;
	
	//end rest
	list[38].pitch = 0xFF;
	list[38].length = 0x00;
	
	
}
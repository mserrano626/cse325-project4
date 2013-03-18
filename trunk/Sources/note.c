/*
 * note.c
 *
 *  Created on: Feb 27, 2013
 *      Author: maserra3
 */

#include "note.h"
#include "pit.h"
#include "pwm.h"
#include "led.h"

struct Note{
	int pre;
	int scale;
	int period;
	int duty;
	int led;
}Note;


void note(int p_note, int duration)
{
	uc_led_all_off();
	
	if(p_note == 0x00){
		/*B3 - 246.94 Hz*/
		Note.pre = 0x01;
		Note.scale = 0xA2;
		Note.period = 0xFA;
		Note.duty = 0xC8;
		Note.led = 1;
	}
	else if (p_note == 0x01){
		/*C4 - 261.63*/
		Note.pre = 2;
		Note.scale = 149;
		Note.period = 255;
		Note.duty = 204;
		Note.led = 2;
	}
	else if (p_note == 0x02){
			/*C#4 - 277.18*/
		Note.pre = 0x01;
		Note.scale = 0xCD;
		Note.period = 0xB0;
		Note.duty = 0x84;
		Note.led = 3;
		}
	else if (p_note == 0x03){
			/*D4 - 293.66*/
		Note.pre = 0x01;
		Note.scale = 0xC6;
		Note.period = 0xAC;
		Note.duty = 0x81;
		Note.led = 4;
		}
	else if (p_note == 0x04){
			/*D#4 - 311.13*/
		Note.pre = 0x01;
		Note.scale = 0xCE;
		Note.period = 0x9C;
		Note.duty = 0x75;
		Note.led = 1;
		}
	else if (p_note == 0x05){
			/*E4 - 329.63*/
		Note.pre = 0x01;
		Note.scale = 0xED;
		Note.period = 0x80;
		Note.duty = 0x60;
		Note.led = 2;
		}
	else if (p_note == 0x06){
			/*F4 - 349.23*/
		Note.pre = 0x00;
		Note.scale = 0xE6;
		Note.period = 0xF9;
		Note.duty = 0xBB;
		Note.led = 3;
		}
	else if (p_note == 0x07){
			/*F#4 - 369.99*/
		Note.pre = 0x00;
		Note.scale = 0xE8;
		Note.period = 0xE9;
		Note.duty = 0xAF;
		Note.led = 4;
		}
	else if (p_note == 0x08){
			/*G4 - 392.00*/
		Note.pre = 0x00;
		Note.scale = 0xEA;
		Note.period = 0xDA;
		Note.duty = 0xA4;
		Note.led = 1;
		}
	else if (p_note == 0x09){
			/*G#4 - 415.30*/
		Note.pre = 0x00;
		Note.scale = 0xF2;
		Note.period = 0xC7;
		Note.duty = 0x95;
		Note.led = 2;
		}
	else if (p_note == 0x0A){
			/*A4 - 440 Hz*/
		Note.pre = 0x00;
		Note.scale = 0xF3;
		Note.period = 0xBB;
		Note.duty = 0x8C;
		Note.led = 3;
		}
	else if (p_note == 0x0B){
			/*A#4 - 466.16*/
		Note.pre = 0x00;
		Note.scale = 0xBD;
		Note.period = 0xE3;
		Note.duty = 0xAA;
		Note.led = 4;
		}
	else if (p_note == 0x0C){
		/*B3 - 246.94 Hz*/
		Note.pre = 0x00;
		Note.scale = 0xA2;
		Note.period = 0xFA;
		Note.duty = 0xC8;
		Note.led = 1;
	}
	else if (p_note == 0x0D){
			/*C5 - 523.25*/
		Note.pre = 0x00;
		Note.scale = 0xF5;
		Note.period = 0x9C;
		Note.duty = 0x75;
		Note.led = 1;
		}
	else{
		//pause
		Note.pre = 0x00;
		Note.scale = 0x0;
		Note.period = 0x0;
		Note.duty = 0x0;
		Note.led = 4;
		
	}
	
	set_pitch(Note.pre, Note.scale, Note.period, Note.duty);
	set_note_length(duration);
	uc_led_on(Note.led);
	
	
}
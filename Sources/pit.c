/*
 * pit.c
 *
 *  Created on: Feb 27, 2013
 *      Author: maserra3
 */

#include "pit.h"
#include "support_common.h"
#include "led.h"

int currentTempo;
unsigned int timer;
unsigned int quarterNoteTime;
unsigned int newTime;
int tempo;
int d_flag = 0;
int d_count = 0;

void pit0_init(){
	
	MCF_PIT0_PCSR &= ~(MCF_PIT_PCSR_EN);
	MCF_PIT0_PCSR |= MCF_PIT_PCSR_RLD;
	MCF_PIT0_PCSR |= MCF_PIT_PCSR_PIF;
	MCF_PIT0_PCSR |= MCF_PIT_PCSR_PIE;
	MCF_PIT0_PCSR |= MCF_PIT_PCSR_OVW;
	MCF_PIT0_PCSR |= MCF_PIT_PCSR_DBG;
	MCF_PIT0_PCSR |= MCF_PIT_PCSR_PRE(13);
	
	currentTempo = 60;
	set_tempo();
	
	
	timer = MCF_PIT0_PMR;
	//enable
	MCF_PIT0_PCSR |= MCF_PIT_PCSR_EN;
	
}


void set_note_length(int note_length){
	
	
	
	
	
	if (note_length == 0x00){
		//whole note
		newTime = (unsigned int)timer * 4;
	}
	else if (note_length == 0x01){
		//half note
		newTime = (unsigned int)timer * 2;
	}
	else if (note_length == 0x02){
		//dotted half
		newTime = (unsigned int)timer * 3;
	}
	else if (note_length == 0x03){
		//quarter
		newTime = (unsigned int)timer;
	}
	else if (note_length == 0x04){
		//dotted quarter
		newTime = (unsigned int)timer * 1.5;
	}
	else if (note_length == 0x05){
		//eighth
		newTime = (unsigned int)timer * .5;
	}
	else if (note_length == 0x06){
		//dotted eighth
		newTime = (unsigned int)timer * .75;
	}
	else if (note_length == 0x07){
		//16th
		newTime = (unsigned int)timer * .25;
	}
	else if (note_length == 0x08){
		//dotted 16th
		newTime = (unsigned int)timer * .375;
	}
	else if (note_length == 0x09){
		//32nd
		newTime = (unsigned int)timer * .0625;
	}
	else if (note_length == 0x0A){
		//dotted 32nd
		newTime = (unsigned int)timer * .09375;
	}
	else if (note_length == 0x0B){
		//64th
		newTime = (unsigned int)timer * .03125;
	}
	else
		newTime = timer * 0; // .25 rest
	
	//clear PMR of previous value
		MCF_PIT0_PMR &= 0;

		//set the new PMR value
		MCF_PIT0_PMR |= (int) newTime;

		//enable PIT
		MCF_PIT0_PCSR |= 0x1;
	//assign new value to PMR
	//MCF_PIT0_PMR = MCF_PIT_PMR_PM((unsigned short)newTime);
	//enable
	//MCF_PIT0_PCSR |= MCF_PIT_PCSR_EN;
	
}

void set_tempo(){
	
	
	if(currentTempo == 60)
		d_flag = 10;
	if(currentTempo == 120)
		d_flag = -10;

	currentTempo = currentTempo + d_flag;
		
	//set value of counter
	switch(currentTempo){
	case 70: quarterNoteTime = 4184;
		currentTempo = 70;
		break;
	case 80: quarterNoteTime = 3661;
		currentTempo = 80;
		break;
	case 90: quarterNoteTime = 3254;
		currentTempo = 90;
		break;
	case 100: quarterNoteTime = 2929;
		currentTempo = 100;		
		break;	
	case 110: quarterNoteTime = 2662;
		currentTempo = 110;
		break;
	case 120: quarterNoteTime = 2440;
		currentTempo = 120;
		break;
	default: quarterNoteTime = 4882;
		currentTempo = 60;
		break;
	}
	MCF_PIT0_PMR = MCF_PIT_PMR_PM((unsigned short)quarterNoteTime);
	//enable
	MCF_PIT0_PCSR |= MCF_PIT_PCSR_EN;
	
}

void pit_off() {
	//clear PCSR0[0] EN bit
	MCF_PIT0_PCSR &= ~(0x0001);
}


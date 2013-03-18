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

void pit0_init(){
	
	MCF_PIT0_PCSR &= ~(MCF_PIT_PCSR_EN);
	MCF_PIT0_PCSR |= MCF_PIT_PCSR_RLD;
	MCF_PIT0_PCSR |= MCF_PIT_PCSR_PIF;
	MCF_PIT0_PCSR |= MCF_PIT_PCSR_PIE;
	MCF_PIT0_PCSR |= MCF_PIT_PCSR_OVW;
	MCF_PIT0_PCSR |= MCF_PIT_PCSR_DBG;
	MCF_PIT0_PCSR |= MCF_PIT_PCSR_PRE(13);
	
	currentTempo = 60;
	set_tempo(60);
	
	interupt_config(55, 1, 7, pit0_isr);
	
	//enable
	MCF_PIT0_PCSR |= MCF_PIT_PCSR_EN;
	
}

__declspec(interrupt) void pit0_isr(){
	/* Clear interrupt request flag. */
	MCF_PIT0_PCSR |= MCF_PIT_PCSR_PIF;

}

void set_note_length(int note_length){
	MCF_PIT0_PCSR &= ~MCF_PIT_PCSR_EN;
	
	
	timer = MCF_PIT0_PMR;
	
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
	
	
	//assign new value to PMR
	MCF_PIT0_PMR = MCF_PIT_PMR_PM((unsigned short)newTime);
	//enable
	MCF_PIT0_PCSR |= MCF_PIT_PCSR_EN;
	
}

void set_tempo(int tempo){
	
	//disable while configuring
	MCF_PIT0_PCSR &= ~MCF_PIT_PCSR_EN;
	
	if(tempo == 0)//set to currentTempo
		tempo = currentTempo;
		
	//set value of counter
	switch(tempo){
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


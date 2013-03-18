/*
 * pb.c
 *
 *  Created on: Feb 27, 2013
 *      Author: maserra3
 */

#include "pb.h"
#include "interupt.h"
#include "pit.h"

int tempo_count;
int current_beat;


void gpt_init(){
	//sets gpt chan 0 for input
	MCF_GPT_GPTIOS &= ~MCF_GPT_GPTIOS_IOS0;
	
	MCF_GPT_GPTCTL2 |= MCF_GPT_GPTCTL2_EDG0A;
	MCF_GPT_GPTCTL2 &= ~MCF_GPT_GPTCTL2_EDG0B;
	
	MCF_GPT_GPTDDR &= ~MCF_GPT_GPTDDR_DDRT0;
	
	MCF_GPT_GPTIE |= MCF_GPT_GPTIE_CI0;
	
	MCF_GPT_GPTSCR1 |= MCF_GPT_GPTSCR1_GPTEN;
	
	MCF_GPT_GPTFLG1 |= MCF_GPT_GPTFLG1_CF0;
	
	interupt_config(44, 1, 7, gpt0_isr);
	
	tempo_count = 0;
	current_beat = 60;
}

__declspec(interrupt) void gpt0_isr(){
	if(tempo_count)
		current_beat = current_beat - 10;
		//currentBeat = currentBeat - 5;
	else
		current_beat = current_beat + 10;
		//currentBeat = currentBeat + 5;
	
	
	if(current_beat == 60 || current_beat == 120)
		tempo_count = (~tempo_count) & 0x1;//switch direction
	
	
		set_tempo(current_beat);	
	
	/* set to clear the GPT channel 0 interrupt request flag. */
	MCF_GPT_GPTFLG1 |= MCF_GPT_GPTFLG1_CF0;
}
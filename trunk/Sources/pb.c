/*
 * pb.c
 *
 *  Created on: Feb 27, 2013
 *      Author: maserra3
 */

#include "pb.h"
#include "interupt.h"
#include "pit.h"
#include "gpio.h"


void gpt_init(){
	
	
	//sets gpt chan 0 for input
	MCF_GPT_GPTIOS &= ~MCF_GPT_GPTIOS_IOS0;
	
	MCF_GPT_GPTCTL2 |= MCF_GPT_GPTCTL2_EDG0A;
	MCF_GPT_GPTCTL2 &= ~MCF_GPT_GPTCTL2_EDG0B;
	
	MCF_GPT_GPTDDR &= ~MCF_GPT_GPTDDR_DDRT0;
	
	MCF_GPT_GPTIE |= MCF_GPT_GPTIE_CI0;
	
	MCF_GPT_GPTSCR1 |= MCF_GPT_GPTSCR1_GPTEN;
	
	MCF_GPT_GPTFLG1 |= MCF_GPT_GPTFLG1_CF0;
	
	
}

/*Source File:	pb.c
 *Project Name:	Project 4
 *Name:			Mario Serrano
 *Email:		maserra3@asu.edu
 *Course name:	CSE325 Embedded Microprocessor Systems
 *Semester:		Spring 2013
 */

#include "pb.h"
#include "interupt.h"
#include "pit.h"
#include "gpio.h"


void gpt_init(){
	
	gpio_port_ta_init();
	
	MCF_GPT_GPTIOS &= ~(0x1);
	
	MCF_GPT_GPTCTL2 &= 0xFC;
	
	MCF_GPT_GPTCTL2 |= 0x2;
	
	MCF_GPT_GPTFLG1 &= 0xE;
	
	MCF_GPT_GPTIE |= 0x1;
	
	MCF_GPT_GPTSCR1 |= 0x80;
	
	MCF_GPT_GPTDDR &= 0xE;
	
	
	
	/*
	//sets gpt chan 0 for input
	MCF_GPT_GPTIOS &= ~MCF_GPT_GPTIOS_IOS0;
	
	MCF_GPT_GPTCTL2 |= MCF_GPT_GPTCTL2_EDG0A;
	MCF_GPT_GPTCTL2 &= ~MCF_GPT_GPTCTL2_EDG0B;
	
	MCF_GPT_GPTDDR &= ~MCF_GPT_GPTDDR_DDRT0;
	
	MCF_GPT_GPTIE |= MCF_GPT_GPTIE_CI0;
	
	MCF_GPT_GPTSCR1 |= MCF_GPT_GPTSCR1_GPTEN;
	
	MCF_GPT_GPTFLG1 |= MCF_GPT_GPTFLG1_CF0;
	*/
	
}

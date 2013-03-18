/*Source File:	main.h
 *Project Name:	Project 4
 *Name:			Mario Serrano
 *Email:		maserra3@asu.edu
 *Course name:	CSE325 Embedded Microprocessor Systems
 *Semester:		Spring 2013
 */
#ifndef PIT_H_
#define PIT_H_

#include "support_common.h"
#include "interupt.h"

extern void pit0_init();
extern void set_note_length(int);

extern void set_tempo();
extern void pit_off();

extern __declspec(interrupt) void gpt0_isr();

#endif /* PIT_H_ */

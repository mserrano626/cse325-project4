/*
 * pit.h
 *
 *  Created on: Feb 27, 2013
 *      Author: maserra3
 */

#ifndef PIT_H_
#define PIT_H_

#include "support_common.h"
#include "interupt.h"

extern void pit0_init();
extern void set_note_length(int, int);
extern __declspec(interrupt) void pit0_isr();
extern void set_tempo(int);

#endif /* PIT_H_ */

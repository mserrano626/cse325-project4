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
extern void set_note_length(int);

extern void set_tempo();
extern void pit_off();


#endif /* PIT_H_ */

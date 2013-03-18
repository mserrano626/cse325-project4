/*
 * interupt.h
 *
 *  Created on: Feb 27, 2013
 *      Author: maserra3
 */

#ifndef INTERUPT_H_
#define INTERUPT_H_

#include "support_common.h"

typedef void (*isr_funct)(); //isr_funct is a type which is a pointer to a void function with no params

extern void interupt_config(int src, int level, int priority, isr_funct isr);
extern void interupt_unmask_src(int src);
extern asm __declspec(standard_abi) void int_uninhibit_all();
extern __declspec(interrupt) void pit0_isr();
extern __declspec(interrupt) void gpt0_isr();

#endif /* INTERUPT_H_ */

/*
 * pb.h
 *
 *  Created on: Feb 27, 2013
 *      Author: maserra3
 */

#ifndef PB_H_
#define PB_H_

#include "support_common.h"

extern void gpt_init();
extern __declspec(interrupt) void gpt0_isr();


#endif /* PB_H_ */

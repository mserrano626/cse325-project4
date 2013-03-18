/*Source File:	pwm.h
 *Project Name:	Project 4
 *Name:			Mario Serrano
 *Email:		maserra3@asu.edu
 *Course name:	CSE325 Embedded Microprocessor Systems
 *Semester:		Spring 2013
 */

#ifndef PWM_H_
#define PWM_H_

#include "support_common.h"

extern void init_pwm();
extern void set_pitch(int, int, int, int);

#endif /* PWM_H_ */

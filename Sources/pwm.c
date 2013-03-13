/*Source File:	pwm.c
 *Project Name:	Project 4
 *Name:			Mario Serrano
 *Email:		maserra3@asu.edu
 *Course name:	CSE325 Embedded Microprocessor Systems
 *Semester:		Spring 2013
 */

#include "pwm.h"

void init_pwm(){
	/*enables PWM7 which is connected to the speaker*/
	MCF_PWM_PWME = MCF_PWM_PWME_PWME7; 
	
	/*sets the polarity to start at 0*/
	MCF_PWM_PWMPOL = 0x00;
	
	/*sets pwm7 to clk SB*/
	MCF_PWM_PWMCLK = 0x80;
	
	/*sets channel 7 to left align*/
	MCF_PWM_PWMCAE = 0x00;
	
	/*sets channel 7 to have a seperate 8bit PWM*/
	MCF_PWM_PWMCTL = 0x00;
	
	/*Initializes controls for setting pitch*/
	MCF_PWM_PWMPRCLK = 0x0;
	MCF_PWM_PWMSCLB = 0x0;
	MCF_PWM_PWMPER7 = 0x0;
	MCF_PWM_PWMDTY7 = 0x0;
	
}

void set_pitch(int pre, int scale, int period, int duty){
	MCF_PWM_PWMPRCLK = pre;
	MCF_PWM_PWMSCLB = scale;
	MCF_PWM_PWMPER7 = period;
	MCF_PWM_PWMDTY7 = duty;
}

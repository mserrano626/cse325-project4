/*Source File:	main.c
 *Project Name:	Project 4
 *Name:			Mario Serrano
 *Email:		maserra3@asu.edu
 *Course name:	CSE325 Embedded Microprocessor Systems
 *Semester:		Spring 2013
 */


#include "support_common.h" /* include peripheral declarations and more */
#include "song.h"
#include "pwm.h"
#include "gpio.h"



__declspec(noreturn)int main(void)
{
	/*  proof that the speaker works */
	
	gpio_port_ta_init();
	init_pwm();
	
	while(1){
		
		play_song();
		
	}
}

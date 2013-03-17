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
#include "pit.h"
#include "led.h"



__declspec(noreturn)int main(void)
{
	/*  proof that the speaker works */
	
	gpio_port_ta_init();
	init_pwm();
	pit0_init();
	int_uninhibit_all();
	uc_led_init();
	
	
	while(1){
		play_song();
	}
}


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
#include "pb.h"



__declspec(noreturn)int main(void)
{
	/*  proof that the speaker works */
	gpio_port_tc_init();
	gpio_port_ta_init();
	init_pwm();
	uc_led_init();
	gpt_init();
	pit0_init();
	interupt_config(44, 1, 7, gpt0_isr);
	interupt_config(55, 4, 6, pit0_isr);
	int_uninhibit_all();
	play_song();
	while(1){}
}


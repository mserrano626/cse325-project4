/* FILENAME: gpio.c
 * ASSIGNMENT: Lab Project 4
 * NAME: Mario Serrano
 * EMAIL: maserra3@asu.edu
 * CLASS: CSE325 Embedded Microprocessor Systems
 * SEMESTER: Spring 2013
 */

#include "gpio.h"


int gpio_port_tc_get_pin_state(int p_pin){
	/*Accesses the SETTC register and returns 
	 * the state of pin p_pin (0 or 1).*/

	return (MCF_GPIO_SETTC & (1 << p_pin)) >> p_pin;
}

void gpio_port_tc_init(){
		/*Configures PTCPAR and DDRTC so port TC is in GPIO 
		 * function and the pin data direction is output.*/
	MCF_GPIO_PTCPAR = MCF_GPIO_PTCPAR_PTCPAR0(MCF_GPIO_PTCPAR_DTIN0_GPIO)| 
			MCF_GPIO_PTCPAR_PTCPAR1(MCF_GPIO_PTCPAR_DTIN1_GPIO) |
			MCF_GPIO_PTCPAR_PTCPAR2(MCF_GPIO_PTCPAR_DTIN2_GPIO) |
			MCF_GPIO_PTCPAR_PTCPAR3(MCF_GPIO_PTCPAR_DTIN3_GPIO);
	
	MCF_GPIO_PORTTC &=  ~(MCF_GPIO_DDRTC_DDRTC0 | 
	        MCF_GPIO_DDRTC_DDRTC1 | 
	        MCF_GPIO_DDRTC_DDRTC2 | 
	        MCF_GPIO_DDRTC_DDRTC3);
	
	MCF_GPIO_DDRTC = MCF_GPIO_DDRTC_DDRTC0 |
			MCF_GPIO_DDRTC_DDRTC1 |
			MCF_GPIO_DDRTC_DDRTC2 |
			MCF_GPIO_DDRTC_DDRTC3;

}


void gpio_port_tc_set_pin_state(int p_pin, int p_state){

	/*Accesses the SETTC register to set the state of pin
	 *  p_pin to p_state.*/
	MCF_GPIO_PORTTC = (MCF_GPIO_PORTTC & ~(1 << p_pin)) | (p_state << p_pin);
	
}

void gpio_port_ta_init(){
	MCF_GPIO_PTAPAR = MCF_GPIO_PTAPAR_PTAPAR0(1) |
			MCF_GPIO_PTAPAR_PTAPAR3(3);
	
	
	MCF_GPIO_PORTTA &=  ~(MCF_GPIO_DDRTA_DDRTA0 | 
		        MCF_GPIO_DDRTA_DDRTA3);
	
	MCF_GPIO_DDRTA = MCF_GPIO_DDRTA_DDRTA0 |
				MCF_GPIO_DDRTA_DDRTA3;
	
}

void gpio_port_ta_set_pin_state(int p_pin, int p_state){

	/*Accesses the SETTAregister to set the state of pin
	 *  p_pin to p_state.*/
	MCF_GPIO_PORTTA = (MCF_GPIO_PORTTA & ~(1 << p_pin)) | (p_state << p_pin);
	
}

int gpio_port_ta_get_pin_state(int p_pin){
	/*Accesses the SETTA register and returns 
	 * the state of pin p_pin (0 or 1).*/

	return (MCF_GPIO_SETTA & (1 << p_pin)) >> p_pin;
}
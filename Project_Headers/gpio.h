/* FILENAME: gpio.h
 * ASSIGNMENT: Lab Project 4
 * NAME: Mario Serrano
 * EMAIL: maserra3@asu.edu
 * CLASS: CSE325 Embedded Microprocessor Systems
 * SEMESTER: Spring 2013
 */
#ifndef GPIO_H
#define GPIO_H

#include "MCF52259.h"


extern int gpio_port_tc_get_pin_state(int p_pin);
extern void gpio_port_tc_init();
extern void gpio_port_tc_set_pin_state(int p_pin, int p_state);
extern void gpio_port_ta_init();
extern void gpio_port_ta_set_pin_state(int p_pin, int p_state);
extern int gpio_port_ta_get_pin_state(int p_pin);


#endif

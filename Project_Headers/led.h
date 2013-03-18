/* FILENAME: led.h
 * ASSIGNMENT: Lab Project 4
 * NAME: Mario Serrano
 * EMAIL: maserra3@asu.edu
 * CLASS: CSE325 Embedded Microprocessor Systems
 * SEMESTER: Spring 2013
 */
#ifndef UC_LED_H
#define UC_LED_H

#include "MCF52259.h"
#include "gpio.h"

extern void uc_led_all_off();
extern void uc_led_all_on();
extern void uc_led_all_toggle();
extern void uc_led_init();
extern void uc_led_off(int p_led);
extern void uc_led_on(int p_led);
extern void uc_led_toggle(int p_led);

#endif
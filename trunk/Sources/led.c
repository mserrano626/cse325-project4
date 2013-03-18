/* FILENAME: led.c
 * ASSIGNMENT: Lab Project 4
 * NAME: Mario Serrano
 * EMAIL: maserra3@asu.edu
 * CLASS: CSE325 Embedded Microprocessor Systems
 * SEMESTER: Spring 2013
 */

#include "led.h"

void uc_led_all_off(){
        uc_led_off(1);
        uc_led_off(2);
        uc_led_off(3);
        uc_led_off(4);
}

void uc_led_all_on(){
        uc_led_on(1);
        uc_led_on(2);
        uc_led_on(3);
        uc_led_on(4);
}

void uc_led_all_toggle(){
        uc_led_toggle(1);
        uc_led_toggle(2);
        uc_led_toggle(3);
        uc_led_toggle(4);
}

void uc_led_init(){
        gpio_port_tc_init();



}

void uc_led_off(int p_led){
        int pin = p_led - 1;

        gpio_port_tc_set_pin_state(pin, 0);
}


void uc_led_on(int p_led){
        int pin = p_led - 1;

        gpio_port_tc_set_pin_state(pin, 1);
}

void uc_led_toggle(int p_led){
        int pin = p_led-1;
        gpio_port_tc_set_pin_state(pin, !gpio_port_tc_get_pin_state(pin));



}

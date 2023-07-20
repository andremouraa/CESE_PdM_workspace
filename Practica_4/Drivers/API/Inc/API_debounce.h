/*
 * API_debounce.h
 *
 *  Created on: 13 de jul de 2023
 *      Author: André Fernandes
 */

#ifndef API_API_DELAY_H_
#define API_API_DELAY_H_
#endif /* API_API_DELAY_H_ */


//Include standard libraries
#include <stdint.h>
#include <stdbool.h>
#include "stm32f4xx_hal.h"  		/* <- HAL include */
#include "stm32f4xx_nucleo_144.h" 	/* <- BSP include */
#include "API_delay.h"

//Define enumeration with states of the State Machine

typedef enum{
	BUTTON_UP,
	BUTTON_FALLING,
	BUTTON_DOWN,
	BUTTON_RISING,
} debounceState_t;

//Define functions

void debounceFSM_init();
void debounceFSM_update();
bool_t readKey();

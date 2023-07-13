/*
 * API_delay.h
 *
 *  Created on: 06 de jul de 2023
 *      Author: André Fernandes
 */

#ifndef API_API_DELAY_H_
#define API_API_DELAY_H_
#endif /* API_API_DELAY_H_ */


//Include standard libraries
#include <stdint.h>
#include <stdbool.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_nucleo_144.h"

//Define typedefs
typedef uint32_t tick_t;
typedef bool bool_t;

typedef struct{
   tick_t startTime;
   tick_t duration;
   bool_t running;
} delay_t;


//Define functions
void delayInit( delay_t * delay, tick_t duration );
bool_t delayRead( delay_t * delay );
void delayWrite( delay_t * delay, tick_t duration );

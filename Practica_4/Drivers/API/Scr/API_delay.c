/*
 * API_delay.c
 *
 *  Created on: 6 de jul de 2023
 *      Author: André Fernandes
 */

#include "API_delay.h"

/*Define functions*/

/**
 * Function: delayInit
 *
 * Initialize a struct of a timer with the delay passed by the user
 * 
 * @param delay_t Struct with the timer's information
 * @param duration Delay time to be set 
 * */


void delayInit( delay_t * delay, tick_t duration )
{
	  delay->duration = duration;
	  delay->running = false;
	  delay->startTime = 0;
}


/**
 * Function: delayRead
 *
 * Receiver a pointer to struct delay_t type and
 * check if the timer is running and then perform actions.
 * If the timer is not running, store the actual time and then starts the timer.
 * If the time is already running, check if the the time already elapsed.
 *
 * @param delay_t Struct with the timer's information
 * @return If the timer is elapsed returns true and if don't returns false
 * */

bool_t delayRead( delay_t * delay )
{
	  if(delay->running == false)
	  {
		  delay->startTime = HAL_GetTick();
		  delay->running = true;
		  return false;
	  }
	  else
	  {
		  if((HAL_GetTick() - delay->startTime) >= delay->duration)
		  {
			  delay->running = false;
			  return true;
		  }
		  else
		  {
			  return false;
		  }
	  }
}


/**
 * Function: delayWrite
 *
 * Receiver a pointer to struct delay_t type and a value of delay
 * The function set a new duration value to the timers

 * @param delay_t Struct with the timer's information
 * @param duration Delay time to be set
 
 * @param delay_t Struct with the timer's information
 * @param duration Delay time to be set 
 * */

void delayWrite( delay_t * delay, tick_t duration )
{
	if (duration >= 0)
	{
	 delay->duration = duration;
	}
}

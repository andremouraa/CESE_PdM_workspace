/*
 * API_debounce.c
 *
 *  Created on: 13 de jul de 2023
 *      Author: André Fernandes
 */

#include "API_debounce.h"


#define DEBOUNCE_DELAY 40


debounceState_t debounceState;
uint8_t buttonState;
delay_t delayButton;



/**
 * Function: debounceFSM_init
 *
 * This function reads the current status of the button
 * and starts the State Machine with this state
 *
 * */

void debounceFSM_init()
{
	/* Initialize BSP PB for BUTTON_USER */
	BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO);

	/*Read the initial state */

	if (!BSP_PB_GetState(BUTTON_USER))
	{
		debounceState = BUTTON_UP;
	}
	else
	{
		debounceState = BUTTON_DOWN;
	}
}


/**
 * Function: debounceFSM_init
 *
 * This function is a State Machine that detects the change of state
 * and set a timer, after the time is elapsed the state of the button
 * is checked again and make the transitions
 *
 * */

void debounceFSM_update()
{
	switch (debounceState)
	{

	case BUTTON_UP:
		if(BSP_PB_GetState(BUTTON_USER))
		{
			delayInit(&delayButton,DEBOUNCE_DELAY);
			debounceState = BUTTON_FALLING;
		}

		break;

	case BUTTON_FALLING:

		if(delayRead(&delayButton))
		{
			if(BSP_PB_GetState(BUTTON_USER))
			{
				debounceState = BUTTON_DOWN;
				buttonState = 1;
			}
			else
			{
				debounceState = BUTTON_UP;
			}
		}

		break;

	case BUTTON_DOWN:

		if(BSP_PB_GetState(BUTTON_USER))
		{
			delayInit(&delayButton,DEBOUNCE_DELAY);
			debounceState = BUTTON_RISING;
		}

		break;


	case BUTTON_RISING:

		if(delayRead(&delayButton))
		{
			if(!BSP_PB_GetState(BUTTON_USER))
			{
				debounceState = BUTTON_UP;
				buttonState = 0;
			}
			else
			{
				debounceState = BUTTON_DOWN;
			}
		}

		break;
	}

}

/**
 * Function: debounceFSM_init
 *
 * This returns true or false if detects that the button was pressed
 *
 * @return Returns true if the button was pressed and false if it wasn't
 *
 * */

bool_t readKey()
{
	if (buttonState == 1)
	{
		buttonState = 0;
		return true;
	}
	else
	{
		return false;
	}
};

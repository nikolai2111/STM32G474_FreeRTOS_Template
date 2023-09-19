/**
 ******************************************************************************
 * Source		: FreeRTOS Hooks
 ******************************************************************************
 * @file		: hooks.c
 * @brief		: Main program body
 * @author		: N. Zoller (NZ)
 * @date		: 18.09.2023
 ******************************************************************************
 * @remark		: Last Modifications:
 * 				- none
 ******************************************************************************
 */

/* Includes -----------------------------------------------------------------*/
#include "main.h"

/* Private typedef ----------------------------------------------------------*/

/* Private define -----------------------------------------------------------*/

/* Private macro ------------------------------------------------------------*/

/* Private variables --------------------------------------------------------*/

/* Private function prototypes ----------------------------------------------*/

/* Private user code --------------------------------------------------------*/

/**
 * @brief		Malloc falied hook
 *
 * @param		None
 * @return		None
 *
 * @detail		Call Error_Handler() if malloc failed.
 *
 * @author		N. Zoller (NZ)
 * @date		18.09.2023
 * @remark		Last Modifications:
 * 				- none
 *****************************************************************************/
void vApplicationMallocFailedHook(void)
{
	Error_Handler();
}

/**
 * @brief		Configure RunTime Stats Timer
 *
 * @param		None
 * @return		None
 *
 * @author		N. Zoller (NZ)
 * @date		19.09.2023
 * @remark		Last Modifications:
 * 				- none
 *****************************************************************************/
void configureTimerForRunTimeStats(void)
{
	ulHighFrequencyTimerTicks = 0;
	HAL_TIM_Base_Start_IT(&htim17);
}

/**
 * @brief		Get value from RunTime Stats Timer
 *
 * @param		None
 * @return		unsigned long	Timer ticks, elapsed time
 *
 * @author		N. Zoller (NZ)
 * @date		19.09.2023
 * @remark		Last Modifications:
 * 				- none
 *****************************************************************************/
unsigned long getRunTimeCounterValue(void)
{
	return ulHighFrequencyTimerTicks;
}

/**
 ******************************************************************************
 * End Source	: FreeRTOS Hooks
 ******************************************************************************
 */

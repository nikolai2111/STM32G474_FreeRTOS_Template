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
 * 				- 12.12.23	NZ	Mod: Moved hardware out of the main.h.
 ******************************************************************************
 */

/* Includes -----------------------------------------------------------------*/
#include "main.h"

/* Hardware */
#include "tim.h"

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
#ifdef DEBUG
	ulHighFrequencyTimerTicks = 0;
#endif /* DEBUG */

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
#ifdef DEBUG
	return ulHighFrequencyTimerTicks;
#else
	return 0;
#endif /* DEBUG */
}

/**
 ******************************************************************************
 * End Source	: FreeRTOS Hooks
 ******************************************************************************
 */

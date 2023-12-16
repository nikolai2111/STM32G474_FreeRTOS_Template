/**
 ******************************************************************************
 * Source		: Interrupt Service Routines
 ******************************************************************************
 * @file		: stm32g4xx_it.c
 * @brief		: Contains the interrupt service routines.
 * @author		: N. Zoller (NZ)
 * @date		: 18.09.2023
 ******************************************************************************
 * @remark		: Last Modifications:
 * 				- 18.09.23	NZ	Mod: Implemented the error handling procedure
 * 								and turn on the error LED.
 * 				- 12.12.23	NZ	Mod: Moved hardware out of the main.h.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_it.h"

/* Private typedef ----------------------------------------------------------*/

/* Private define -----------------------------------------------------------*/

/* Private macro ------------------------------------------------------------*/

/* Private variables --------------------------------------------------------*/

/* Private function prototypes ----------------------------------------------*/

/* External functions -------------------------------------------------------*/

/* Private user code --------------------------------------------------------*/

/*****************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers         */
/*****************************************************************************/

/**
 * @brief		This function handles Non maskable interrupt.
 *
 * @param		None
 * @return		None
 *
 * @author		STMicroelectronics
 * @remark		Last Modifications:
 * 				- 18.09.23	NZ	Mod: Implemented the error handling procedure
 * 				and turn on the error LED.
 *****************************************************************************/
void NMI_Handler(void)
{
	while (true)
	{
		HAL_GPIO_WritePin(ERROR_LED_PORT, ERROR_LED_PIN, GPIO_PIN_SET);
	}
}

/**
 * @brief		This function handles Hard fault interrupt.
 *
 * @param		None
 * @return		None
 *
 * @author		STMicroelectronics
 * @remark		Last Modifications:
 * 				- 18.09.23	NZ	Mod: Implemented the error handling procedure
 * 				and turn on the error LED.
 *****************************************************************************/
void HardFault_Handler(void)
{
	while (true)
	{
		HAL_GPIO_WritePin(ERROR_LED_PORT, ERROR_LED_PIN, GPIO_PIN_SET);
	}
}

/**
 * @brief		This function handles Memory management fault.
 *
 * @param		None
 * @return		None
 *
 * @author		STMicroelectronics
 * @remark		Last Modifications:
 * 				- 18.09.23	NZ	Mod: Implemented the error handling procedure
 * 				and turn on the error LED.
 *****************************************************************************/
void MemManage_Handler(void)
{
	while (true)
	{
		HAL_GPIO_WritePin(ERROR_LED_PORT, ERROR_LED_PIN, GPIO_PIN_SET);
	}
}

/**
 * @brief		This function handles Prefetch fault, memory access fault.
 *
 * @param		None
 * @return		None
 *
 * @author		STMicroelectronics
 * @remark		Last Modifications:
 * 				- 18.09.23	NZ	Mod: Implemented the error handling procedure
 * 				and turn on the error LED.
 *****************************************************************************/
void BusFault_Handler(void)
{
	while (true)
	{
		HAL_GPIO_WritePin(ERROR_LED_PORT, ERROR_LED_PIN, GPIO_PIN_SET);
	}
}

/**
 * @brief		This function handles Undefined instruction or illegal state.
 *
 * @param		None
 * @return		None
 *
 * @author		STMicroelectronics
 * @remark		Last Modifications:
 * 				- 18.09.23	NZ	Mod: Implemented the error handling procedure
 * 				and turn on the error LED.
 *****************************************************************************/
void UsageFault_Handler(void)
{
	while (true)
	{
		HAL_GPIO_WritePin(ERROR_LED_PORT, ERROR_LED_PIN, GPIO_PIN_SET);
	}
}

/**
 * @brief		This function handles Debug monitor.
 *
 * @param		None
 * @return		None
 *
 * @author		STMicroelectronics
 * @remark		Last Modifications:
 * 				- none
 *****************************************************************************/
void DebugMon_Handler(void)
{
}

/**
 * @brief		This function handles System tick timer.
 *
 * @param		None
 * @return		None
 *
 * @author		STMicroelectronics
 * @remark		Last Modifications:
 * 				- none
 *****************************************************************************/
void SysTick_Handler(void)
{
	HAL_IncTick();
#if (INCLUDE_xTaskGetSchedulerState == 1 )
	if (xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED)
	{
#endif /* INCLUDE_xTaskGetSchedulerState */
		xPortSysTickHandler();
#if (INCLUDE_xTaskGetSchedulerState == 1 )
	}
#endif /* INCLUDE_xTaskGetSchedulerState */
}

/******************************************************************************/
/* STM32G4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32g4xx.s).                    */
/******************************************************************************/

/**
 * @brief		This function handles the TIM17 interrupt.
 *
 * @param		None
 * @return		None
 *
 * @details		This function handles TIM1 trigger and commutation interrupts
 * 				and TIM17 global interrupt. Which is used for the Run Time
 * 				Statistics.
 *
 * @author		STMicroelectronics
 * @remark		Last Modifications:
 * 				- 19.09.23	NZ	Add: RunTime Statistics
 *****************************************************************************/
void TIM1_TRG_COM_TIM17_IRQHandler(void)
{

#ifdef DEBUG
	// Counts up FreeRTOS RunTime Statistics ticks
	ulHighFrequencyTimerTicks++;
#endif /* DEBUG */

	HAL_TIM_IRQHandler(&htim17);
}

/**
 ******************************************************************************
 * End Source	: Interrupt Service Routines
 ******************************************************************************
 */

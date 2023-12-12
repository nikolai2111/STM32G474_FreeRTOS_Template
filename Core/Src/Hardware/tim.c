/**
 ******************************************************************************
 * Source		: Timer Configuration
 ******************************************************************************
 * @file		: tim.c
 * @brief		: Contains the configuration for the timers.
 * @author		: N. Zoller (NZ)
 * @date		: 12.12.2023
 ******************************************************************************
 * @remark		: Last Modifications:
 * 				- none
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

/* Includes -----------------------------------------------------------------*/
#include "tim.h"
/* Private typedef ----------------------------------------------------------*/

/* Private define -----------------------------------------------------------*/

/* Private macro ------------------------------------------------------------*/

/* Private variables --------------------------------------------------------*/
TIM_HandleTypeDef htim17;

/* Private function prototypes ----------------------------------------------*/

/* External functions -------------------------------------------------------*/

/* Private user code --------------------------------------------------------*/

/**
 * @brief		This function initialized the timer 17.
 *
 * @param		None
 * @return		None
 *
 * @author		STMicroelectronics
 * @remark		Last Modifications:
 * 				- none
 *****************************************************************************/
void MX_TIM17_Init(void)
{
	htim17.Instance = TIM17;
	htim17.Init.Prescaler = 0;
	htim17.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim17.Init.Period = 2400;
	htim17.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim17.Init.RepetitionCounter = 0;
	htim17.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim17) != HAL_OK)
	{
		Error_Handler();
	}
}

/**
 * @brief		This function initialized the timers on the use MCU.
 *
 * @param		None
 * @return		None
 *
 * @author		STMicroelectronics
 * @remark		Last Modifications:
 * 				- none
 *****************************************************************************/
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *tim_baseHandle)
{

	if (tim_baseHandle->Instance == TIM17)
	{
		/* TIM17 clock enable */
		__HAL_RCC_TIM17_CLK_ENABLE();

		/* TIM17 interrupt Init */
		HAL_NVIC_SetPriority(TIM1_TRG_COM_TIM17_IRQn, 5, 0);
		HAL_NVIC_EnableIRQ(TIM1_TRG_COM_TIM17_IRQn);
	}
}

/**
 * @brief		This function de-initialized the timers on the use MCU.
 *
 * @param		None
 * @return		None
 *
 * @author		STMicroelectronics
 * @remark		Last Modifications:
 * 				- none
 *****************************************************************************/
void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef *tim_baseHandle)
{

	if (tim_baseHandle->Instance == TIM17)
	{
		/* Peripheral clock disable */
		__HAL_RCC_TIM17_CLK_DISABLE();

		/* TIM17 interrupt Deinit */
		HAL_NVIC_DisableIRQ(TIM1_TRG_COM_TIM17_IRQn);
	}
}

/**
 ******************************************************************************
 * End Source	: Timer Configuration
 ******************************************************************************
 */

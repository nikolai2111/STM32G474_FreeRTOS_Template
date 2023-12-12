/**
 ******************************************************************************
 * Source		: GPIO Configuration
 ******************************************************************************
 * @file		: gpio.c
 * @brief		: Contains the configuration for the gpios.
 * @author		: N. Zoller (NZ)
 * @date		: 18.09.2023
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
#include "gpio.h"

/* Private typedef ----------------------------------------------------------*/

/* Private define -----------------------------------------------------------*/

/* Private macro ------------------------------------------------------------*/

/* Private variables --------------------------------------------------------*/

/* Private function prototypes ----------------------------------------------*/

/* External functions -------------------------------------------------------*/

/* Private user code --------------------------------------------------------*/

/**
 * @brief		This function is executed in case of error occurrence.
 *
 * @param		None
 * @return		None
 *
 * @author		STMicroelectronics
 * @remark		Last Modifications:
 * 				- none
 *****************************************************************************/
void MX_GPIO_Init(void)
{

	GPIO_InitTypeDef GPIO_InitStruct =
	{ 0 };

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOF_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	/* Configure error led pin Output Level */
	HAL_GPIO_WritePin(ERROR_LED_PORT, ERROR_LED_PIN, GPIO_PIN_RESET);

	/* Configure error led pin : PA5 on the Nucelo-Board */
	GPIO_InitStruct.Pin = ERROR_LED_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(ERROR_LED_PORT, &GPIO_InitStruct);
}

/**
 ******************************************************************************
 * End Source	: GPIO Configuration
 ******************************************************************************
 */

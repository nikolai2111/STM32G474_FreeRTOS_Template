/**
 ******************************************************************************
 * Source		: HAL MSP
 ******************************************************************************
 * @file		: stm32g4xx_hal_msp.c
 * @brief		: This file provides code for the MSP Initialization
 * 				and de-Initialization codes.
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
#include "main.h"

/* Private typedef ----------------------------------------------------------*/

/* Private define -----------------------------------------------------------*/

/* Private macro ------------------------------------------------------------*/

/* Private variables --------------------------------------------------------*/

/* Private function prototypes ----------------------------------------------*/

/* External functions -------------------------------------------------------*/

/* Private user code --------------------------------------------------------*/

/**
 * @brief		Initializes the Global MSP.
 *
 * @param		None
 * @return		None
 *
 * @author		STMicroelectronics
 * @remark		Last Modifications:
 * 				- none
 *****************************************************************************/
void HAL_MspInit(void)
{
	__HAL_RCC_SYSCFG_CLK_ENABLE();
	__HAL_RCC_PWR_CLK_ENABLE();

	/* System interrupt init*/
	/* PendSV_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(PendSV_IRQn, 15, 0);
}

/**
 ******************************************************************************
 * End Source	: HAL MSP
 ******************************************************************************
 */

/**
 ******************************************************************************
 * Header		: Main
 ******************************************************************************
 * @file		: main.h
 * @brief		: Header for main.c file.
 * @author		: N. Zoller (NZ)
 * @date		: 07.09.2023
 ******************************************************************************
 * @remark		: Last Modifications:
 * 				- 12.12.23	NZ	Mod: Cleaned up file.
 ******************************************************************************
 * @todo		:	- Change the port and pin of the error led
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

/* Define to prevent recursive inclusion ------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -----------------------------------------------------------------*/
#include <stdbool.h>

/* STM32 HAL */
#include "stm32g4xx_hal.h"

/* Tool Boxes */
#include "putchar_getchar_redirect.h"

/* Exported types -----------------------------------------------------------*/

/* Exported constants -------------------------------------------------------*/

/* Exported macro -----------------------------------------------------------*/
#define ERROR_LED_PORT	GPIOA
#define ERROR_LED_PIN	GPIO_PIN_5

/* Exported variables -------------------------------------------------------*/
#ifdef DEBUG
extern volatile unsigned long ulHighFrequencyTimerTicks;
#endif /* DEBUG */

/* Exported functions prototypes --------------------------------------------*/
void Error_Handler(void);

/* Private defines ----------------------------------------------------------*/


#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/**
 ******************************************************************************
 * End Header	: Main
 ******************************************************************************
 */

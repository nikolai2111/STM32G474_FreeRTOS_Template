/**
 ******************************************************************************
 * Header		: GPIO Configuration
 ******************************************************************************
 * @file		: gpio.h
 * @brief		: Header for gpio.c file.
 * @author		: N. Zoller (NZ)
 * @date		: 18.09.2023
 ******************************************************************************
 * @remark		: Last Modifications:
 * 				- 12.12.23	NZ	Mod: Cleaned up file.
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
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -----------------------------------------------------------------*/
#include "main.h"

/* Exported types -----------------------------------------------------------*/

/* Exported constants -------------------------------------------------------*/

/* Exported macro -----------------------------------------------------------*/

/* Exported variables -------------------------------------------------------*/

/* Exported functions prototypes --------------------------------------------*/
void MX_GPIO_Init(void);

/* Private defines ----------------------------------------------------------*/

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

/**
 ******************************************************************************
 * End Header	: GPIO Configuration
 ******************************************************************************
 */

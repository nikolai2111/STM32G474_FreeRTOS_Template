/**
 ******************************************************************************
 * Header		: Timer Configuration
 ******************************************************************************
 * @file		: tim.h
 * @brief		: Header for tim.c file.
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

/* Define to prevent recursive inclusion ------------------------------------*/
#ifndef __TIM_H__
#define __TIM_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -----------------------------------------------------------------*/
#include "main.h"

/* Exported types -----------------------------------------------------------*/

/* Exported constants -------------------------------------------------------*/

/* Exported macro -----------------------------------------------------------*/

/* Exported variables -------------------------------------------------------*/
extern TIM_HandleTypeDef htim17;

/* Exported functions prototypes --------------------------------------------*/
void MX_TIM17_Init(void);


/* Private defines ----------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __TIM_H__ */

/**
 ******************************************************************************
 * End Header	: Timer Configuration
 ******************************************************************************
 */

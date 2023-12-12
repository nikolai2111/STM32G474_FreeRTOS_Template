/**
 ******************************************************************************
 * Header		: USART Configuration
 ******************************************************************************
 * @file		: usart.h
 * @brief		: Header for usart.c file.
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
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -----------------------------------------------------------------*/
#include "main.h"

/* Exported types -----------------------------------------------------------*/

/* Exported constants -------------------------------------------------------*/

/* Exported macro -----------------------------------------------------------*/

/* Exported variables -------------------------------------------------------*/
extern UART_HandleTypeDef hlpuart1;

/* Exported functions prototypes --------------------------------------------*/
void MX_LPUART1_UART_Init(void);

/* Private defines ----------------------------------------------------------*/


#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

/**
 ******************************************************************************
 * End Header	: USART Configuration
 ******************************************************************************
 */

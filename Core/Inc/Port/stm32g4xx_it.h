/**
 ******************************************************************************
 * Header		: Interrupt Service Routines
 ******************************************************************************
 * @file		: stm32g4xx_it.h
 * @brief		: Contains the interrupt service routines.
 * @author		: N. Zoller (NZ)
 * @date		: 18.09.2023
 ******************************************************************************
 * @remark		: Last Modifications:
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

/* Define to prevent recursive inclusion ------------------------------------*/
#ifndef __STM32G4xx_IT_H
#define __STM32G4xx_IT_H

#ifdef __cplusplus
 extern "C" {
#endif

 /* Includes -----------------------------------------------------------------*/
#include "main.h"

 /* Hardware */
 #include "tim.h"

 /* FreeRTOS */
 #include "FreeRTOS.h"
 #include "task.h"

 /* Exported types -----------------------------------------------------------*/

 /* Exported constants -------------------------------------------------------*/

 /* Exported macro -----------------------------------------------------------*/

 /* Exported functions prototypes --------------------------------------------*/
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void DebugMon_Handler(void);
void SysTick_Handler(void);

/* Private defines ----------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __STM32G4xx_IT_H */

 /**
  ******************************************************************************
  * End Header	: Interrupt Service Routines
  ******************************************************************************
  */

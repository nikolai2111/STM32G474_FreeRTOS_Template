/**
 ******************************************************************************
 * Source		: Error Handlers
 ******************************************************************************
 * @file		: error_handler.c
 * @brief		: Contains the error handlers and assert functions.
 * @author		: N. Zoller (NZ)
 * @date		: 13.09.2023
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

/* External functions --------------------------------------------------------*/

/* Private user code --------------------------------------------------------*/

/**
 * @brief		This function is executed in case of error occurrence.
 *
 * @param		None
 * @return		None
 *
 * @author		STMicroelectronics
 * @remark		Last Modifications:
 * 				- 15.09.23	NZ	Mod: Implemented the error handling procedure
 * 				and flash the on board LED.
 *****************************************************************************/
void Error_Handler(void)
{
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (true)
	{
		HAL_GPIO_TogglePin(ERROR_LED_PORT, ERROR_LED_PIN);

		/**
		 * @note NOP is used because HAL_Delay is based on interrupts and does
		 * not work. So in the error state the CPU time does not matter. Led
		 * flashed with approx. 200Hz.
		 */
		for (unsigned long i = 0; i < 120000; i++)
		{
			asm("NOP");
		}
	}
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  	Reports the name of the source file and the source line number
  *         	where the assert_param error has occurred.
  * @param  	file:		pointer to the source file name
  * @param  	line: 		assert_param error line source number
  * @return 	None
  *
  * @author		STMicroelectronics
  * @remark		Last Modifications:
  * 				- none
  ****************************************************************************/
void assert_failed(uint8_t *file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
}

#endif /* USE_FULL_ASSERT */

/**
 ******************************************************************************
 * End Source	: Error Handlers
 ******************************************************************************
 */

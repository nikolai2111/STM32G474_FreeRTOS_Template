/**
 ******************************************************************************
 * Source		: Main
 ******************************************************************************
 * @file		: main.cpp
 * @brief		: Main program body
 * @author		: N. Zoller (NZ)
 * @date		: 07.09.2023
 ******************************************************************************
 * @remark		: Last Modifications:
 * 				- none
 ******************************************************************************
 * @todo		:	- none
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

/* C Includes ----------------------------------------------------------------*/
#include "main.h"

/* C++ Includes --------------------------------------------------------------*/
#include "FreeRTOS.hpp"
#include "Task.hpp"

/* Private namespaces --------------------------------------------------------*/
using namespace std::chrono_literals;

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

void DefaultTask_Runnable(void *pvParam);

/* Private Mutex(es) ---------------------------------------------------------*/

/* Private Semaphore(s) ------------------------------------------------------*/

/* Private Timer(s) ----------------------------------------------------------*/

/* Private Queue(s) ----------------------------------------------------------*/

/* Private task(s) -----------------------------------------------------------*/
Task DefaultTask = Task(DefaultTask_Runnable, "default Task", 1024, tskIDLE_PRIORITY);

/**
 * @brief		The application entry point.
 *
 * @param		None
 * @return		int
 *
 * @author		STMicroelectronics
 * @remark		Last Modifications:
 * 				- 12.09.23	NZ	Mod: Input arguments to argc and *argv
 *****************************************************************************/
int main(int argc, char *argv[])
{
	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* Configure the system clock */
	SystemClock_Config();

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_LPUART1_UART_Init();

	/**
	 * @note Disable internal buffering of the input stream to avoid unexpected
	 * behavior with scanf().
	 */
	setvbuf(stdin, NULL, _IONBF, 0);

	/* Create and configure Mutexes */

	/* Create and configure Semaphores */

	/* Create and configure Timers */

	/* Create and configure Queues */

	/* Create the task(s) */

	/* Start scheduler */
	FreeRTOS::startScheduler();

	/* We should never get here as control is now taken by the scheduler */
	while (true)
	{
	}
}

/**
 * @brief		System Default Task
 *
 * @param  		pvParameters:	Not used
 * @return 		None
 *
 * @details		Default task for this program.
 *
 * @author		N. Zoller (NZ)
 * @date		07.09.2023
 * @remark		Last Modifications:
 * 				- 12.09.23	NZ	Mod: Content to the FreeRTOS Wrappers
 *****************************************************************************/
void DefaultTask_Runnable(void *pvParam)
{
	char rx_buff[32];

	while (true)
	{
		/* Task code goes here. */
		printf("----------------------------------\n\r");
		printf("Enter your name: ");
		scanf("%31s", rx_buff);
		printf("\n\rHello %s...\n\r", rx_buff);

		DefaultTask.delay(FreeRTOS::convertToTicks(1s));
	}
}

/**
 * @brief		System Clock Configuration
 *
 * @param		None
 * @return		None
 *
 * @author		STMicroelectronics
 * @remark		Last Modifications:
 * 				- none
 *****************************************************************************/
void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/** Configure the main internal regulator output voltage
	 */
	HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
	{
		Error_Handler();
	}
}

/**
 ******************************************************************************
 * End Source	: Main
 ******************************************************************************
 */

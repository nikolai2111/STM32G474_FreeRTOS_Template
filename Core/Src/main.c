/**
 ******************************************************************************
 * Source		: Main
 ******************************************************************************
 * @file		: main.c
 * @brief		: Main program body
 * @author		: N. Zoller (NZ)
 * @date		: 07.09.2023
 ******************************************************************************
 * @remark		: Last Modifications:
 * 				- 19.09.23	NZ	Add: RunTime Statistics
 * 				- 19.09.23	NZ	Mod: Clock to use the external 24 MHz Crystal.
 * 				- 12.12.23	NZ	Mod: Internal clock to be 170 MHz.
 * 				- 12.12.23	NZ	Mod: Moved hardware out of the main.h.
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

/* Includes -----------------------------------------------------------------*/
#include "main.h"

/* Hardware */
#include "gpio.h"
#include "usart.h"
#include "tim.h"

/* FreeRTOS */
#include "FreeRTOS.h"
#include "task.h"

/* Private typedef ----------------------------------------------------------*/

/* Private define -----------------------------------------------------------*/

/* Private macro ------------------------------------------------------------*/

/* Private variables --------------------------------------------------------*/
TaskHandle_t xDefaultTask_Handle = NULL;

#ifdef DEBUG
volatile unsigned long ulHighFrequencyTimerTicks;
#endif /* DEBUG */

/* Private function prototypes ----------------------------------------------*/
void SystemClock_Config(void);

void vDefaultTask(void *pvParam);

/* Private user code --------------------------------------------------------*/

/**
 * @brief		The application entry point.
 *
 * @param		None
 * @return		int		exit code
 *
 * @author		STMicroelectronics
 * @remark		Last Modifications:
 * 				- 19.09.23	NZ	Add: RunTime Statistics
 *****************************************************************************/
int main(void)
{
	/* MCU Configuration ----------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* Configure the system clock */
	SystemClock_Config();

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_LPUART1_UART_Init();

#ifdef DEBUG
	MX_TIM17_Init();
#endif /* DEBUG */

	/**
	 * @note Disable internal buffering of the input stream to avoid unexpected
	 * behavior with scanf().
	 */
	setvbuf(stdin, NULL, _IONBF, 0);

	/* Create and configure Mutexes */

	/* Create and configure Semaphores */

	/* Create and configure Timers */

	/* Create and configure Queues */

	/* Create the thread(s) */
	/* definition and creation of defaultTask */
	xTaskCreate(vDefaultTask,	/* Function that implements the task. */
		"defaultTask",			/* Text name for the task. */
		2048,					/* Stack size in words, not bytes. */
		(void*) 1,				/* Parameter passed into the task. */
		tskIDLE_PRIORITY,		/* Priority at which the task is created. */
		&xDefaultTask_Handle);	/* Used to pass out the created task's handle. */

	/* Start scheduler */
	vTaskStartScheduler();

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
 * 				- none
 *****************************************************************************/
void vDefaultTask(void *pvParam)
{
	char rx_buff[32] = {0};

	while (true)
	{
		/* Task code goes here. */

		printf("----------------------------------\n\r");
		printf("Enter your name: ");
		//scanf("%31s", rx_buff);
		printf("\n\rHello %s...\n\r", rx_buff);

		vTaskDelay(1000);
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
 * 				- 19.09.23	NZ	Mod: Clock to use the external 24 MHz crystal
 * 								and the external 32.768 kHz crystal, they are
 * 								the default configuration on the nucleo-board.
 * 				- 12.12.23	NZ	Mod: Configured the internal clock to run on
 * 								the maximum speed of 170 MHz.
 *****************************************************************************/
void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/**
	 * Configure the main internal regulator output voltage
	 */
	HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);

	/**
	 * Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV6;
	RCC_OscInitStruct.PLL.PLLN = 85;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
	RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}

	/**
	 * Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
	{
		Error_Handler();
	}
}

/**
 ******************************************************************************
 * End Source	: Main
 ******************************************************************************
 */

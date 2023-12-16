/**
 ******************************************************************************
 * Source		: Redirect putchar / getchar
 ******************************************************************************
 * @file		: putchar_getchar_redirect.c
 * @brief		: Redirects the putchar and the getchar to use the HAL-library
 * @author		: N. Zoller (NZ)
 * @date		: 15.09.2023
 ******************************************************************************
 * @remark		: Last Modifications:
 * 				- 15.09.23	NZ	Mod: Split up in a source and header file
 ******************************************************************************
 * @attention
 * Source		: https://forum.digikey.com/t/easily-use-scanf-on-stm32/21103
 ******************************************************************************
 */

/* Includes -----------------------------------------------------------------*/
#include "putchar_getchar_redirect.h"

/* Private typedef ----------------------------------------------------------*/

/* Private define -----------------------------------------------------------*/
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#define GETCHAR_PROTOTYPE int __io_getchar(void)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#define GETCHAR_PROTOTYPE int fgetc(FILE *f)
#endif

/* Private macro ------------------------------------------------------------*/

/* Private variables --------------------------------------------------------*/

/* Private function prototypes ----------------------------------------------*/

/* External functions --------------------------------------------------------*/

/* Private user code --------------------------------------------------------*/

/**
 * @brief		Redirect putchar
 *****************************************************************************/
PUTCHAR_PROTOTYPE
{
	HAL_UART_Transmit(&hlpuart1, (uint8_t*) &ch, 1, HAL_MAX_DELAY);
	return ch;
}

/**
 * @brief		Redirect getchar
 *****************************************************************************/
GETCHAR_PROTOTYPE
{
	uint8_t ch = 0;

	/* Clear the Overrun flag just before receiving the first character */
	__HAL_UART_CLEAR_OREFLAG(&hlpuart1);

	/* Wait for reception of a character on the USART RX line and echo this
	 * character on console */
	HAL_UART_Receive(&hlpuart1, (uint8_t*) &ch, 1, HAL_MAX_DELAY);
	HAL_UART_Transmit(&hlpuart1, (uint8_t*) &ch, 1, HAL_MAX_DELAY);
	return ch;
}

/**
 ******************************************************************************
 * End Source	: Redirect putchar / getchar
 ******************************************************************************
 */

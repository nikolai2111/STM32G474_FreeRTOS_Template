/**
 ******************************************************************************
 * Source		: System Memory
 ******************************************************************************
 * @file		: sysmem.c
 * @brief		: STM32CubeIDE System Memory calls file
 * @detail		: For more information about which C functions need which of
 * 				these lowlevel functions please consult the newlib libc manual.
 *
 * @author		: STMicroelectronics
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

/* Includes */
#include <errno.h>
#include <stdint.h>

#include "main.h"

/**
 * Pointer to the current high watermark of the heap usage
 * @warning		Not used anymore.
 */
// static uint8_t *__sbrk_heap_end = NULL;

/**
 * @brief		Memory allocation to the newlib heap
 *
 * @param 		incr	Memory size
 * @return 		Pointer to allocated memory
 *
 * @detail		_sbrk() allocates memory to the newlib heap and is used by malloc
 * 				and others from the C library.
 *
 * 				@verbatim
 * 				############################################################################
 *				#  .data  #  .bss  #       newlib heap       #          MSP stack          #
 * 				#         #        #                         # Reserved by _Min_Stack_Size #
 * 				############################################################################
 * 				^-- RAM start      ^-- _end                             _estack, RAM end --^
 * 				@endverbatim
 *
 * 				This implementation starts allocating at the '_end' linker symbol
 * 				The '_Min_Stack_Size' linker symbol reserves a memory for the MSP stack
 * 				The implementation considers '_estack' linker symbol to be RAM end
 * 				NOTE: If the MSP stack, at any point during execution, grows larger than the
 * 				reserved size, please increase the '_Min_Stack_Size'.
 *
 * @warning		sbrk should not be used and is empty, because the FreeRTOS heap
 * 				should be used. malloc functions are redirected to the FreeRTOS
 * 				heap functions. When used the Erorr_handler() is called.
 *
 * @author		STMicroelectronics
 * @remark		Last Modifications:
 * 				- 13.09.23	NZ	Mod: Function content to return NULL and do
 * 								nothing.
 *
 * @todo		- Implement detection that sbrk was used.
 *****************************************************************************/
void* _sbrk(ptrdiff_t incr)
{
	Error_Handler();
	return NULL;

	/*
	 extern uint8_t _end; // Symbol defined in the linker script
	 extern uint8_t _estack; // Symbol defined in the linker script
	 extern uint32_t _Min_Stack_Size; // Symbol defined in the linker script
	 const uint32_t stack_limit = (uint32_t) &_estack
	 - (uint32_t) &_Min_Stack_Size;
	 const uint8_t *max_heap = (uint8_t*) stack_limit;
	 uint8_t *prev_heap_end;

	 // Initialize heap end at first call
	 if (NULL == __sbrk_heap_end)
	 {
	 __sbrk_heap_end = &_end;
	 }

	 // Protect heap from growing into the reserved MSP stack
	 if (__sbrk_heap_end + incr > max_heap)
	 {
	 errno = ENOMEM;
	 return (void*) -1;
	 }

	 prev_heap_end = __sbrk_heap_end;
	 __sbrk_heap_end += incr;

	 return (void*) prev_heap_end;

	 */
}

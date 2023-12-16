/**
 ******************************************************************************
 * Source		: NewLib Heap Override
 ******************************************************************************
 * @file		: newlib_heap_override.c
 * @brief		: Overrides the newlib standard heap functions like free.
 * @detail		: The newlib contains its own heap system, but FreeRTOS does
 * 				also have its own system and we do not want to have 2 heap
 * 				systems. The newlib would use the function _sbrk to allocate
 * 				memory from the space reserved in the linker script.
 * 				Unfortunately it gives it never back, even if the task gets
 * 				deleted.
 *
 * 				Therefore here are some replacement functions, which redirect
 * 				the memory allocation to the FreeRTOS heap system.
 *
 * 				If for example malloc is called, then it calls a fuction from
 * 				the newlib, but this will then redirect the call to _malloc_r,
 * 				which an additional pointer to the _reent pointer.
 * 				The data of this pointer is not being used here.
 *
 * 				The functions to be replaced have __wrap_ as prefix. It is
 * 				necessary to tell the linker to replace the original function
 * 				by using these functions here.
 *
 * 				Set these additional linker flags:
 * 				-Wl,--wrap=_malloc_r
 * 				-Wl,--wrap=_free_r
 * 				-Wl,--wrap=_realloc_r
 *
 * 				Not all functions have been replaced, because they are not used
 * 				currently.
 *
 * @author		: M. Luethi (ML)
 * @date		: 13.09.2023
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

/* Includes -----------------------------------------------------------------*/
/* Libraries */
#include <string.h>

/* FreeRTOS */
#include "FreeRTOS.h"

/* Private typedef ----------------------------------------------------------*/

/* Private define -----------------------------------------------------------*/

/* Private macro ------------------------------------------------------------*/

/* Private variables --------------------------------------------------------*/

/* Private function prototypes ----------------------------------------------*/

/* External functions --------------------------------------------------------*/

/* Private user code --------------------------------------------------------*/

/**
 * @brief		Wrapper for _malloc_r
 *
 * @param		reent_ptr
 * @param		free_p
 * @return		none
 *
 * @author		M. Luethi (ML)
 * @date		13.09.2023
 * @remark		Last Modifications:
 * 				- none
 *****************************************************************************/
void* __wrap__malloc_r(struct _reent *reent_ptr, size_t size)
{
	return pvPortMalloc(size);
}

/**
 * @brief		Wrapper for _free_r
 *
 * @param		reent_ptr
 * @param		free_p
 * @return		none
 *
 * @author		M. Luethi (ML)
 * @date		13.09.2023
 * @remark		Last Modifications:
 * 				- none
 *****************************************************************************/
void __wrap__free_r(struct _reent *reent_ptr, void *free_p)
{
	vPortFree(free_p);
}

/**
 * @brief		Wrapper for _realloc_r
 *
 * @param		reent_ptr
 * @param		free_p
 * @return		none
 *
 * @detail		This implementation is standard compatible, but not very good
 * 				optimized, because it does always allocates a new region and free
 * 				the old one.
 *
 * @author		M. Luethi (ML)
 * @date		13.09.2023
 * @remark		Last Modifications:
 * 				- none
 *****************************************************************************/
void* __wrap__realloc_r(struct _reent *reent_ptr, void *ptr, size_t size)
{
	if (ptr == NULL)
	{
		//Same function as malloc
		return pvPortMalloc(size);
	}

	if (size == 0)
	{
		//Same function as free
		vPortFree(ptr);
		return NULL;
	}

	//Because we do not know the size of the current allocated memory, we just allocate a new region with the
	//asked size and copy as many bytes from the original memory to the newly allocated.
	void *newRegion = pvPortMalloc(size);
	if (newRegion == NULL)
	{
		//Could not allocate more memory. The caller can still use the original pointer
		return NULL;
	}
	memcpy(newRegion, ptr, size);
	vPortFree(ptr); //free the old region. The caller is not allowed to use the old region
	return newRegion;
}

/**
 ******************************************************************************
 * End Source	: NewLib Heap Override
 ******************************************************************************
 */

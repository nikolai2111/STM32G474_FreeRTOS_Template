/*
 * hook.c
 *
 *  Created on: Sep 15, 2023
 *      Author: Nikolai.Zoller
 */

#include "main.h"

void vApplicationMallocFailedHook(void)
{
	Error_Handler();
}

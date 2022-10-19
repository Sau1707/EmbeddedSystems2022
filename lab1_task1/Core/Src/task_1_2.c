/*
 * Copyright (c) 2022, Swiss Federal Institute of Technology (ETH Zurich).
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors:  Philipp Miedl, Seonyeong Heo
 */

#include <stdint.h>                             // Standard Integer - data type definitions
#include <stdio.h>                              // Standard In-/Output definitions/functions

#include "lab1.h"                               // Lab specific defines/declarations

// These register base address and register address offsets can be found in the STM32U575/585
// Reference Manual Chapter 2 and Chapter 13.
//----------------defs0----------------
#define REGBASEADDR (0x42021C00UL)  // Base address of Port H configuration register
#define REGOFF_MODE (0x00000000UL)  // Address offset of the port mode register
#define REGOFF_OUTD (0x00000014UL)  // Address offset of output data register
//----------------defs1----------------

void task_1_2(void)
{
	uint32_t count = 0;                               // Simple counter variable

	// Enable GPIOH clock by setting the peripheral clock enable register
	__HAL_RCC_GPIOH_CLK_ENABLE();

	// Configure PH.6 by setting the mode to general purpose output mode (0b01).
	// The configuration information can be found in the STM32U575/585 Reference Manual
	// Chapter 13.
	// *((volatile uint32_t*)(REGBASEADDR + REGOFF_MODE)) &= ~(0x2000UL);

	/* Inizialize GPIO pin 6 */
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

	HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, 1);
	HAL_GPIO_WritePin(GPIOH, GPIO_PIN_7, 0);

	while(1)
	{
		// *((volatile uint32_t*)(REGBASEADDR + REGOFF_OUTD)) ^= (0x0040UL);  // Toggle output state of PH.6
		HAL_GPIO_TogglePin(GPIOH, GPIO_PIN_6);
		HAL_GPIO_TogglePin(GPIOH, GPIO_PIN_7);

		// ---------------------------------------------------------------------------- //
		//                                 Placeholder 1                                //
		// ---------------------------------------------------------------------------- //
		for(count = 0; count < g_waitcycles; count++)   // Busy Loop or Delay
		{
			// -------------------------------------------------------------------------//
			//                               Placeholder 2                              //
			// -------------------------------------------------------------------------//
		}
	}
}

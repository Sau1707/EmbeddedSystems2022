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
 * Authors:  Romain Jacob, Seonyeong Heo
 */
#include "lab0.h"

#define LED_RED		(0x040)
#define LED_GREEN	(0x080)

void task_5(void)
{
	// Declare a delay counter
	volatile uint32_t i;

	// Define a toggling counter
	uint32_t counter = 0;

	/*
	 * Definition of activeLED
	 *
	 * activeLED : __31__  __30__  __...__  ___07__  __06__  __...__  __01__  __00__
	 *             **    unused bits    **  LED_GREEN LED_RED **    unused bits    **
	 *
	 * Set the bits in activeLED to toggle the corresponding LEDs
	 */

	//
	// TODO: Change the definition of activeLED
	uint8_t activeLED = 192;

	while(1)
	{
		//
		// TODO: For Task 5.2 (set value for activeLED)
		//

		// Toggle an LED
		toggle(activeLED);

		// Delay of ~300ms
		for (i = 0; i < 30000; i++) {DELAY_10US}

		// Toggle an LED
		toggle(activeLED);

		// Delay of ~300ms
		for (i = 0; i < 30000; i++) {DELAY_10US}

		// Print counter value and increment it
		uart_println("counter = %u",counter);
		counter += 1;
	}
}

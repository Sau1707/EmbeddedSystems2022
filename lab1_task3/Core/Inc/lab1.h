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

#ifndef LAB1_H_
#define LAB1_H_

#include "stm32u5xx_hal.h"

#include <stdint.h>
#include <stdarg.h>

#ifdef HAL_UART_MODULE_ENABLED
extern UART_HandleTypeDef huart1;
#endif

#define WAIT_INIT_MULTI ((uint32_t)(25))                 // Multiplier for longer busy wait
#define WAITCYCLES_BASE ((uint32_t)(100000))             // Base value for waiting cycles
#define WAIT_CYCLES     ((uint32_t)(WAITCYCLES_BASE))    // Initial number of waiting cycles
extern uint32_t g_waitcycles;                            // Number of wait cycles

static const char msg[] = "Button is pressed.";

#ifdef HAL_UART_MODULE_ENABLED
/**
 * @brief Send string via UART peripheral
 * @param str Pointer to the message to send
 * @param ... printf-style parameters
 */
static inline void uart_println(const char* str, ...)
{
	static char buffer[256];
	va_list args;

	va_start(args, str);
	vsnprintf(buffer, 256, str, args);

	uint8_t *p = (uint8_t *) buffer;
	while(*p)
	{
		HAL_UART_Transmit(&huart1, p++, 1, 0xFFFF);
	}

	HAL_UART_Transmit(&huart1, (uint8_t *)"\r\n", 2, 0xFFFF);
}
#endif

/**
 * @brief Embedded Systems (ES) Lab 1
 *
 * Base scaffold for the Lab 1 in Embedded Systems (ES). The goal of this
 * Lab is that the students get to know the platform B-U585I-IOT02A
 * Discovery Kit. This file implements the following part:
 * Task 3.1: GPIO configuration with device configuration tool
 */
void task_3_1(void);

/**
 * @brief Embedded Systems (ES) Lab 1
 *
 * Base scaffold for the Lab 1 in Embedded Systems (ES). The goal of this
 * Lab is that the students get to know the platform B-U585I-IOT02A
 * Discovery Kit. This file implements the following part:
 * Task 3.2: UART configuration with device configuration tool
 */
void task_3_2(void);

#endif /* LAB1_H_ */

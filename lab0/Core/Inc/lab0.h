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
 * Authors:  Seonyeong Heo
 */

#ifndef INC_LAB0_H_
#define INC_LAB0_H_

#include "stm32u5xx_hal.h"

#include <stdint.h>
#include <stdarg.h>

#define DELAY_10US { volatile unsigned j; for(j = 0; j < 105; j++); }

extern UART_HandleTypeDef huart1;

static inline void toggle(uint16_t GPIO_Pin)
{
	HAL_GPIO_TogglePin(GPIOH, GPIO_Pin);
}

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

/**
 * @brief Embedded Systems (ES) Lab 0
 *
 * Task 2: Your first embedded system program.
 *
 */
void task_2(void);

/**
 * @brief Embedded Systems (ES) Lab 0
 *
 * Task 3: Adaptive toggling delay.
 *
 */
void task_3(void);

/**
 * @brief Embedded Systems (ES) Lab 0
 *
 * Task 4: Use your own function.
 *
 */
void task_4(void);

/**
 * @brief Embedded Systems (ES) Lab 0
 *
 * Task 5: Taking control of the LEDs.
 *
 */
void task_5(void);

#endif /* INC_LAB0_H_ */

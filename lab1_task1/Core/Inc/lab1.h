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

#define WAIT_INIT_MULTI ((uint32_t)(25))                 // Multiplier for longer busy wait
#define WAITCYCLES_BASE ((uint32_t)(100000))             // Base value for waiting cycles
#define WAIT_CYCLES     ((uint32_t)(WAITCYCLES_BASE))    // Initial number of waiting cycles
extern uint32_t g_waitcycles;                            // Number of wait cycles

/**
 * @brief Embedded Systems (ES) Lab 1
 *
 * Base scaffold for the Lab 1 in Embedded Systems (ES). The goal of this
 * Lab is that the students get to know the platform B-U585I-IOT02A
 * Discovery Kit. This file implements the following part:
 * Task 1.1: Flashing an existing application.
 */
void task_1_1(void);
/**
 * @brief Embedded Systems (ES) Lab 1
 *
 * Base scaffold for the Lab1 in Embedded Systems (ES). The goal of this
 * Lab is that the students get to know the platform B-U585I-IOT02A
 * Discovery Kit. This file implements the following part:
 * Task 1.2: Using library functions instead of hard-coded register access
 */
void task_1_2(void);

/**
 * @brief Embedded Systems (ES) Lab 1
 *
 * Base scaffold for the Lab 1 in Embedded Systems (ES). The goal of this
 * Lab is that the students get to know the platform B-U585I-IOT02A
 * Discovery Kit. This file implements the following part:
 * Task 1.3: Adding a blinking LED
 */
void task_1_3(void);

/**
 * @brief Embedded Systems (ES) Lab 1
 *
 * Base scaffold for the Lab 1 in Embedded Systems (ES). The goal of this
 * Lab is that the students get to know the platform B-U585I-IOT02A
 * Discovery Kit. This file implements the following part:
 * Task 2.2: GPIO input polling
 */
void task_2_2(void);

/**
 * @brief Embedded Systems (ES) Lab 1
 *
 * Base scaffold for the Lab 1 in Embedded Systems (ES). The goal of this
 * Lab is that the students get to know the platform B-U585I-IOT02A
 * Discovery Kit. This file implements the following part:
 * Task 2.3: When should we poll?
 */
void task_2_3(void);

#endif /* LAB1_H_ */

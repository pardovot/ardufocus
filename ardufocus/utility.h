/**
 * Ardufocus - Moonlite compatible focuser
 * Copyright (C) 2017-2019 João Brázio [joao@brazio.org]
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __UTIL_H__
#define __UTIL_H__

#include "config.h"

#include "macro.h"
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

extern volatile uint32_t timer0_compa_count;

namespace util {
float steinhart(const uint16_t &);

inline uint16_t hex2l(const char *str) { return (strtol(str, NULL, 16)); }
inline uint32_t hex2ul(const char *str) { return (strtoul(str, NULL, 16)); }

__attribute__((always_inline)) inline void delay_250ns() {
  // Delay 4 cycles: 250us at 16 MHz
  asm volatile("    rjmp 1f"
               "\n"
               "1:  rjmp 2f"
               "\n"
               "2:"
               "\n");
}

__attribute__((always_inline)) inline void delay_500ns() {
  // Delay 8 cycles: 500us at 16 MHz
  asm volatile("    lpm"
               "\n"
               "    lpm"
               "\n"
               "    rjmp 1f"
               "\n"
               "1:"
               "\n");
}

__attribute__((always_inline)) inline void delay_750ns() {
  // Delay 12 cycles: 750us at 16 MHz
  asm volatile("    ldi  r18, 4"
               "\n"
               "1:  dec  r18"
               "\n"
               "    brne 1b"
               "\n");
}

__attribute__((always_inline)) inline void delay_1us() {
  // Delay 16 cycles: 1us at 16 MHz
  asm volatile("    ldi  r18, 5"
               "\n"
               "1:  dec  r18"
               "\n"
               "    brne 1b"
               "\n"
               "    nop"
               "\n");
}

__attribute__((always_inline)) inline void delay_2us() {
  // Delay 32 cycles: 2us at 16 MHz
  asm volatile("    ldi  r18, 10"
               "\n"
               "1:  dec  r18"
               "\n"
               "    brne 1b"
               "\n"
               "    rjmp 1f"
               "\n"
               "1:"
               "\n");
}

__attribute__((always_inline)) inline void delay_250us() {
  // Delay 4 cycles: 250 ns at 16 MHz
  asm volatile("    rjmp 1f"
               "\n"
               "1:  rjmp 2f"
               "\n"
               "2:"
               "\n");
}

__attribute__((always_inline)) inline void delay_1ms() {
  // Delay 16 000 cycles: 1ms at 16.0 MHz
  asm volatile("    ldi  r18, 21"
               "\n"
               "    ldi  r19, 199"
               "\n"
               "1:  dec  r19"
               "\n"
               "    brne 1b"
               "\n"
               "    dec  r18"
               "\n"
               "    brne 1b"
               "\n");
}

__attribute__((always_inline)) inline void delay_2ms() {
  // Delay 32 000 cycles: 2ms at 16.0 MHz
  asm volatile("    ldi  r18, 42"
               "\n"
               "    ldi  r19, 142"
               "\n"
               "1:  dec  r19"
               "\n"
               "    brne 1b"
               "\n"
               "    dec  r18"
               "\n"
               "    brne 1b"
               "\n"
               "    nop"
               "\n");
}

__attribute__((always_inline)) inline void delay_5ms() {
  // Delay 80 000 cycles: 5ms at 16.0 MHz
  asm volatile("    ldi  r18, 104"
               "\n"
               "    ldi  r19, 229"
               "\n"
               "1:  dec  r19"
               "\n"
               "    brne 1b"
               "\n"
               "    dec  r18"
               "\n"
               "    brne 1b"
               "\n");
}

#ifdef HAS_ACCELERATION
float lerp(float const &, float const &, float);
float clamp(float, float const &, float const &);

#ifdef USE_SMOOTHSTEP_ACCEL
float smoothstep(float const &, float const &, float);
float smootherstep(float const &, float const &, float);
float smootheststep(float const &, float const &, float);
#endif
#endif
}; // namespace util

#endif

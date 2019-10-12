/* Copyright 2017 Jason Williams
 * Copyright 2018 Jack Humbert
 * Copyright 2019 Clueboard
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef __AVR__
#    include <avr/interrupt.h>
#    include <avr/io.h>
#    include <util/delay.h>
#else
#    include "wait.h"
#endif

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "led_matrix_direct.h"
#include "progmem.h"
#include "print.h"

uint8_t g_pwm_buffer[LED_DRIVER_LED_COUNT];
bool    g_pwm_buffer_update_required = false;

void led_matrix_direct_init(uint8_t addr) {
    // TODO: Code to initialize the matrix pins
}

void led_matrix_direct_set_value(int index, uint8_t value) {
    if (index >= 0 && index < LED_DRIVER_LED_COUNT) {
        g_pwm_buffer[index] = value;
        g_pwm_buffer_update_required = true;
    }
}

void led_matrix_direct_set_value_all(uint8_t value) {
    for (int i = 0; i < LED_DRIVER_LED_COUNT; i++) {
        led_matrix_direct_set_value(i, value);
    }
}

void led_matrix_direct_flush(void) {
    if (g_pwm_buffer_update_required) {
        // TODO: Write code to scan the LED matrix once
        g_pwm_buffer_update_required = false;
    }
}

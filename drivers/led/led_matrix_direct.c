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
#include "wait.h"
#include "quantum.h"
#include "backlight.h"


/*
 * g_pwm_buffer is an array that represents the value of each LED.
 * FIXME: Map this from the wiring matrix to a physical location matrix at some point
 */
uint8_t g_pwm_buffer[LED_MATRIX_ROWS * LED_MATRIX_COLS];
const pin_t led_row_pins[LED_MATRIX_ROWS] = LED_MATRIX_ROW_PINS;
const pin_t led_col_pins[LED_MATRIX_COLS] = LED_MATRIX_COL_PINS;


void led_matrix_direct_init_pins(void) {
    /* Set all pins to output, we are not interested in reading any information.
     */
    for (uint8_t x = 0; x < LED_MATRIX_ROWS; x++) {
        setPinOutput(led_row_pins[x]);
    }

    for (uint8_t x = 0; x < LED_MATRIX_COLS; x++) {
        setPinOutput(led_col_pins[x]);
    }
}

void led_matrix_direct_set_value(int index, uint8_t value) {
    /* Set the brighness for a single LED.
     */
    if (index >= 0 && index < LED_DRIVER_LED_COUNT) {
        g_pwm_buffer[index] = value;
    }
}

void led_matrix_direct_set_value_all(uint8_t value) {
    /* Set the brighness for all LEDs.
     */
    for (int i = 0; i < LED_DRIVER_LED_COUNT; i++) {
        led_matrix_direct_set_value(i, value);
    }
}

void led_matrix_direct_flush(void) {
    /* This is a basic bit-banged pwm implementation.
     *
     * Limitations:
     * - Only 10 brightness levels
     * - Brighter leds will introduce latency to keyboard scanning
     */
    uint8_t led_count = 0;
    for (uint8_t row = 0; row < LED_MATRIX_ROWS; row++) {
        writePinLow(led_row_pins[row]);

        for (uint8_t col = 0; col < LED_MATRIX_COLS; col++) {
            wait_us(1);  // This seems to give more even brightness
            const int brightness = g_pwm_buffer[led_count] / 25;
            if (brightness > 0) {
                writePinHigh(led_col_pins[col]);
                for (uint8_t i = 1; i <= brightness; i++) {
                    wait_us(1);
                }
            }
            writePinLow(led_col_pins[col]);
            led_count++;
        }
    }
}

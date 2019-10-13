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


uint8_t g_pwm_buffer[LED_DRIVER_LED_COUNT];
//const pin_t led_row_pins[LED_MATRIX_ROWS] = LED_MATRIX_ROW_PINS;
//const pin_t led_col_pins[LED_MATRIX_COLS] = LED_MATRIX_COL_PINS;


void led_matrix_direct_init_pins(void) {
    /*
    print("Initializing LED matrix.\n");
    led_matrix_direct_unselect_rows();

    for (uint8_t x = 0; x < LED_MATRIX_COLS; x++) {
        setPinInputLow(led_col_pins[x]);
    }
    */
}

void led_matrix_direct_set_value(int index, uint8_t value) {
    /*
    if (index >= 0 && index < LED_DRIVER_LED_COUNT) {
        g_pwm_buffer[index] = value;
    }
    */
}

void led_matrix_direct_set_value_all(uint8_t value) {
    /*
    for (int i = 0; i < LED_DRIVER_LED_COUNT; i++) {
        led_matrix_direct_set_value(i, value);
    }
    */
}

void led_matrix_direct_flush(void) {
    // FIXME: Need to take led brightness into account
    /*
    for (uint8_t row = 0; row < LED_MATRIX_ROWS; row++) {
        led_matrix_direct_select_row(row);

        for (uint8_t col = 0; col < LED_MATRIX_COLS; col++) {
            setPinInputHigh(led_col_pins[col]);
            wait_us(30);
            setPinInputLow(led_col_pins[col]);
        }
    }
    */
}

void led_matrix_direct_select_row(uint8_t row) {
    /*
    setPinOutput(led_row_pins[row]);
    writePinLow(led_row_pins[row]);
    */
}

void led_matrix_direct_unselect_row(uint8_t row) {
    /*
    setPinInputHigh(led_row_pins[row]);
    */
}

void led_matrix_direct_unselect_rows(void) {
    /*
    for (uint8_t x = 0; x < LED_MATRIX_ROWS; x++) {
        setPinInputHigh(led_row_pins[x]);
    }
    */
}

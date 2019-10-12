#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define PRODUCT_ID      0x2010
#define DEVICE_VER      0x0001

/* key matrix pins */
#define MATRIX_ROW_PINS { D4, D1, E6, B5 }
#define MATRIX_COL_PINS { F7, F6, D3, D2 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Backlight configuration
 */
#define LED_MATRIX_ROWS 4
#define LED_MATRIX_ROW_PINS { B1, B3, B2, B4 }
#define LED_MATRIX_COLS 4
#define LED_MATRIX_COL_PINS { B6, D0, C6, D7 }
#define LED_DRIVER_LED_COUNT 16

/*
 * On a Pro Micro you have to choose between underglow and the rotary encoder.
 */

/* Encoder pins */
#define ENCODERS_PAD_A { F4 }
#define ENCODERS_PAD_B { F5 }
#define ENCODER_RESOLUTION 4

/* Underglow options */
//#define RGB_DI_PIN F4
//#define RGBLIGHT_ANIMATIONS
//#define RGBLED_NUM 1
//#define RGBLIGHT_HUE_STEP 8
//#define RGBLIGHT_SAT_STEP 8
//#define RGBLIGHT_VAL_STEP 8

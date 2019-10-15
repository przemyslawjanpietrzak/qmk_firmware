MCU = atmega32u4
BOOTLOADER = caterina
EXTRAFLAGS += -flto

## Features
BACKLIGHT_ENABLE = yes
LED_MATRIX_ENABLE = direct
CONSOLE_ENABLE = yes

## On a Pro Micro you have to choose between underglow and the rotary encoder.
RGBLIGHT_ENABLE = no
ENCODER_ENABLE = yes

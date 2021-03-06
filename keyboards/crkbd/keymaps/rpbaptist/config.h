/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define SSD1306OLED

#define USE_SERIAL_PD2

#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO

#define FORCE_NKRO

#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 12
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 16
#define RGBLIGHT_VAL_STEP 16

#define TAPPING_TERM 170
// #define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

#define TAPPING_TOGGLE 2

#define MOUSEKEY_DELAY             0
#define MOUSEKEY_INTERVAL          16
#define MOUSEKEY_MAX_SPEED         6
#define MOUSEKEY_TIME_TO_MAX       32
#define MOUSEKEY_WHEEL_MAX_SPEED   4
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

#define OLED_FONT_H "keyboards/crkbd/keymaps/rpbaptist/glcdfont.c"

#define LCPO_KEYS KC_LCTL, KC_RSFT, KC_COMM
#define RCPC_KEYS KC_RCTL, KC_RSFT, KC_DOT

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

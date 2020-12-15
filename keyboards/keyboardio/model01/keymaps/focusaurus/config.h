/*
Copyright 2017 Danny Nguyen <danny@keeb.io>

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

// #define USE_I2C
#define EE_HANDS
#define IGNORE_MOD_TAP_INTERRUPT
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 300
#define NO_ACTION_FUNCTION
#define NO_ACTION_MACRO
#define PERMISSIVE_HOLD
#define TAPPING_TERM 200
// limits maximum brightness of LEDs to 200 out of 255.
// If not defined maximum brightness is set to 255
// https://www.reddit.com/r/olkb/comments/jy3huf/flashed_qmk_on_keyboardio_model_01_but_only_the/gd4ea46?utm_source=share&utm_medium=web2x&context=3
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200

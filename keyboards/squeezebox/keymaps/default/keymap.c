/* Copyright 2021 Peter Lyons 
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
#include QMK_KEYBOARD_H

enum combos {
  COMBO_RESET,
  COMBO_ESC,
  COMBO_TAB,
  COMBO_ENT,
  COMBO_SPC
};

const uint16_t PROGMEM combo_reset[] = {KC_QUOT, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_A, KC_SCLN, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_O, KC_Q, COMBO_END};
const uint16_t PROGMEM combo_ent[] = {KC_E, KC_J, COMBO_END};
const uint16_t PROGMEM combo_spc[] = {KC_U, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_RESET] = COMBO(combo_reset, RESET),
  [COMBO_ESC] = COMBO(combo_esc, KC_ESC),
  [COMBO_TAB] = COMBO(combo_tab, KC_TAB),
  [COMBO_ENT] = COMBO(combo_ent, KC_ENT),
  [COMBO_SPC] = COMBO(combo_spc, KC_SPC)
};

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    DVORAK,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [DVORAK] = LAYOUT(
            KC_F, KC_Q, KC_C, KC_R, KC_L,
            KC_D, KC_H, KC_T, KC_N, KC_S,
            KC_B, KC_M, KC_W, KC_V, KC_Z,
            KC_NO, KC_NO, OSM(MOD_LCTL), OSM(MOD_LSFT), OSM(MOD_LGUI),
            KC_NO, KC_NO, KC_ENT, KC_SPC, KC_BSPC
            ),
};

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

#define LEAD_PUN LT(NAVPUN, KC_F10)
#define FUZZ_NAV LT(NAVPUN, KC_F11)
#define LEAD_PUN LT(NAVPUN, KC_F10)
#define ENT_NAV LT(NAVPUN, KC_ENT)
#define SPC_NUM LT(NAVPUN, KC_SPC)

enum {
  TD_COMMA,
  TD_LBRC,
  TD_RBRC,
  TD_SEMI
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_COMMA] = ACTION_TAP_DANCE_DOUBLE(KC_COMMA, KC_F12),
  [TD_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, LSFT(KC_COMMA)),
  [TD_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, LSFT(KC_DOT)),
  [TD_SEMI] = ACTION_TAP_DANCE_DOUBLE(KC_COLN, KC_SCLN)
};


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
    /* MACOS, */
    /* NAVPUN, */
    /* NAVNUM, */
    /* NUMNAV, */
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [DVORAK] = LAYOUT(
            KC_A, KC_B, KC_C, KC_D, KC_E,
            KC_F, KC_G, KC_H, KC_I, KC_J,
            KC_K, KC_L, KC_M, KC_N, KC_O,
            KC_1, KC_2, KC_3,
            KC_4, KC_5, KC_6
            /* OSM(MOD_LCTL), OSM(MOD_LSFT), KC_BSPC, */
            /* ENT_NAV, SPC_NUM, LEAD_PUN */
            ),
    /* [MACOS] = LAYOUT( */
    /*         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
    /*         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
    /*         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
    /*         OSM(MOD_LGUI), KC_TRNS, KC_TRNS, */
    /*         KC_TRNS, KC_TRNS, KC_TRNS */
    /*         ), */
    /* [NAVPUN] = LAYOUT( */
    /*         KC_TRNS, KC_LCBR, KC_RCBR, LSFT(KC_GRV), KC_EQL, */
    /*         KC_TRNS, KC_LPRN, KC_RPRN, KC_SLSH, KC_GRV, */
    /*         KC_TRNS, TD(TD_LBRC), TD(TD_RBRC), KC_TRNS, KC_TRNS, */
    /*         KC_TRNS, KC_TRNS, KC_TRNS, */
    /*         KC_TRNS, KC_TRNS, KC_TRNS */
    /*         ), */
};

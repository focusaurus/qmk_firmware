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
#define SPC_NUM LT(NAVNUM, KC_SPC)

enum {

  TD_COMMA,
  TD_DOT,
  TD_LBRC,
  TD_RBRC,
  TD_SEMI

};

qk_tap_dance_action_t tap_dance_actions[] = {

  [TD_COMMA] = ACTION_TAP_DANCE_DOUBLE(KC_COMMA, KC_F12),
  [TD_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_QUES),
  [TD_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, LSFT(KC_COMMA)),
  [TD_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, LSFT(KC_DOT)),
  [TD_SEMI] = ACTION_TAP_DANCE_DOUBLE(KC_COLN, KC_SCLN)

};

enum combos {

  /* COMBO_ENTER, */
  /* COMBO_SLASH, */
  /* COMBO_SPACE, */
  /* COMBO_TAB, */
  /* COMBO_TILDE, */
  COMBO_ESCAPE,
  COMBO_EXCLAMATION,
  COMBO_MINUS,
  /* COMBO_MINUS2, */
  COMBO_PIPE,
  COMBO_QUESTION,
  COMBO_RESET,

};

/* const uint16_t PROGMEM combo_enter[] = {KC_E, KC_J, COMBO_END}; */
/* const uint16_t PROGMEM combo_slash[] = {KC_T, KC_W, COMBO_END}; */
/* const uint16_t PROGMEM combo_space[] = {KC_U, KC_K, COMBO_END}; */
/* const uint16_t PROGMEM combo_tab[] = {KC_O, KC_Q, COMBO_END}; */
/* const uint16_t PROGMEM combo_tilde[] = {KC_H, KC_M, COMBO_END}; */
const uint16_t PROGMEM combo_escape[] = {KC_E, KC_U, COMBO_END};
const uint16_t PROGMEM combo_exclamation[] = {KC_Z, KC_DOT, COMBO_END};
/* const uint16_t PROGMEM combo_minus2[] = {KC_S, KC_Z, COMBO_END}; */
const uint16_t PROGMEM combo_minus[] = {KC_Z, KC_V, COMBO_END};
const uint16_t PROGMEM combo_pipe[] = {KC_Z, KC_P, COMBO_END};
const uint16_t PROGMEM combo_question[] = {KC_Z, KC_COMMA, COMBO_END};
const uint16_t PROGMEM combo_reset[] = {KC_F, KC_L, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {

  /* [COMBO_ENTER] = COMBO(combo_enter, KC_ENT), */
  /* [COMBO_MINUS2] = COMBO(combo_minus2, KC_MINUS), */
  /* [COMBO_SLASH] = COMBO(combo_slash, KC_SLSH), */
  /* [COMBO_SPACE] = COMBO(combo_space, KC_SPC), */
  /* [COMBO_TAB] = COMBO(combo_tab, KC_TAB), */
  /* [COMBO_TILDE] = COMBO(combo_tilde, KC_TILDE), */
  [COMBO_ESCAPE] = COMBO(combo_escape, KC_ESC),
  [COMBO_EXCLAMATION] = COMBO(combo_exclamation, LSFT(KC_1)),
  [COMBO_MINUS] = COMBO(combo_minus, KC_MINUS),
  [COMBO_PIPE] = COMBO(combo_pipe, KC_PIPE),
  [COMBO_QUESTION] = COMBO(combo_question, KC_QUES),
  [COMBO_RESET] = COMBO(combo_reset, RESET),

};

// Defines names for use in layer keycodes and the keymap
enum layer_names {

    DVORAK,
    MACOS,
    NAVPUN,
    NAVNUM,
    BANG,
    NAVFKEYS,

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [DVORAK] = LAYOUT(

        KC_QUOTE, KC_COMMA, KC_DOT, LT(NAVFKEYS, KC_P), KC_Y,
        MT(MOD_LGUI | MOD_LALT, KC_A), KC_O, KC_E, KC_U, KC_I,
        LT(BANG, LSFT(KC_SCLN)), KC_Q, LALT_T(KC_J), LCTL_T(KC_K), KC_X,
        OSM(MOD_LCTL), OSM(MOD_LSFT), OSM(MOD_LALT),
        KC_BSPC, LEAD_PUN, OSM(MOD_LGUI),
        KC_F, KC_G, KC_C, KC_R, KC_L,
        KC_D, KC_H, KC_T, KC_N, KC_S,
        KC_B, RCTL_T(KC_M), KC_W, KC_V, LT(BANG, KC_Z),
        OSM(MOD_LALT), OSM(MOD_RSFT), OSM(MOD_RCTL),
        ENT_NAV, SPC_NUM, LEAD_PUN

        /*
            LSFT(KC_A), LSFT(KC_B), LSFT(KC_C), LSFT(KC_D), LSFT(KC_E),
            LSFT(KC_F), LSFT(KC_G), LSFT(KC_H), LSFT(KC_I), LSFT(KC_J),
            LSFT(KC_K), LSFT(KC_L), LSFT(KC_M), LSFT(KC_N), LSFT(KC_O),
            LSFT(KC_1), LSFT(KC_2), LSFT(KC_3),
            LSFT(KC_4), LSFT(KC_5), LSFT(KC_6),
            KC_A, KC_B, KC_C, KC_D, KC_E,
            KC_F, KC_G, KC_H, KC_I, KC_J,
            KC_K, KC_L, KC_M, KC_N, KC_O,
            KC_1, KC_2, KC_3,
            KC_4, KC_5, KC_6
        */

            ),
    [MACOS] = LAYOUT(

            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            OSM(MOD_LGUI), KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, OSM(MOD_LGUI),
            KC_TRNS, KC_TRNS, KC_TRNS

            ),
    [NAVPUN] = LAYOUT(

            KC_TRNS, KC_BSPC, KC_SPC, KC_DEL, KC_PGUP,
            KC_TAB, KC_LEFT, KC_UP, KC_RIGHT, KC_ENT,
            LCTL(KC_A), KC_HOME, KC_DOWN, KC_END, KC_PGDN,
            KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_LCBR, KC_RCBR, LSFT(KC_GRV), LSFT(KC_EQUAL),
            KC_TRNS, KC_LPRN, KC_RPRN, KC_SLSH, KC_GRV,
            KC_TRNS, TD(TD_LBRC), TD(TD_RBRC), KC_BSLS, KC_EQUAL,
            KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS

            ),
    [NAVNUM] = LAYOUT(

            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS,
            KC_COMM, KC_7, KC_8, KC_9, KC_TRNS,
            KC_DOT, KC_4, KC_5, KC_6, KC_0,
            LSFT(KC_COLN), KC_1, KC_2, KC_3, KC_TRNS,
            KC_TRNS, KC_TRNS, OSM(MOD_LGUI),
            KC_TRNS, KC_TRNS, KC_TRNS

            ),
    [BANG] = LAYOUT(

            KC_TRNS, KC_QUES, LSFT(KC_1), KC_PIPE, KC_TRNS,
            KC_MINUS, KC_TRNS, KC_TRNS, KC_MINUS, KC_TRNS,
            KC_TRNS, KC_SCLN, KC_TRNS, LSFT(KC_MINUS), KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS,
            KC_PIPE, LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), KC_TRNS,
            KC_MINUS, LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_0),
            LSFT(KC_MINUS), LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS

            ),
    [NAVFKEYS] = LAYOUT(

            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F12,
            KC_TRNS, KC_F4, KC_F5, KC_F6, KC_F11,
            KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F10,
            KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS

            ),
};

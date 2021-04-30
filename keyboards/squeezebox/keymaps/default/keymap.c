/* Copyright 2021 Peter Lyons
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 *
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

#define LEADER KC_F10
#define FUZZBALL KC_F11
#define SNIPPETS KC_F12

enum {

  TD_COMMA,
  /* TD_DOT, */
  /* TD_LBRC, */
  /* TD_RBRC, */
  TD_SEMI

};

qk_tap_dance_action_t tap_dance_actions[] = {

  [TD_COMMA] = ACTION_TAP_DANCE_DOUBLE(KC_COMMA, KC_F12),
  /* [TD_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_QUES), */
  /* [TD_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, LSFT(KC_COMMA)), */
  /* [TD_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, LSFT(KC_DOT)), */
  [TD_SEMI] = ACTION_TAP_DANCE_DOUBLE(KC_COLON, KC_SCLN)

};

enum combos {

  /* COMBO_COLON, */
  /* COMBO_ENTER, */
  /* COMBO_EXCLAMATION, */
  /* COMBO_MINUS, */
  /* COMBO_MINUS2, */
  /* COMBO_PIPE, */
  /* COMBO_QUESTION, */
  /* COMBO_SEMI, */
  /* COMBO_SLASH, */
  /* COMBO_SPACE, */
  /* COMBO_TAB, */
  /* COMBO_TILDE, */
  COMBO_BACKSPACE,
  COMBO_BRACKETS,
  COMBO_ESCAPE,
  COMBO_PARENS,

};


/* const uint16_t PROGMEM combo_colon[] = {KC_U, KC_K, COMBO_END}; */
/* const uint16_t PROGMEM combo_enter[] = {KC_E, KC_J, COMBO_END}; */
/* const uint16_t PROGMEM combo_exclamation[] = {KC_Z, KC_DOT, COMBO_END}; */
/* const uint16_t PROGMEM combo_minus2[] = {KC_S, KC_Z, COMBO_END}; */
/* const uint16_t PROGMEM combo_minus[] = {KC_N, KC_S, COMBO_END}; */
/* const uint16_t PROGMEM combo_pipe[] = {KC_Z, KC_P, COMBO_END}; */
/* const uint16_t PROGMEM combo_question[] = {KC_Z, KC_COMMA, COMBO_END}; */
/* const uint16_t PROGMEM combo_reset[] = {KC_F, KC_L, COMBO_END}; */
/* const uint16_t PROGMEM combo_slash[] = {KC_T, KC_W, COMBO_END}; */
/* const uint16_t PROGMEM combo_space[] = {KC_U, KC_K, COMBO_END}; */
/* const uint16_t PROGMEM combo_tab[] = {KC_O, KC_Q, COMBO_END}; */
/* const uint16_t PROGMEM combo_tilde[] = {KC_H, KC_M, COMBO_END}; */
const uint16_t PROGMEM combo_backspace[] = {KC_O, KC_E, COMBO_END};
const uint16_t PROGMEM combo_brackets[] = {KC_J, KC_E, COMBO_END};
const uint16_t PROGMEM combo_escape[] = {KC_E, KC_U, COMBO_END};
const uint16_t PROGMEM combo_parens[] = {KC_U, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {

  /* [COMBO_COLON] = COMBO(combo_colon, KC_COLON), */
  /* [COMBO_ENTER] = COMBO(combo_enter, KC_ENT), */
  /* [COMBO_EXCLAMATION] = COMBO(combo_exclamation, KC_EXCLAIM), */
  /* [COMBO_MINUS2] = COMBO(combo_minus2, KC_MINUS), */
  /* [COMBO_MINUS] = COMBO(combo_minus, KC_MINUS), */
  /* [COMBO_PIPE] = COMBO(combo_pipe, KC_PIPE), */
  /* [COMBO_QUESTION] = COMBO(combo_question, KC_QUES), */
  /* [COMBO_SLASH] = COMBO(combo_slash, KC_SLSH), */
  /* [COMBO_SPACE] = COMBO(combo_space, KC_SPC), */
  /* [COMBO_TAB] = COMBO(combo_tab, KC_TAB), */
  /* [COMBO_TILDE] = COMBO(combo_tilde, KC_TILDE), */
  [COMBO_BACKSPACE] = COMBO(combo_backspace, KC_BSPC),
  [COMBO_BRACKETS] = COMBO_ACTION(combo_brackets),
  [COMBO_ESCAPE] = COMBO(combo_escape, KC_ESC),
  [COMBO_PARENS] = COMBO_ACTION(combo_parens),

};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case COMBO_BRACKETS:
      if (pressed) {
        tap_code16(KC_LBRC);
        tap_code16(KC_RBRC);
        tap_code16(KC_LEFT);
      }
      break;
    case COMBO_PARENS:
      if (pressed) {
        tap_code16(KC_LPRN);
        tap_code16(KC_RPRN);
        tap_code16(KC_LEFT);
      }
      break;
  }
}

// Defines names for use in layer keycodes and the keymap
enum layer_names {

    DVORAK,
    MACOS,
    NAVNUM,
    BANG,
    KBFN

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [DVORAK] = LAYOUT(

        // TODO 1-finger combos for uk, ej, oq
        KC_QUOTE, TD(TD_COMMA), LALT_T(KC_DOT), LCTL_T(KC_P), KC_Y,
        MT(MOD_LGUI | MOD_LALT, KC_A), KC_O, KC_E, KC_U, KC_I,
        TD(TD_SEMI), KC_Q, KC_J, KC_K, KC_X,
        OSM(MOD_LCTL), OSM(MOD_LSFT), OSM(MOD_LALT),
        LT(KBFN, KC_BSPC), LT(NAVNUM, LEADER), MT(MOD_LGUI, FUZZBALL),

        // TODO 1-finger combos for hm, tw, nv, sz
        KC_F, RCTL_T(KC_G), LALT_T(KC_C), KC_R, KC_L,
        KC_D, KC_H, KC_T, KC_N, KC_S,
        KC_B, KC_M, KC_W, KC_V, KC_Z,
        // TODO if top row mods work out can use these for something else
        OSM(MOD_LALT), OSM(MOD_RSFT), OSM(MOD_RCTL),
        // TODO LE3 available for a better layer
        KC_ENT, LT(BANG, KC_SPC), KC_ESC

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
    [NAVNUM] = LAYOUT(

            KC_TRNS, KC_BSPC, KC_SPC, KC_DEL, KC_PGUP,
            KC_TAB, KC_LEFT, KC_UP, KC_RIGHT, KC_ENT,
            LCTL(KC_A), KC_HOME, KC_DOWN, KC_END, KC_PGDN,
            KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS,
            KC_COMM, KC_7, KC_8, KC_9, KC_NO,
            KC_DOT, KC_4, KC_5, KC_6, KC_0,
            KC_COLON, KC_1, KC_2, KC_3, KC_NO,
            KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS

            ),
    [BANG] = LAYOUT(

            KC_LT, KC_GT, KC_LCBR, KC_RCBR, KC_PIPE,
            KC_MINUS, KC_UNDERSCORE, KC_LPRN, KC_RPRN, KC_SCLN,
            KC_QUES, KC_EXCLAIM, KC_LBRC, KC_RBRC, KC_BSLS,
            KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS,

            LSFT(KC_EQL), LSFT(KC_7), LSFT(KC_8), KC_NO, KC_TILDE,
            KC_EQL, LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), KC_SLSH,
            KC_GRV, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), KC_COLON,
            KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS

            ),
    [KBFN] = LAYOUT(

            KC_NO, KC_NO, KC_NO, KC_VOLU, KC_NO,
            KC_CAPSLOCK, KC_NO, KC_NO, KC_MUTE, RESET,
            TG(MACOS), KC_NO, KC_NO, KC_VOLD, KC_NO,
            KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS,
            KC_NO, KC_F7, KC_F8, KC_F9, KC_F12,
            KC_NO, KC_F4, KC_F5, KC_F6, KC_F11,
            KC_NO, KC_F1, KC_F2, KC_F3, KC_F10,
            KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS

            ),
};

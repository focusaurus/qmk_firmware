/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include QMK_KEYBOARD_H

enum combos {

  COMBO_BACKSPACE,
  COMBO_BRACKETS,
  COMBO_ESCAPE,
  COMBO_PARENS,
  COMBO_PIPE,

};

const uint16_t PROGMEM combo_backspace[] = {KC_NO, KC_NO, COMBO_END};
const uint16_t PROGMEM combo_brackets[] = {KC_J, KC_E, COMBO_END};
const uint16_t PROGMEM combo_escape[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_parens[] = {KC_U, KC_K, COMBO_END};
const uint16_t PROGMEM combo_pipe[] = {KC_DOT, KC_P, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {

  [COMBO_BACKSPACE] = COMBO(combo_backspace, KC_BSPC),
  [COMBO_BRACKETS] = COMBO_ACTION(combo_brackets),
  [COMBO_ESCAPE] = COMBO(combo_escape, KC_ESC),
  [COMBO_PARENS] = COMBO_ACTION(combo_parens),
  [COMBO_PIPE] = COMBO(combo_pipe, KC_PIPE)

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

#define LEADER KC_F10
#define FUZZBALL KC_F11
#define SNIPPETS KC_F12

enum layer_names {

    DVORAK,
    MACOS,
    EDIT,
    NUMBERS,
    BANG,
    KBFN

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
[DVORAK] = LAYOUT_stack(

KC_TAB, KC_QUOTE, KC_COMMA /*TD(TD_COMMA)*/, LALT_T(KC_DOT), LCTL_T(KC_P), KC_Y,
MT(MOD_LCTL, KC_ESC), MT(MOD_LGUI | MOD_LALT, KC_A), KC_O, KC_E, KC_U, KC_I,
OSL(BANG), KC_SCLN /*TD(TD_SEMI)*/, KC_Q, KC_J, KC_K, KC_X, OSL(BANG), LT(KBFN, FUZZBALL),
KC_LEFT, KC_RIGHT, LT(KBFN, KC_BSPC), LT(EDIT, LEADER), OSM(MOD_LSFT),

              KC_F, RCTL_T(KC_G), LALT_T(KC_C), KC_R, KC_L, KC_SLASH,
              KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINUS,
OSM(MOD_RGUI), OSM(MOD_LALT), KC_B, KC_M, KC_W, KC_V, KC_Z, KC_NO,
LT(BANG, KC_ENT), LT(NUMBERS, KC_SPC), OSM(MOD_RCTL), KC_LEFT, KC_RIGHT

), [MACOS] = LAYOUT_stack(

KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
OSM(MOD_RCTL), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, OSM(MOD_RGUI), KC_TRNS, KC_TRNS

), [EDIT] = LAYOUT_stack(

KC_NO, KC_TRNS, KC_BSPC, KC_SPC, KC_DEL, KC_PGUP,
KC_NO, KC_TAB, KC_LEFT, KC_UP, KC_RIGHT, KC_ENT,
LCTL(KC_A), KC_HOME, KC_DOWN, KC_END, KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

RSFT(KC_EQL), KC_LCBR, KC_RCBR, LSFT(KC_GRV), KC_EQL, KC_TRNS,
KC_EQL, KC_LPRN, KC_RPRN, KC_SLSH, KC_GRV, KC_TRNS,
// TODO tapdance square brackets here
KC_TRNS, KC_TRNS, KC_BSLS, KC_LBRC, KC_RBRC, KC_PIPE, RSFT(KC_MINUS), KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

), [NUMBERS] = LAYOUT_stack(

KC_NO, KC_TRNS, KC_BSPC, KC_SPC, KC_DEL, KC_PGUP,
KC_NO, KC_TAB, KC_LEFT, KC_UP, KC_RIGHT, KC_ENT,
LCTL(KC_A), KC_HOME, KC_DOWN, KC_END, KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                  KC_COMMA, KC_7, KC_8, KC_9, KC_NO, KC_NO,
                  KC_DOT,   KC_4, KC_5, KC_6, KC_0, KC_TRNS,
KC_TRNS, KC_TRNS, KC_COLON, KC_1, KC_2, KC_3, KC_NO, KC_NO,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

), [BANG] = LAYOUT_stack(

KC_NO, KC_LT, KC_GT, KC_LCBR, KC_RCBR, KC_PIPE,
KC_NO, KC_MINUS, KC_UNDERSCORE, KC_LPRN, KC_RPRN, KC_SCLN,
KC_NO, KC_QUES, KC_EXCLAIM, KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                  LSFT(KC_EQL), LSFT(KC_7), LSFT(KC_8), KC_NO, KC_TILDE, KC_NO,
                  KC_EQL, LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), KC_SLSH, KC_NO,
KC_TRNS, KC_TRNS, KC_GRV, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), KC_COLON, KC_NO,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

), [KBFN] = LAYOUT_stack(

KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLU, KC_NO,
KC_CAPSLOCK, TG(MACOS), KC_NO, KC_NO, KC_MUTE, RESET,
KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLD, KC_NO, KC_NO, KC_NO,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

              KC_NO, KC_F7, KC_F8, KC_F9, KC_F12, KC_NO,
              KC_NO, KC_F4, KC_F5, KC_F6, KC_F11, KC_NO,
KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F10, KC_NO,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

),
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case DVORAK:
            oled_write_P(PSTR("dvorak\n"), false);
            break;
        case MACOS:
            oled_write_P(PSTR("macos\n"), false);
            break;
        case EDIT:
            oled_write_P(PSTR("nav/num\n"), false);
            break;
        case BANG:
            oled_write_P(PSTR("bang\n"), false);
            break;
        case KBFN:
            oled_write_P(PSTR("keeb/fn\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

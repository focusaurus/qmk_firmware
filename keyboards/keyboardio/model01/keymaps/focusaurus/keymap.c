/* Copyright 2018 James Laird-Wah
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

/* layer constants */
enum {
  DVORAK = 0,
  NAVPUNC,
  NAVNUM,
  KEEBNAV,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[DVORAK] = LAYOUT(
  // Row A Left (no innermost column)
  KC_GESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
  // Row A Right (no innermost column)
  KC_F6, KC_F7, KC_F8, KC_F9, KC_EQL, KC_BSLS,
  // Row B Left
  KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_PGUP,
  // Row B Right
  KC_VOLU, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH,
  // Row C Left
  LCTL_T(KC_ESC), MT(MOD_LGUI | MOD_LALT, KC_A), KC_O, KC_E, KC_U, KC_I, KC_HOME,
  // Row C Right
  KC_MUTE, KC_D, KC_H, KC_T, KC_N, MT(MOD_LGUI | MOD_LALT, KC_S), KC_MINS,
  // Row D Left
  OSM(MOD_LSFT), KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_PGDN,
  // Row D Right
  KC_VOLD, KC_B, KC_M, KC_W, KC_V, KC_Z, MT(MOD_RSFT, KC_F12),
  // Thumb cluster (left then right on same line moving outermost to innermost)
  MT(MOD_LGUI | MOD_LALT, KC_BSPC), MT(MOD_LGUI | MOD_LALT, KC_BSPC),
    LT(NAVPUNC, KC_F12), LT(NAVNUM, KC_SPC),
      OSM(MOD_LGUI), MT(MOD_RALT, KC_ENT),
        OSM(MOD_LSFT), OSM(MOD_RSFT),
  // Palm keys
  LT(KEEBNAV, KC_F11), LT(KEEBNAV, KC_F11)
  ),
[NAVPUNC] = LAYOUT(
  // Row A Left (no innermost column)
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  // Row A Right (no innermost column)
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  // Row B Left
  KC_TRNS, LGUI(KC_TAB), KC_BSPC, KC_SPC, KC_DEL, KC_PGUP, KC_TRNS,
  // Row B Right
  KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, LSFT(KC_GRV), KC_TRNS, KC_TRNS,
  // Row C Left
  KC_TRNS, KC_TAB, KC_LEFT, KC_UP, KC_RIGHT, KC_ENT, KC_TRNS,
  // Row C Right
  KC_TRNS, KC_TRNS, KC_LPRN, KC_RPRN, KC_SLSH, KC_GRV, KC_TRNS,
  // Row D Left
  KC_TRNS, KC_TRNS, KC_HOME, KC_DOWN, KC_END, KC_PGDN, KC_TRNS,
  // Row D Right
  KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS,                     KC_TRNS,
      KC_TRNS,               KC_TRNS,
         KC_TRNS,         KC_TRNS,
            KC_TRNS,   KC_TRNS,
  KC_TRNS,                KC_TRNS
  ),
[NAVNUM] = LAYOUT(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_COMM, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_DOT, KC_4, KC_5, KC_6, KC_0, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, LSFT(KC_COLN), KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS,
                                         KC_TRNS,                                 KC_TRNS,
                                            KC_TRNS,                           KC_TRNS,
                                               KC_TRNS,                     KC_TRNS,
                                                  KC_TRNS,               KC_TRNS,
                                      KC_TRNS,                                        KC_TRNS
  ),
[KEEBNAV] = LAYOUT(
  // Row A Left (no innermost column)
  RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  // Row A Right (no innermost column)
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  // Row B Left
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  // Row B Right
  KC_TRNS, KC_PGUP, KC_BSPC, KC_SPC, KC_DEL, KC_TRNS, KC_TRNS,
  // Row C Left
  RGB_MOD, RGB_MOD, RGB_MOD, RGB_MOD, RGB_MOD, RGB_MOD, RGB_MOD,
  // Row C Right
  KC_TRNS, KC_ENT, KC_LEFT, KC_UP, KC_RIGHT, KC_TAB, KC_TRNS,
  // Row D Left
  KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS,
  // Row D Right
  KC_TRNS, KC_PGDN, KC_HOME, KC_DOWN, KC_END, KC_TRNS, KC_TRNS,
     KC_TRNS,                     KC_TRNS,
      KC_TRNS,               KC_TRNS,
         KC_TRNS,         KC_TRNS,
            KC_TRNS,   KC_TRNS,
  KC_TRNS,                KC_TRNS
  ),
};

/* template for new layouts:
LAYOUT(
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                                         _______,                                 _______,
                                            _______,                           _______,
                                               _______,                     _______,
                                                  _______,               _______,
                                      _______,                                        _______
  )
*/

static void set_numpad_colours(int on, void (*write)(int, uint8_t, uint8_t, uint8_t)) {
  if (!on) {
    for (int i=44; i<=60; i++)
      write(i, 0, 0, 0);
    write(63, 0, 0, 0);
    return;
  }

  /* main number keys */
  for (int i=44; i<=47; i++)
    write(i, 255, 0, 0);
  for (int i=49; i<=54; i++)
    write(i, 255, 0, 0);

  /* accessory keys */
  write(48, 128, 128, 0);
  for (int i=55; i<=59; i++)
    write(i, 128, 128, 0);

  // enter
  write(63, 0, 128, 0);

  // num key
  write(60, 128, 0, 128);
}

#ifdef RGB_MATRIX_ENABLE
/* the RGB matrix effects will overwrite the numpad indicator.
 * this handy mechanism allows to override the matrix effects.
 */
void rgb_matrix_indicators_user(void) {
  if (layer_state & (1<<NAVPUNC)) {
    set_numpad_colours(1, &rgb_matrix_set_color);
  }
}
#else   /* no RGB matrix support */

layer_state_t layer_state_set_user(layer_state_t state) {
  if (state & (1<<NAVPUNC)) {
    set_numpad_colours(1, &set_led_to);
  } else {
    set_numpad_colours(0, &set_led_to);
  }

  return state;
}
#endif

/* vim: set ts=2 sw=2 et: */

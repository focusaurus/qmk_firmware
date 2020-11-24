#include QMK_KEYBOARD_H


#define _DVORAK 0
#define _NAVPAREN 1
#define _NUM 2
#define _KEEBNAV 3

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  NAVPAREN,
  NUM,
  KEEBNAV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT(
  // row A
  KC_GESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, /*right*/ KC_F6, KC_F7, KC_F8, KC_F9, KC_EQL, KC_BSLS,
  // row B
  KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, /*right*/ KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH,
  // row C
  LCTL_T(KC_ESC), MT(MOD_LGUI | MOD_LALT, KC_A), KC_O, KC_E, KC_U, KC_I, /*right*/ KC_D, KC_H, KC_T, KC_N, MT(MOD_LGUI | MOD_LALT, KC_S), KC_MINS,
  // row D
  OSM(MOD_LSFT), KC_SCLN, KC_Q, KC_J, KC_K, KC_X, /*rotary*/ KC_HOME, KC_MUTE, /*right*/ KC_B, KC_M, KC_W, KC_V, KC_Z, MT(MOD_RSFT, KC_F12),
  // row E
  MT(MOD_LGUI | MOD_LALT, KC_BSPC), MT(MOD_LGUI, KC_F11), LT(_NAVPAREN, KC_ENT), /*right*/ LT(3, KC_ENT), LT(2, KC_SPC), KC_RALT
  ),

  [_NAVPAREN] = LAYOUT(
  // row A
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*right*/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  // row B
  KC_TRNS, LGUI(KC_TAB), KC_BSPC, KC_SPC, KC_DEL, KC_PGUP, KC_TRNS, /*right*/ KC_LCBR, KC_RCBR, LSFT(KC_GRV), KC_TRNS, KC_TRNS,
  // row C
  KC_TRNS, KC_TAB, KC_LEFT, KC_UP, KC_RIGHT, KC_ENT, /*right*/ KC_TRNS, KC_LPRN, KC_RPRN, KC_SLSH, KC_GRV, KC_TRNS,
  // row D
  KC_TRNS, KC_TRNS, KC_HOME, KC_DOWN, KC_END, KC_PGDN, /*rotary*/ KC_TRNS, KC_TRNS, /*right*/ KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS,
  // row E
  KC_TRNS, KC_TRNS, KC_TRNS, /*right*/ KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_NUM] = LAYOUT(
  // row A
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*right*/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  // row B
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*right*/ KC_COMM, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS,
  // row C
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*right*/ KC_DOT, KC_4, KC_5, KC_6, KC_0, KC_TRNS,
  // row D
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*rotary*/ KC_TRNS, KC_TRNS, /*right*/ LSFT(KC_COLN), KC_1,  KC_2,  KC_3, KC_TRNS, KC_TRNS,
  // row E
  KC_TRNS, KC_TRNS, KC_TRNS, /*right*/ KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_KEEBNAV] = LAYOUT(
  // row A
  RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*right*/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  // row B
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_VAI, KC_TRNS, /*right*/ KC_PGUP, KC_BSPC, KC_SPC, KC_DEL, LGUI(KC_TAB), KC_TRNS,
  // row C
  KC_TRNS, KC_TRNS, RGB_RMOD, RGB_TOG, RGB_MOD, KC_TRNS, /*right*/ KC_ENT, KC_LEFT, KC_UP, KC_RIGHT, KC_TAB, KC_TRNS,
  // row D
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_VAD, KC_TRNS, /*rotary*/ KC_TRNS, KC_TRNS, /*right*/ KC_PGDN, KC_HOME, KC_DOWN, KC_END, KC_TRNS, KC_TRNS,
  // row E
  KC_TRNS, KC_TRNS, KC_TRNS, /*right*/ KC_TRNS, KC_TRNS, KC_TRNS
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case NAVPAREN:
      if (record->event.pressed) {
        layer_on(_NAVPAREN);
        update_tri_layer(_NAVPAREN, _NUM, _KEEBNAV);
      } else {
        layer_off(_NAVPAREN);
        update_tri_layer(_NAVPAREN, _NUM, _KEEBNAV);
      }
      return false;
      break;
    case NUM:
      if (record->event.pressed) {
        layer_on(_NUM);
        update_tri_layer(_NAVPAREN, _NUM, _KEEBNAV);
      } else {
        layer_off(_NUM);
        update_tri_layer(_NAVPAREN, _NUM, _KEEBNAV);
      }
      return false;
      break;
    case KEEBNAV:
      if (record->event.pressed) {
        layer_on(_KEEBNAV);
      } else {
        layer_off(_KEEBNAV);
      }
      return false;
      break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // Tap the key that would be comma in dvorak
    // (left ring finger top row)
    // twice in a row to type a literal comma
    SEQ_ONE_KEY(KC_LEAD) {
      tap_code(KC_SCLN);
    }
    // 2 commas for emacs
    /* SEQ_TWO_KEYS(KC_LEAD, KC_LEAD) { */
    /*   tap_code(KC_COMM); */
    /*   tap_code(KC_COMM); */
    /* } */
    // Since most of the time I type a comma, it's followed by a space
    // make the what happens by default
    SEQ_ONE_KEY(KC_SPC) {
      SEND_STRING(", ");
    }
    // Similar to above but for enter
    SEQ_ONE_KEY(KC_ENT) {
      SEND_STRING(",\\n");
    }
    // F11 to launch fuzzball gui fuzzy finder
    SEQ_ONE_KEY(KC_DOT) {
      tap_code(KC_F11);
    }
    // b for browser (F1 fkeys)
    SEQ_ONE_KEY(KC_B) {
      tap_code(KC_F1);
    }
    // t for terminal (F3 fkeys)
    SEQ_ONE_KEY(KC_T) {
      tap_code(KC_F3);
    }
    // e for emacs (F4 fkeys)
    SEQ_ONE_KEY(KC_E) {
      tap_code(KC_F4);
    }
    // s for slack (F6 fkeys)
    SEQ_ONE_KEY(KC_S) {
      tap_code(KC_F6);
    }
    // m for music (F8 fkeys)
    SEQ_ONE_KEY(KC_M) {
      tap_code(KC_F8);
    }
    /* SEQ_TWO_KEYS(KC_D, KC_D) { */
    /*   SEND_STRING(SS_LCTL("a") SS_LCTL("c")); */
    /* } */
    /* SEQ_THREE_KEYS(KC_D, KC_D, KC_S) { */
    /*   SEND_STRING("https://start.duckduckgo.com\n"); */
    /* } */
    /* SEQ_TWO_KEYS(KC_A, KC_S) { */
    /*   register_code(KC_LGUI); */
    /*   register_code(KC_S); */
    /*   unregister_code(KC_S); */
    /*   unregister_code(KC_LGUI); */
    /* } */
  }
}


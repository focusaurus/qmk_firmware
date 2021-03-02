#include QMK_KEYBOARD_H

/* layer constants */
enum {
  DVORAK = 0,
  MACOS,
  NAVPUN,
  NAVNUM,
  NUMNAV,
};

// left thumb cluster layer taps
#define LEAD_PUN LT(NAVPUN, KC_F10)
#define FUZZ_NAV LT(NUMNAV, KC_F11)

// right thumb cluster layer taps
#define LEAD_NAV LT(NUMNAV, KC_F10)
#define ENT_NAV LT(NUMNAV, KC_ENT)
#define SPC_NUM LT(NAVNUM, KC_SPC)


// snippets
#define SNIP_SFT MT(MOD_RSFT, KC_F12)

enum {
  TD_COMMA_F12,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_COMMA_F12] = ACTION_TAP_DANCE_DOUBLE(KC_COMMA, KC_F12),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DVORAK] = LAYOUT_ergodox_pretty(
    // row A left (7 keys)
    KC_GESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_NO,
    // row A right (7 keys)
    KC_MUTE, KC_F6, KC_F7, KC_F8, KC_F9, KC_EQL, KC_BSLS,
    // row B left (has inner column) (7 keys)
    KC_TAB, KC_QUOT, TD(TD_COMMA_F12), KC_DOT, KC_P, KC_Y, KC_PGUP,
    // row B right (has inner column) (7 keys)
    KC_VOLU, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH,
    // row C left (no inner column) (6 keys)
    LCTL_T(KC_ESC), MT(MOD_LGUI | MOD_LALT, KC_A), KC_O, KC_E, KC_U, KC_I,
    // row C right (no inner column) (6 keys)
    KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS,
    // row D left (has inner column) (7 keys)
    OSM(MOD_LSFT), MT(MOD_LGUI | MOD_LALT, KC_SCLN), KC_Q, KC_J, KC_K, KC_X, KC_PGDN,
    // row D right (has inner column) (7 keys)
    KC_VOLD, KC_B, KC_M, KC_W, KC_V, KC_Z, SNIP_SFT,
    // row E left (5 keys)
    KC_F1, KC_F2, KC_F3, KC_F4, OSM(MOD_LCTL),
    // row E right (5 keys)
    RALT_T(KC_LEFT), KC_DOWN, KC_UP, KC_RIGHT, LGUI(LALT(KC_X)),
    // Thumb row F top left (2 keys)
    KC_F6, KC_F7,
    // Thumb row F top right (2 keys)
    KC_F8, KC_F9,
    // Thumb row G just the middle 1U keys (2 keys)
    TG(MACOS), OSM(MOD_LALT),
    // Thumb row H bottom left (mixed 2U 2U 1U) (3 keys)
    LEAD_PUN, OSM(MOD_LSFT), FUZZ_NAV,
    // Thumb row H bottm right (mixed 2U 2U 1U) (3 keys)
    LEAD_NAV, ENT_NAV, SPC_NUM),
  [MACOS] = LAYOUT_ergodox_pretty(
    // All this layer does is swap GUI/CTL on left thumb
    // mostly for copy/paste/new-tab parity
    // row A left (7 keys)
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // row A right (7 keys)
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // row B left (has inner column) (7 keys)
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // row B right (has inner column) (7 keys)
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // row C left (no inner column) (6 keys)
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // row C right (no inner column) (6 keys)
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // row D left (has inner column) (7 keys)
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // row D right (has inner column) (7 keys)
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // row E left (5 keys)
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, OSM(MOD_LGUI),
    // row E right (5 keys)
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI(KC_W),
    // Thumb row F top left (2 keys)
    KC_TRNS, KC_TRNS,
    // Thumb row F top right (2 keys)
    KC_TRNS, KC_TRNS,
    // Thumb row G just the middle 1U keys (2 keys)
    KC_TRNS, KC_TRNS,
    // Thumb row H bottom left (mixed 2U 2U 1U) (3 keys)
    KC_TRNS, KC_TRNS, MT(MOD_LCTL, KC_F11),
    // Thumb row H bottm right (mixed 2U 2U 1U) (3 keys)
    KC_TRNS, KC_TRNS, KC_TRNS),
 [NAVPUN] = LAYOUT_ergodox_pretty(
    // row A left (7 keys)
    RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // row A right (7 keys)
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // row B left (has inner column) (7 keys)
    KC_TRNS, LGUI(KC_TAB), KC_BSPC, KC_SPC, KC_DEL, KC_PGUP, KC_TRNS,
    // row B right (has inner column) (7 keys)
    KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, LSFT(KC_GRV), KC_EQL, KC_TRNS,
    // row C left (no inner column) (6 keys)
    KC_TRNS, KC_TAB, KC_LEFT, KC_UP, KC_RGHT, KC_ENT,
    // row C right (no inner column) (6 keys)
    KC_TRNS, KC_LPRN, KC_RPRN, KC_SLSH, KC_GRV, KC_TRNS,
    // row D left (has inner column) (7 keys)
    KC_TRNS, KC_HOME, KC_HOME, KC_DOWN, KC_END, KC_PGDN, KC_TRNS,
    // row D right (has inner column) (7 keys)
    KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS,
    // row E left (5 keys)
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // row E right (5 keys)
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // Thumb row F top left (2 keys)
    KC_TRNS, KC_TRNS,
    // Thumb row F top right (2 keys)
    KC_TRNS, KC_TRNS,
    // Thumb row G just the middle 1U keys (2 keys)
    KC_TRNS, KC_TRNS,
    // Thumb row H bottom left (mixed 2U 2U 1U) (3 keys)
    KC_TRNS, KC_TRNS, KC_TRNS,
    // Thumb row H bottm right (mixed 2U 2U 1U) (3 keys)
    KC_TRNS, KC_TRNS, KC_TRNS),
 [NAVNUM] = LAYOUT_ergodox_pretty(
   // row A left (7 keys)
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
   // row A right (7 keys)
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
   // row B left (has inner column) (7 keys)
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
   // row B right (has inner column) (7 keys)
   KC_TRNS, KC_COMM, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS,
   // row C left (no inner column) (6 keys)
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
   // row C right (no inner column) (6 keys)
   KC_DOT, KC_4, KC_5, KC_6, KC_0, KC_TRNS,
   // row D left (has inner column) (7 keys)
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
   // row D right (has inner column) (7 keys)
   KC_TRNS, LSFT(KC_COLN), KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS,
   // row E left (5 keys)
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
   // row E right (5 keys)
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
   // Thumb row F top left (2 keys)
   KC_TRNS, KC_TRNS,
   // Thumb row F top right (2 keys)
   KC_TRNS, KC_TRNS,
   // Thumb row G just the middle 1U keys (2 keys)
   KC_TRNS, KC_TRNS,
   // Thumb row H bottom left (mixed 2U 2U 1U) (3 keys)
   KC_TRNS, KC_TRNS, KC_TRNS,
   // Thumb row H bottom right (mixed 2U 2U 1U) (3 keys)
   KC_TRNS, KC_TRNS, KC_TRNS),
 [NUMNAV] = LAYOUT_ergodox_pretty(
    // row A left (7 keys)
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // row A right (7 keys)
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // row B left (has inner column) (7 keys)
    KC_TRNS, KC_TRNS, KC_9, KC_8, KC_7, KC_W, KC_TRNS,
    // row B right (has inner column) (7 keys)
    KC_TRNS, KC_PGUP, KC_BSPC, KC_SPC, KC_DEL, RGUI(KC_TAB), KC_TRNS,
    // row C left (no inner column) (6 keys)
    KC_TRNS, KC_0, KC_6, KC_5, KC_4, KC_E,
    // row C right (no inner column) (6 keys)
    KC_ENT, KC_LEFT, KC_UP, KC_RGHT, KC_TAB, KC_TRNS,
    // row D left (has inner column) (7 keys)
    KC_TRNS, KC_TRNS, KC_3, KC_2, KC_1, LSFT(KC_Z), KC_TRNS,
    // row D right (has inner column) (7 keys)
    KC_TRNS, KC_PGDN, KC_HOME, KC_DOWN, KC_END, KC_PGDN, KC_TRNS,
    // row E left (5 keys)
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // row E right (5 keys)
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // Thumb row F top left (2 keys)
    KC_TRNS, KC_TRNS,
    // Thumb row F top right (2 keys)
    KC_TRNS, KC_TRNS,
    // Thumb row G just the middle 1U keys (2 keys)
    KC_TRNS, KC_TRNS,
    // Thumb row H bottom left (mixed 2U 2U 1U) (3 keys)
    KC_TRNS, KC_TRNS, KC_TRNS,
    // Thumb row H bottom right (mixed 2U 2U 1U) (3 keys)
    KC_TRNS, KC_TRNS, KC_TRNS),
};


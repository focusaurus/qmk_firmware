#include QMK_KEYBOARD_H

#define LEADER KC_F10
#define FUZZBALL KC_F11
#define SNIPPET KC_F12

enum {

  TD_COMMA,
  TD_LBRC,
  TD_RBRC,
  TD_SEMI

};

qk_tap_dance_action_t tap_dance_actions[] = {

  [TD_COMMA] = ACTION_TAP_DANCE_DOUBLE(KC_COMMA, SNIPPET),
  [TD_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, LSFT(KC_COMMA)),
  [TD_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, LSFT(KC_DOT)),
  [TD_SEMI] = ACTION_TAP_DANCE_DOUBLE(KC_COLN, KC_SCLN)

};

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

/* layer constants */
enum {
  DVORAK,
  MACOS,
  EDIT,
  NUMBERS,
  BANG,
  KBFN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[DVORAK] = LAYOUT_ergodox(

// left hand
// row A left (7 keys)
KC_GESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_NO,
// row B left (has inner column) (7 keys)
KC_TAB, KC_QUOT, TD(TD_COMMA), LALT_T(KC_DOT), LCTL_T(KC_P), KC_Y, LCTL(KC_TAB),
// row C left (no inner column) (6 keys)
LCTL_T(KC_ESC), MT(MOD_LGUI | MOD_LALT, KC_A), KC_O, KC_E, KC_U, KC_I,
// row D left (has inner column) (7 keys)
KC_NO, TD(TD_SEMI), KC_Q, KC_J, KC_K, KC_X, LCTL(LSFT(KC_TAB)),
// row E left (5 keys)
KC_F1, KC_F2, KC_F3, KC_F4, MT(MOD_LALT, KC_BSPC),
// Left thumb cluster (5 keys)
KC_LEFT, KC_RIGHT,
TG(MACOS),
LT(EDIT, LEADER), OSM(MOD_LSFT), LT(KBFN, FUZZBALL),

// right hand
// row A right (7 keys)
KC_MUTE, KC_F6, KC_F7, KC_F8, KC_F9, KC_EQL, KC_BSLS,
// row B right (has inner column) (7 keys)
KC_VOLU, KC_F, RCTL_T(KC_G), LALT_T(KC_C), KC_R, KC_L, KC_SLSH,
// row C right (no inner column) (6 keys)
KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS,
// row D right (has inner column) (7 keys)
KC_VOLD, KC_B, KC_M, KC_W, KC_V, LT(BANG, KC_Z), KC_NO,
// row E right (5 keys)
KC_DEL, OSM(MOD_RSFT), OSM(MOD_LALT), OSM(MOD_RGUI), LGUI(LALT(KC_X)),
// right thumb cluster (5 keys)
KC_LEFT, KC_RIGHT,
TG(EDIT),
OSM(MOD_RCTL), LT(BANG, KC_ENT), LT(NUMBERS, KC_SPC)

),

[MACOS] = LAYOUT_ergodox(

// All this layer does is swap GUI/CTL
// mostly for copy/paste/new-tab parity

// left hand
// row A left (7 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// row B left (has inner column) (7 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// row C left (no inner column) (6 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// row D left (has inner column) (7 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// row E left (5 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// thumb cluster left
KC_TRNS, KC_TRNS,
KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS,

// right hand
// row A right (7 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// row B right (has inner column) (7 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// row C right (no inner column) (6 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// row D right (has inner column) (7 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// row E right (5 keys)
OSM(MOD_RGUI), KC_TRNS, KC_TRNS, OSM(MOD_RCTL), KC_TRNS,
// thumb cluster right
KC_TRNS, KC_TRNS,
KC_TRNS,
OSM(MOD_RGUI), KC_TRNS, KC_TRNS

),
[EDIT] = LAYOUT_ergodox(

// left hand
// row A left (7 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// row B left (has inner column) (7 keys)
KC_TRNS, LGUI(KC_TAB), KC_BSPC, KC_SPC, KC_DEL, KC_PGUP, KC_TRNS,
// row C left (no inner column) (6 keys)
KC_TRNS, KC_TAB, KC_LEFT, KC_UP, KC_RIGHT, KC_ENT,
// row D left (has inner column) (7 keys)
LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), KC_HOME, KC_DOWN, KC_END, KC_PGDN, KC_TRNS,
// row E left (5 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// thumb cluster left
KC_TRNS, KC_TRNS,
KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS,

// right hand
// row A right (7 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// row B right (has inner column) (7 keys)
KC_TRNS, RSFT(KC_EQL), KC_LCBR, KC_RCBR, LSFT(KC_GRV), KC_EQL, KC_TRNS,
// row C right (no inner column) (6 keys)
KC_EQL, KC_LPRN, KC_RPRN, KC_SLSH, KC_GRV, KC_TRNS,
// row D right (has inner column) (7 keys)
KC_TRNS, KC_BSLS, TD(TD_LBRC), TD(TD_RBRC), KC_PIPE, RSFT(KC_MINUS), KC_TRNS,
// row E right (5 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// thumb cluster right
KC_TRNS, KC_TRNS,
KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS

),
[NUMBERS] = LAYOUT_ergodox(

// HEADS UP: This is a copy of the left hand from the EDIT
// layer because QMK layers are dumb and don't really
// work in any kind of reasonable way.
// Without this copying, the default layer of DVORAK would fire
// which is not what I want
// left hand
// row A left (7 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// row B left (has inner column) (7 keys)
KC_TRNS, LGUI(KC_TAB), KC_BSPC, KC_SPC, KC_DEL, KC_PGUP, KC_TRNS,
// row C left (no inner column) (6 keys)
KC_TRNS, KC_TAB, KC_LEFT, KC_UP, KC_RIGHT, KC_ENT,
// row D left (has inner column) (7 keys)
LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), KC_HOME, KC_DOWN, KC_END, KC_PGDN, KC_TRNS,
// row E left (5 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// thumb cluster left
KC_TRNS, KC_TRNS,
KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS,

// right hand
// row A right (7 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// row B right (has inner column) (7 keys)
KC_TRNS, KC_COMMA, KC_7, KC_8, KC_9, KC_W, KC_TRNS,
// row C right (no inner column) (6 keys)
KC_DOT, KC_4, KC_5, KC_6, KC_0, KC_TRNS,
// row D right (has inner column) (7 keys)
KC_TRNS, KC_COLON, KC_1, KC_2, KC_3, KC_ENT, KC_TRNS,
// row E right (5 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// thumb cluster right
KC_TRNS, KC_TRNS,
KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS

),
[BANG] = LAYOUT_ergodox(

// HEADS UP: This is a copy of the left hand from the EDIT
// layer because QMK layers are dumb and don't really
// work in any kind of reasonable way.
// Without this copying, the default layer of DVORAK would fire
// which is not what I want
// left hand
// row A left (7 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// row B left (has inner column) (7 keys)
KC_TRNS, LGUI(KC_TAB), KC_BSPC, KC_SPC, KC_DEL, KC_PGUP, KC_TRNS,
// row C left (no inner column) (6 keys)
KC_TRNS, KC_TAB, KC_LEFT, KC_UP, KC_RIGHT, KC_ENT,
// row D left (has inner column) (7 keys)
LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), KC_HOME, KC_DOWN, KC_END, KC_PGDN, KC_TRNS,
// row E left (5 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// thumb cluster left
KC_TRNS, KC_TRNS,
KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS,

// right hand
// row A right (7 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// row B right (has inner column) (7 keys)
KC_TRNS, LSFT(KC_EQL), LSFT(KC_7), LSFT(KC_8), KC_SLSH, KC_NO, KC_NO,
// row C right (no inner column) (6 keys)
KC_EQL, LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), KC_MINUS, KC_PIPE,
// row D right (has inner column) (7 keys)
// TODO maybe combo for a pair of curly braces for bash vars?
KC_TRNS, KC_NO, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), KC_QUES, KC_NO,
// row E right (5 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// thumb cluster right
KC_TRNS, KC_TRNS,
KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS
),

[KBFN] = LAYOUT_ergodox(
// left hand
// row A left (7 keys)
RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// row B left (has inner column) (7 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// row C left (no inner column) (6 keys)
KC_CAPSLOCK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// row D left (has inner column) (7 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// row E left (5 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// thumb cluster left
KC_TRNS, KC_TRNS,
KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS,

// right hand
// row A right (7 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// row B right (has inner column) (7 keys)
KC_TRNS, KC_TRNS, KC_F7, KC_F9, KC_F9, KC_F12, KC_TRNS,
// row C right (no inner column) (6 keys)
KC_TRNS, KC_F4, KC_F6, KC_F6, KC_F11, KC_TRNS,
// row D right (has inner column) (7 keys)
KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F1, KC_F10,
// row E right (5 keys)
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// thumb cluster right
KC_TRNS, KC_TRNS,
KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS
)

};

/* void keyboard_post_init_user(void) { */
/*   layer_on(EDIT); */
/* } */

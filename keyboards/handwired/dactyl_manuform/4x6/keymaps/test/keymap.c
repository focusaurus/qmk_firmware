#include QMK_KEYBOARD_H


#define _BASE 0
#define _RAISE 1
#define _LOWER 2

// Fillers to make layering more clear

#define ____ KC_TRNS

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty)
 * +-----------------------------------------+                             +-----------------------------------------+
 * | ESC  |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | TAB  |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | SHFT |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |      |
 * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
 *               |  [   |   ]  |                                                         |      |      |
 *               +-------------+-------------+                             +-------------+-------------+
 *                             |      |      |                             |      |      |
 *                             |------+------|                             |------+------|
 *                             |      |      |                             |      |      |
 *                             +-------------+                             +-------------+
 *                                           +-------------+ +-------------+
 *                                           |      |      | |      |      |
 *                                           |------+------| |------+------|
 *                                           |      |      | |      |      |
 *                                           +-------------+ +-------------+
 */

[_BASE] = LAYOUT( \
    KC_A, KC_B, KC_C, KC_D, KC_E, KC_F,               LSFT(KC_A), LSFT(KC_B), LSFT(KC_C), LSFT(KC_D), LSFT(KC_E), LSFT(KC_F), \
    KC_G, KC_H, KC_I, KC_J, KC_K, KC_L,               LSFT(KC_G), LSFT(KC_H), LSFT(KC_I), LSFT(KC_J), LSFT(KC_K), LSFT(KC_L), \
    KC_M, KC_N, KC_O,KC_P, KC_Q, KC_R,               LSFT(KC_M), LSFT(KC_N), LSFT(KC_O), LSFT(KC_P), LSFT(KC_Q), LSFT(KC_R), \
                    KC_S, KC_T,                                            LSFT(KC_S), LSFT(KC_T), \
                                    KC_U, KC_V,             LSFT(KC_U), LSFT(KC_V), \
                                    KC_W, KC_X,            LSFT(KC_W), LSFT(KC_X), \
                                    KC_Y, KC_Z,             LSFT(KC_Y), LSFT(KC_Z) \
),

[_LOWER] = LAYOUT(
    _______,_______,_______,_______,_______,KC_LBRC,            KC_RBRC, KC_P7, KC_P8,  KC_P9,  RESET,  KC_PLUS,   \
    _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,            KC_RPRN, KC_P4, KC_P5,  KC_P6,  KC_MINS,KC_PIPE,   \
    _______,_______,_______,_______,_______,_______,            _______, KC_P1, KC_P2,  KC_P3,  KC_EQL, KC_UNDS,   \
                                            _______,KC_PSCR,    _______, KC_P0,                                    \
                                            _______,_______,    _______,_______,                                   \
                                            _______,_______,    _______,_______,                                   \
                                            _______,_______,    _______,_______                                    \
),

[_RAISE] = LAYOUT(
    _______,RESET,  _______,_______,_______,KC_LBRC,            KC_RBRC,_______,KC_NLCK,KC_INS, KC_SLCK,KC_MUTE,   \
    _______,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,            KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU,   \
    _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,KC_VOLD,   \
                                            _______,_______,    KC_EQL, _______,                                   \
                                            _______,_______,    _______,_______,                                   \
                                            _______,_______,    _______,_______,                                   \
                                            _______,_______,    _______,_______                                    \
)
};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

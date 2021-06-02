#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {

    DVORAK

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [DVORAK] = LAYOUT(

        KC_QUOTE, KC_COMMA, KC_DOT, KC_P, KC_Y,
        KC_A, KC_O, KC_E, KC_U, KC_I,
        KC_SCLN, KC_Q, KC_J, KC_K, KC_X,
        KC_LCTL, KC_LSFT, KC_LALT,
        KC_BSPC, KC_F10, KC_F11,

        KC_F, KC_G, KC_C, KC_R, KC_L,
        KC_D, KC_H, KC_T, KC_N, KC_S,
        KC_B, KC_M, KC_W, KC_V, KC_Z,
        KC_LALT, KC_RSFT, KC_RCTL,
        KC_ENT, KC_SPC, KC_ESC

            ),
};

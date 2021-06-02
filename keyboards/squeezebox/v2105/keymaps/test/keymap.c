#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names { TEST };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [TEST] = LAYOUT(
        KC_A, KC_B, KC_C, KC_D, KC_E,
        KC_F, KC_G, KC_H, KC_I, KC_J,
        KC_K, KC_L, KC_M, KC_N, KC_O,
        KC_1, KC_2, KC_3,
        KC_4, KC_5, KC_6,

        LSFT(KC_E), LSFT(KC_D), LSFT(KC_C), LSFT(KC_B), LSFT(KC_A),
        LSFT(KC_J), LSFT(KC_I), LSFT(KC_H), LSFT(KC_G), LSFT(KC_F),
        LSFT(KC_O), LSFT(KC_N), LSFT(KC_M), LSFT(KC_L), LSFT(KC_K),
        LSFT(KC_3), LSFT(KC_2), LSFT(KC_1),
        LSFT(KC_6), LSFT(KC_5), LSFT(KC_4)
  ),
};

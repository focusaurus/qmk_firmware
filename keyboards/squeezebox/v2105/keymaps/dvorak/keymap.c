#include QMK_KEYBOARD_H

#define LEADER KC_F10
#define FUZZBALL KC_F11
#define SNIPPETS KC_F12

// Defines names for use in layer keycodes and the keymap
enum layer_names {

    DVORAK,

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [DVORAK] = LAYOUT(

        // TODO 1-finger combos for uk, ej, oq
        KC_QUOTE, KC_COMMA, LALT_T(KC_DOT), LCTL_T(KC_P), KC_Y,
        MT(MOD_LGUI | MOD_LALT, KC_A), KC_O, KC_E, KC_U, KC_I,
        KC_SCLN, KC_Q, KC_J, KC_K, KC_X,
        OSM(MOD_LCTL), OSM(MOD_LSFT), KC_SPC,
        KC_ENT, LEADER, MT(MOD_LGUI, FUZZBALL),

        // TODO 1-finger combos for hm, tw, nv, sz
        KC_F, RCTL_T(KC_G), LALT_T(KC_C), KC_R, KC_L,
        KC_D, KC_H, KC_T, KC_N, KC_S,
        KC_B, KC_M, KC_W, KC_V, KC_Z,
        // TODO if top row mods work out can use these for something else
        OSM(MOD_LALT), OSM(MOD_RSFT), KC_ENT,
        // TODO LE3 available for a better layer
        KC_SPC, KC_SPC, KC_ESC

            ),
};

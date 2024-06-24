#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _RGBTEST 1
#define _CLEAR 2

// Some basic macros

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x6(
        // left hand
        KC_0,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,
        KC_9,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,
        KC_Y,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
        KC_U,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,
                        KC_I,   KC_O,
                                    KC_A,
                                    KC_L, KC_N,
                                    KC_M, KC_DOT,
        // right hand
        KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,
        KC_RBRC,KC_Y,   KC_U,    KC_I,    KC_O,     KC_P,
        KC_R,   KC_H,   KC_J,    KC_K,    KC_L,     KC_W,
        KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_E,
                        KC_LEFT, KC_UP,
             KC_0,
             KC_2, KC_3,
             KC_4
    )
};

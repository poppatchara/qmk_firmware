#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// flash command
// qmk flash -kb pop_dactyl -km test -bl uf2-split-right -j 16

#define Layer_main 0
#define Layer_utils 1
#define _CLEAR 2

// Some basic macros

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [Layer_main] = LAYOUT_5x6(
        // left hand
        KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,
        KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,
                                KC_COMM,    KC_DOT,

                                            KC_1,       KC_2,       KC_3,
                                            LT(Layer_utils,KC_4),   KC_5,

        // right hand
        KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,
        KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,
        KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
        KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,    KC_UP,
                                KC_LEFT,    KC_UP,

        KC_1,       KC_2,       KC_3,
        KC_4,       LT(Layer_utils, KC_5)
    ),

    [Layer_utils] = LAYOUT_5x6(
        // left hand
        XXXXXXX,    XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       QK_BOOT,
        XXXXXXX,    XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,
        XXXXXXX,    XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,
        XXXXXXX,    XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,
                                XXXXXXX,    XXXXXXX,
                                            XXXXXXX,       XXXXXXX,       XXXXXXX,
                                            XXXXXXX,       XXXXXXX,

        // right hand
        QK_BOOT,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,
        XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,
        XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,
        XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,
                                XXXXXXX,    XXXXXXX,

        XXXXXXX,       XXXXXXX,       XXXXXXX,
        XXXXXXX,       XXXXXXX
    )
};

#ifdef OLED_ENABLE
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    render_logo();
    return false;
}
#endif

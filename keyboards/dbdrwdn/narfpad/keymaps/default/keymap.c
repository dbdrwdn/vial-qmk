#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_A,   KC_B,   KC_C, KC_D,
        KC_E,   KC_F,   KC_G,
        KC_H,   KC_I,   KC_J,   KC_K
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code16(KC_L);
        } else {
            tap_code16(KC_M);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code16(KC_N);
        } else {
            tap_code16(KC_O);
        }
    }
    return false;
}

#include QMK_KEYBOARD_H

#include "quantum/keymap_extras/keymap_hungarian.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _ABC 0
#define _SYM 1
#define _MSC 2
#define _NAV 3
#define _NUM 4


#define __MC OSM(MOD_LCTL)
#define __MG OSM(MOD_LGUI)
#define __MA OSM(MOD_LALT)
#define __MS OSM(MOD_LSFT)


enum custom_keycodes {
  MY_COMM = SAFE_RANGE,
  MY_DOT,
  MY_DASH,
  MY_EXLM,
  MY_QST
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // SEND_STRING is software layout sensitive --> simulate US QUERTY
  switch (keycode) {
    case MY_COMM:
      if (record->event.pressed) {
        clear_oneshot_mods();
        SEND_STRING(", ");
      }
      break;
    case MY_DOT:
      if (record->event.pressed) {
        clear_oneshot_mods();
        SEND_STRING(". ");
        set_oneshot_mods(MOD_LSFT);
      }
      break;
    case MY_DASH:
      if (record->event.pressed) {
        clear_oneshot_mods();
        SEND_STRING(" // "); // US QUERTY "/" == HU QWERTZ "-"
      }
      break;
    case MY_EXLM:
      if (record->event.pressed) {
        clear_oneshot_mods();
        SEND_STRING("$ "); // US QUERTY "$" == HU QWERTZ "!"
        set_oneshot_mods(MOD_LSFT);
      }
      break;
    case MY_QST:
      if (record->event.pressed) {
        clear_oneshot_mods();
        SEND_STRING("< "); // US QUERTY "<" == HU QWERTZ "?"
        set_oneshot_mods(MOD_LSFT);
      }
      break;

  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_ABC] = LAYOUT(
    HU_Q,    HU_W,    HU_F,    HU_P,    HU_B,             HU_J,    HU_L,    HU_U,      HU_Y,      HU_AA,
    HU_A,    HU_R,    HU_S,    HU_T,    HU_G,             HU_M,    HU_N,    HU_E,      HU_I,      HU_O,
    HU_Z,    HU_X,    HU_C,    HU_D,    HU_V,             HU_K,    HU_H,    OSL(_SYM), OSL(_MSC), HU_EE,
    CTL_T(KC_TAB), LT(_NAV, KC_SPC), MEH_T(KC_ENT),       OSM(MOD_LSFT), LT(_NUM, KC_BSPC), GUI_T(KC_ESC)
  ),

  [_SYM] = LAYOUT(
    HU_MORE, HU_RCBR, HU_RBRC, HU_RPRN, HU_BSLS,          HU_TILD, HU_CIRC, XXXXXXX, XXXXXXX, HU_AT,
    HU_LESS, HU_LCBR, HU_LBRC, HU_LPRN, HU_SLSH,          HU_PERC, HU_ASTR, XXXXXXX, HU_COLN, HU_SCLN,
    HU_HASH, HU_DLR,  HU_QST,  HU_EXLM, HU_PIPE,          HU_AMPR, HU_EQL,  _______, HU_PLUS, HU_GRV,
                      HU_UNDS, HU_QUOT, HU_DQOT,          HU_DOT,  HU_COMM, HU_MINS
  ),

  [_MSC] = LAYOUT(
    _______, HU_UEE,  HU_UE,   HU_UU,   _______,          _______, _______, _______, _______,   _______, 
    HU_II,   HU_OEE,  HU_OE,   HU_OO,   _______,          _______, _______, _______, _______,   _______, 
    _______, _______, MY_QST,  MY_EXLM, _______,          _______, _______, _______, OSL(_MSC), _______, 
                      HU_UNDS, HU_DQOT, HU_QUOT,          MY_DOT,  MY_COMM, MY_DASH
  ),

  [_NAV] = LAYOUT(
    KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,          KC_WH_U, KC_PGUP, KC_SPC,  KC_PGDN, KC_INS,
    __MG,    __MA,    __MS,    __MC,    KC_VOLD,          KC_WH_D, KC_LEFT, KC_UP,   KC_RGHT, KC_TAB,
    C(HU_Z), C(HU_X), C(HU_C), C(HU_D), C(HU_V),          KC_APP,  KC_HOME, KC_DOWN, KC_END,  KC_ENT,
                      _______, _______, _______,          KC_DEL,  KC_BSPC, KC_ESC
  ),

  [_NUM] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            HU_MINS, HU_7,    HU_8,    HU_9,    KC_BSPC,
    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,           HU_0,    HU_4,    HU_5,    HU_6,    HU_DOT,
    KC_F11,  KC_F12,  KC_F13,  KC_PSCR, KC_PAUS,          HU_PLUS, HU_1,    HU_2,    HU_3,    HU_COMM,
                      KC_TAB,  KC_SPC,  KC_ENT,           _______, _______, _______
  )

};



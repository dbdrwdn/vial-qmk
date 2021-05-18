#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4652 // "FR"
#define PRODUCT_ID      0x5349
#define DEVICE_VER      0x0001
#define MANUFACTURER    FR4Boards
#define PRODUCT         Southpaw75ISO

/* key matrix size */
#define MATRIX_ROWS 9
#define MATRIX_COLS 9

/* key matrix pins */
#define MATRIX_ROW_PINS { D3, D2, D1, D0, D4, C6, D7, E6, B4 }
#define MATRIX_COL_PINS { B5, F4, F5, F6, F7, B1, B3, B2, B6 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* vial settings */
#define VIAL_KEYBOARD_UID {0x5D, 0xDC, 0xDF, 0x29, 0xAF, 0xEB, 0xE3, 0x56}
#define VIAL_UNLOCK_COMBO_ROWS { 3 }
#define VIAL_UNLOCK_COMBO_COLS { 8 }
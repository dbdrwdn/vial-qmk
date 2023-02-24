#pragma once

#define MATRIX_ROWS 8
#define MATRIX_COLS 10

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

// wiring of each half
#define MATRIX_ROW_PINS { F6, D7, B3, E6 }
#define MATRIX_COL_PINS { F4, D4, F5, B1, B2 }

#define SOFT_SERIAL_PIN D2

#define USE_SERIAL

#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE

#define RGB_DI_PIN D3

#define ENCODERS_PAD_A {B5}
#define ENCODERS_PAD_B {B4}

#define ENCODER_RESOLUTION 2

#define DEBOUNCE 5

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_SPLIT
  #define RGBLED_SPLIT { 18, 18 }
  #define RGBLED_NUM 36
  #define RGBLIGHT_HUE_STEP 16
  #define RGBLIGHT_SAT_STEP 16
  #define RGBLIGHT_VAL_STEP 16
  #define RGBLIGHT_LIMIT_VAL 150 /* The maximum brightness level for RGBLIGHT_ENABLE */
  #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
#endif
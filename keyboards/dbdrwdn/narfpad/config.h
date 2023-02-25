// Copyright 2023 Sebastian Stumpf (@sebastian-stumpf)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define MATRIX_ROW_PINS { GP6, GP7, GP0 }
#define MATRIX_COL_PINS { GP26, GP27, GP28, GP29 }
#define DIODE_DIRECTION COL2ROW

#define ENCODERS_PAD_A { GP3, GP2 }
#define ENCODERS_PAD_B { GP4, GP1 }

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

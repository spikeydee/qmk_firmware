#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    QMK
#define PRODUCT         lanc keyboard

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 10

/* key matrix pins */
#define MATRIX_ROW_PINS { D5, B0, B1, C7 }
#define MATRIX_COL_PINS { E6, B3, B7, D7, D6, D4, D3, D2, D1, D0 }
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

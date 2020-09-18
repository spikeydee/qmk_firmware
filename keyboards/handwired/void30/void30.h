#pragma once

#include "quantum.h"
#include QMK_KEYBOARD_H

#define KC_NP KC_NO // key is not present
#define KC_NA KC_NO // present but not available for use
#define KC_NU KC_NO // available but not used
#define XXX   KC_NO // lets just keep this here

// non-KC_ keycodes
#define KC_RST RESET
#define KC_TOG RGB_TOG
#define KC_MOD RGB_MOD
#define KC_HUI RGB_HUI
#define KC_SAI RGB_SAI
#define KC_VAI RGB_VAI

#define LAYOUT( \
  K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,\
  K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,\
  K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29 \
) { \
	{ K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09 }, \
	{ K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19 }, \
	{ K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29 }  \
}

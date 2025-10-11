#include QMK_KEYBOARD_H
#include "spikeydee.h" 

// Combos & declarations

enum layers { BASE, GAME, MEDR, NAVR, MOUR, NSSL, NSL, FUNL };

enum combo_events {
  MEDR_COMBO,
  FUNL_COMBO,

  DEL_COMBO,
  BTN3_COMBO,
  MUTE_COMBO,

  DOT_COMBO,
  LPRN_COMBO,
  APP_COMBO,
};


const uint16_t PROGMEM medr_combo[] = {LT(NAVR, KC_SPC), LT(MOUR, KC_TAB), COMBO_END};
const uint16_t PROGMEM funl_combo[] = {LT(NSSL, KC_ENT), LT(NSL, KC_BSPC), COMBO_END};

const uint16_t PROGMEM del_combo[]  = {KC_ENT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM btn3_combo[] = {MS_BTN1, MS_BTN2, COMBO_END};
const uint16_t PROGMEM mute_combo[] = {KC_MSTP, KC_MPLY, COMBO_END};


const uint16_t PROGMEM dot_combo[]  = {KC_0, KC_MINS, COMBO_END};
const uint16_t PROGMEM lprn_combo[] = {KC_RPRN, KC_UNDS, COMBO_END};
const uint16_t PROGMEM app_combo[]  = {KC_SPC, KC_TAB, COMBO_END};


combo_t key_combos[COMBO_COUNT]	= {
	[MEDR_COMBO] = COMBO(medr_combo, LT(MEDR, KC_ESC)),
    [FUNL_COMBO] = COMBO(funl_combo, LT(FUNL, KC_DEL)),
	
	[DEL_COMBO]	 = COMBO(del_combo, KC_DEL),
	[BTN3_COMBO] = COMBO(btn3_combo, MS_BTN3),	
	[MUTE_COMBO] = COMBO(mute_combo, KC_MUTE),
	
	
	[DOT_COMBO] = COMBO(dot_combo, KC_DOT),
	[LPRN_COMBO] = COMBO(lprn_combo, KC_LPRN),
	[APP_COMBO] = COMBO(app_combo, KC_APP),
};

layer_state_t layer_state_set_user(layer_state_t const state) {
	if (layer_state_is(GAME)) {
		combo_disable();
	} else {
		combo_enable();
	}
	return state;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [BASE] = LAYOUT_spikeydee(
    KC_Q,              KC_D,              KC_R,              KC_W,              KC_B,              KC_J,              KC_F,              KC_U,              KC_P,              KC_QUOT,
    LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_H),      LSFT_T(KC_T),      KC_G,              KC_Y,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_O),      LGUI_T(KC_I),
    KC_Z,              KC_X,	          KC_M,              KC_C,              KC_V,              KC_K,              KC_L,              KC_COMM,           KC_DOT,		       KC_SLSH,
    KC_NP,             KC_NP,             LT(MEDR, KC_ESC),  LT(NAVR, KC_SPC),  LT(MOUR, KC_TAB),  LT(NSSL, KC_ENT),  LT(NSL, KC_BSPC),  LT(FUNL, KC_DEL),  KC_NP,             KC_NP
   ),  
   [NAVR] = LAYOUT_spikeydee(
    QK_BOOT,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NU,   KC_PGUP, KC_UP,   KC_PGDN, KC_NU,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NA,   KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_NU,
    KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,	 KC_NU,   KC_HOME, KC_INS,  KC_END,  KC_NU,
    KC_NP,   KC_NP,   KC_NA,   KC_NA,   KC_NA,   KC_ENT,  KC_BSPC, KC_DEL,  KC_NP,   KC_NP
   ),
   [MOUR] = LAYOUT_spikeydee(
    QK_BOOT,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NU,   MS_WHLU, MS_UP, MS_WHLD, KC_NU,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NA,   KC_NU,   MS_LEFT, MS_DOWN, MS_RGHT, KC_NU,
    KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,	 KC_NU,   MS_WHLL, KC_NU, MS_WHLR, KC_NU,
    KC_NP,   KC_NP,   KC_NA,   KC_NA,   KC_NA,   MS_BTN1, MS_BTN2, MS_BTN3, KC_NP,   KC_NP
   ),
   [MEDR] = LAYOUT_spikeydee(
    QK_BOOT,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   BL_TOGG, BL_UP,  KC_VOLU, BL_DOWN,  BL_BRTG,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NA,   KC_NU,   KC_MPRV, KC_VOLD, KC_MNXT, KC_NU,
    KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NU,   KC_NU,   KC_NU, 	KC_NU,   KC_NU,
    KC_NP,   KC_NP,   KC_NA,   KC_NA,   KC_NA,   KC_MSTP, KC_MPLY, KC_MUTE, KC_NP,   KC_NP
   ),
   [FUNL] = LAYOUT_spikeydee(
    KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, KC_NA,	  KC_NA,   KC_NA,   KC_NA,   QK_BOOT,
    KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL, KC_NA,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, KC_NA,	  KC_NA,   KC_NA,   KC_NA, 	 KC_NA,
    KC_NP,   KC_NP,   KC_APP,  KC_SPC,  KC_TAB,  KC_NA,   KC_NA,   KC_NA,   KC_NP,   KC_NP
   ),
   [NSL] = LAYOUT_spikeydee(
    KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, KC_NA,   KC_NA,   KC_NA,   KC_NA,   QK_BOOT,
    KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  KC_NA,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, KC_NA,   KC_NA,   KC_COMM, KC_DOT,  KC_SLSH,
    KC_NP,   KC_NP,   KC_DOT,  KC_0,    KC_MINS, KC_NA,   KC_NA,   KC_NA,   KC_NP,   KC_NP
   ),
   [NSSL] = LAYOUT_spikeydee(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, KC_NA,   KC_NA,   KC_NA,   KC_NA,   QK_BOOT,
    KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, KC_NA,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, TG(GAME),KC_NA,   KC_COMM, KC_DOT,  KC_SLSH,
    KC_NP,   KC_NP,   KC_LPRN, KC_RPRN, KC_UNDS, KC_NA,   KC_NA,   KC_NA,   KC_NP,   KC_NP
   ),
   [GAME] = LAYOUT_spikeydee(
    KC_ESC,	 KC_Q, 	  KC_W,	   KC_E,    KC_R,    KC_T,	  KC_Y,	   KC_U, 	KC_I,	 KC_O,
    KC_LSFT, KC_A,	  KC_S,	   KC_D, 	KC_F,	 KC_G,	  KC_H,	   KC_J,    KC_K,	 KC_L,
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, 	KC_P,	 KC_SLSH,
    KC_NP,   KC_NP,   KC_LALT, KC_SPC,  KC_TAB,  LT(NSSL, KC_ENT),  LT(NSL, KC_BSPC), KC_DEL,  KC_NP,   KC_NP
   )
};

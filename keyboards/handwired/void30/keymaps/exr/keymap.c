#include QMK_KEYBOARD_H
// Combos & declarations
enum combo_events {
  PLUS_COMBO,
  MINS_COMBO,
  ASTR_COMBO,
  SLSH_COMBO,
  EQL_COMBO,
  
  ZERO_COMBO,
  DOT_COMBO,
  UNDS_COMBO,
  LPRN_COMBO,
  RPRN_COMBO,
  
  ESC_COMBO,
  SPC_COMBO,
  TAB_COMBO,
  ENT_COMBO,
  BSPC_COMBO,
  DEL_COMBO,
};

const uint16_t PROGMEM plus_combo[] = {KC_5,KC_6, COMBO_END};
const uint16_t PROGMEM mins_combo[] = {KC_8,KC_9, COMBO_END};
const uint16_t PROGMEM astr_combo[] = {KC_4,KC_5, COMBO_END};
const uint16_t PROGMEM slsh_combo[] = {KC_7,KC_8, COMBO_END};
const uint16_t PROGMEM eql_combo[]  = {KC_6,KC_9, COMBO_END};

const uint16_t PROGMEM zero_combo[] = {KC_1,KC_2, COMBO_END};
const uint16_t PROGMEM dot_combo[]  = {KC_1,KC_5, COMBO_END};
const uint16_t PROGMEM unds_combo[]  = {KC_2,KC_5, COMBO_END};
const uint16_t PROGMEM lprn_combo[]  = {KC_2,KC_4, COMBO_END};
const uint16_t PROGMEM rprn_combo[]  = {KC_2,KC_6, COMBO_END};

const uint16_t PROGMEM esc_combo[]  = {KC_Q,KC_D, COMBO_END};
const uint16_t PROGMEM spc_combo[]  = {KC_D,KC_R, COMBO_END};
const uint16_t PROGMEM tab_combo[]  = {KC_R,KC_W, COMBO_END};
const uint16_t PROGMEM ent_combo[]  = {KC_F,KC_U, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {KC_U,KC_P, COMBO_END};
const uint16_t PROGMEM del_combo[]  = {KC_P,KC_QUOT, COMBO_END};

combo_t key_combos[COMBO_COUNT]	= {
    [PLUS_COMBO] = COMBO(plus_combo, KC_PLUS),
	[MINS_COMBO] = COMBO(mins_combo, KC_MINS),
	[ASTR_COMBO] = COMBO(astr_combo, KC_ASTR),
    [SLSH_COMBO] = COMBO(slsh_combo, KC_SLSH),
    [EQL_COMBO] = COMBO(eql_combo, KC_EQL),
	
    [ZERO_COMBO] = COMBO(zero_combo, KC_0),
    [DOT_COMBO]  = COMBO(dot_combo, KC_DOT),
    [UNDS_COMBO]  = COMBO(unds_combo, KC_UNDS),
    [LPRN_COMBO]  = COMBO(lprn_combo, KC_LPRN),
    [RPRN_COMBO]  = COMBO(rprn_combo, KC_RPRN),
	
    [ESC_COMBO]  = COMBO(esc_combo, KC_ESC),
    [SPC_COMBO]  = COMBO(spc_combo, KC_SPC),
    [TAB_COMBO]  = COMBO(tab_combo, KC_TAB),
    [ENT_COMBO]  = COMBO(ent_combo, KC_ENT),
    [BSPC_COMBO] = COMBO(bspc_combo, KC_BSPC),
	[DEL_COMBO] = COMBO(del_combo, KC_DEL),
};

enum layers { BASE, GAME, MEDR, NAVR, MOUR, NSL, NSSL, FUNL };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#if defined ALPHAS_QWERTY
  [BASE] = LAYOUT(
    KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,
    LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_D),      LSFT_T(KC_F),      KC_G,              KC_H,              RSFT_T(KC_J),      RCTL_T(KC_K),      RALT_T(KC_L),      RGUI_T(KC_QUOT),
    KC_Z,              KC_X,		      KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           KC_DOT, 		   KC_SLSH
  ),
#elif defined ALPHAS_COLEMAKDH
  [BASE] = LAYOUT(
    KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,
    LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,              KC_M,              RSFT_T(KC_N),      RCTL_T(KC_E),      RALT_T(KC_I),      RGUI_T(KC_O),
    KC_Z,              KC_X,      		  KC_C,              KC_D,              KC_V,              KC_K,              KC_H,              KC_COMM,           KC_DOT,    		   KC_SLSH
  ),
#else
[BASE] = LAYOUT(
    KC_Q,              KC_D,              KC_R,              KC_W,              KC_B,              KC_J,              KC_F,              KC_U,              KC_P,              KC_QUOT,
    LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_H),      LSFT_T(KC_T),      KC_G,              KC_Y,   			  RSFT_T(KC_N),      RCTL_T(KC_E),      RALT_T(KC_O),      RGUI_T(KC_I),
    KC_Z,              KC_X,		      LT(MEDR, KC_M),    LT(NAVR, KC_C),    LT(MOUR, KC_V),    LT(NSSL, KC_K),    LT(NSL, KC_L),     LT(FUNL, KC_COMM), KC_DOT,    		   KC_SLSH
  ),  
#endif
   [NAVR] = LAYOUT(
    KC_RST,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NU,   KC_PGUP, KC_UP,   KC_PGDN, KC_NU,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NA,   KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_HOME,
    KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_ENT,  KC_BSPC, KC_DEL,  KC_INS,  KC_END
  ),
  [MOUR] = LAYOUT(
    KC_RST,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NU,   KC_WH_U, KC_MS_U, KC_WH_D, KC_NU,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NA,   KC_NU,   KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_L,
    KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_BTN1, KC_BTN3, KC_BTN2, KC_NU,   KC_WH_R
  ),
  [MEDR] = LAYOUT(
    KC_RST,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NU,   KC_NU,   KC_VOLU, KC_NU,   KC_NU,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NA,   KC_NU,   KC_MPRV, KC_VOLD, KC_MNXT, KC_NU,
    KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_MSTP, KC_MPLY, KC_MUTE, KC_NU,   KC_NU
  ),
  [FUNL] = LAYOUT(
    KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_RST,
    KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK, KC_NA,   KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, KC_NA,   KC_APP,  KC_NA,   KC_NA,   TG(GAME)
  ),
  [NSL] = LAYOUT(
    KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_RST,
    KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  KC_NA,   KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA
  ),
  [NSSL] = LAYOUT(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_RST,
    KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, KC_NA,   KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA
  ),
  [GAME] = LAYOUT(
    KC_Q,                    KC_D,            KC_R,            KC_W,            KC_B,            KC_J,            KC_F,            KC_U,               KC_P,         KC_QUOT,
    LSFT_T(KC_A),            KC_S,            KC_H,            KC_T,            KC_G,            KC_Y,		      KC_N,            KC_E,               KC_O,         RSFT_T(KC_I),
    LCTL_T(KC_Z),            KC_X,            KC_M,            KC_C,            KC_V,            LT(NSSL, KC_K),  LT(NSL, KC_L),   LT(FUNL, KC_COMM),  KC_DOT,       RCTL_T(KC_SLSH)
  )
};

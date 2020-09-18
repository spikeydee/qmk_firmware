/* Copyright 2019 Danny Nguyen <danny@keeb.io>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
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
  
  ENT_COMBO,
  SPC_COMBO,
  BSPC_COMBO,
  DEL_COMBO,
  TAB_COMBO,
  ESC_COMBO,
  
  HOME_COMBO,
  END_COMBO,
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

const uint16_t PROGMEM ent_combo[]  = {KC_4,KC_6, COMBO_END};
const uint16_t PROGMEM spc_combo[]  = {KC_4,KC_8, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {KC_8,KC_6, COMBO_END};
const uint16_t PROGMEM del_combo[]  = {KC_5,KC_9, COMBO_END};
const uint16_t PROGMEM tab_combo[]  = {KC_7,KC_5, COMBO_END};
const uint16_t PROGMEM esc_combo[]  = {KC_7,KC_9, COMBO_END};

const uint16_t PROGMEM home_combo[] = {KC_LEFT,KC_DOWN, COMBO_END};
const uint16_t PROGMEM end_combo[] = {KC_RGHT,KC_DOWN, COMBO_END};

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
	
    [ENT_COMBO]  = COMBO(ent_combo, KC_ENT),
    [SPC_COMBO]  = COMBO(spc_combo, KC_SPC),
    [BSPC_COMBO] = COMBO(bspc_combo, KC_BSPC),
	[DEL_COMBO] = COMBO(del_combo, KC_DEL),
    [TAB_COMBO]  = COMBO(tab_combo, KC_TAB),
    [ESC_COMBO]  = COMBO(esc_combo, KC_ESC),
	
    [HOME_COMBO] = COMBO(home_combo, KC_HOME),
    [END_COMBO]  = COMBO(end_combo, KC_END),	
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |      | Knob 2: Page Dn/Up |
        | Press: Mute       | Home | Press: Play/Pause  |
        | Hold: Layer 2     | Up   | RGB Mode           |
        | Left              | Down | Right              |
     */
    [0] = LAYOUT(
        KC_7, KC_8, KC_9,
        KC_4, KC_5, KC_6,
        KC_1, KC_2, LT(1, KC_3)
    ),
    /*
        | RESET          | N/A  | Media Stop |
        | Held: Layer 2  | Home | RGB Mode   |
        | Media Previous | End  | Media Next |
     */
    [1] = LAYOUT(
        KC_PGUP  , KC_UP, KC_PGDN,
        KC_LEFT, KC_DOWN, KC_RGHT,
        RESET  , KC_INS , _______
    ),
};

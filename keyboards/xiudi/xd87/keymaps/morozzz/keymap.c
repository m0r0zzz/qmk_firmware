/* Copyright 2018 Alexander Fougner <fougner89 at gmail.com>
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
#include "keycode.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    UC_CCOP = SAFE_RANGE,
    UC_CCCL,
    UC_CCFL
};

/*enum layers {*/
#define L_BASE     0
#define L_MIDI_OCT 1 /*row - octave layout*/
#define L_MIDI_PI  2 /*piano/tracker layout*/
#define L_MIDI_FR  3 /*row - fourths layout*/
#define L_MIDI_FF  4 /*row - fifths layout*/
#define L_FN1      5
#define L_FN2      6
#define L_FN3      7
/*}*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = LAYOUT_tkl_ansi(
	KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,            KC_PSCR, KC_SLCK, KC_PAUS,
	KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_INS,  KC_HOME, KC_PGUP,
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,  KC_DEL,  KC_END,  KC_PGDN,
	KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,                                       
	KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT,           KC_UP,           
	KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                               MO(L_FN1),   KC_RALT, KC_APP,  KC_RCTL,  KC_LEFT, KC_DOWN, KC_RGHT   ),
    [L_FN1] = LAYOUT_tkl_ansi(
	RESET  , DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_LANG1, KC_LANG2, KC_LANG3, KC_LANG4, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC__VOLDOWN, KC__VOLUP, KC_TRNS,  KC_TRNS, BL_TOGG, BL_INC,
	KC_TRNS, RGB_TOG, RGB_VAI, RGB_MOD, RGB_HUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, BL_BRTG, BL_DEC,
	KC_LOCK, KC_TRNS, RGB_VAD, RGB_RMOD,RGB_HUD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,                            
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NK_ON,   NK_OFF,  UC_CCOP, UC_CCCL, UC_CCFL,                   KC_TRNS,           KC_TRNS,         
	KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS,                              KC_TRNS, MO(L_FN2),   KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS   ),
    [L_FN2] = LAYOUT_tkl_ansi(
	KC_TRNS, DYN_REC_START1, DYN_REC_START2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, DF(L_BASE), DF(L_MIDI_OCT), DF(L_MIDI_PI), DF(L_MIDI_FR), DF(L_MIDI_FF), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DYN_REC_STOP,  KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,                            
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,           KC_TRNS,         
	KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS,                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS   ),
    [L_FN3] = LAYOUT_tkl_ansi(
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,                            
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,           KC_TRNS,         
	KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS,                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS   ),
	
	[L_MIDI_OCT] = LAYOUT_tkl_ansi(
	DF(L_BASE), MI_OCT_N2, MI_OCT_N1, MI_OCT_0, MI_OCT_1, MI_OCT_2, MI_OCT_3, MI_OCT_4, MI_OCT_5, MI_OCT_6, MI_OCT_7, MI_OCTD, MI_OCTU,           MI_TRNS_0, KC_TRNS, MI_CH1,
	KC_TRNS, MI_C_3 , MI_Cs_3, MI_D_3 , MI_Ds_3, MI_E_3 , MI_F_3 , MI_Fs_3, MI_G_3 , MI_Gs_3, MI_A_3 , MI_As_3, MI_B_3 ,MI_ALLOFF, MI_TRNSU, MI_MODSU, MI_CHU,
	KC_TRNS, MI_C_2 , MI_Cs_2, MI_D_2 , MI_Ds_2, MI_E_2 , MI_F_2 , MI_Fs_2, MI_G_2 , MI_Gs_2, MI_A_2 , MI_As_2, MI_B_2 ,MI_VEL_10, MI_TRNSD, MI_MODSD, MI_CHD,
	MI_MOD , MI_C_1 , MI_Cs_1, MI_D_1 , MI_Ds_1, MI_E_1 , MI_F_1 , MI_Fs_1, MI_G_1 , MI_Gs_1, MI_A_1 , MI_As_1,          KC_TRNS,                            
	MI_LEG , MI_C   , MI_Cs  , MI_D   , MI_Ds  , MI_E   , MI_F   , MI_Fs  , MI_G   , MI_Gs  , MI_A   ,                   MI_LEG ,           MI_BENDU,         
	MI_PORT, KC_TRNS, MI_SOST,                          MI_SUS ,                              MO(L_FN1), MI_SOST, KC_TRNS, MI_PORT,  MI_VELD, MI_BENDD, MI_VELU   ),
	[L_MIDI_PI] = LAYOUT_tkl_ansi(
	DF(L_BASE), MI_OCT_N2, MI_OCT_N1, MI_OCT_0, MI_OCT_1, MI_OCT_2, MI_OCT_3, MI_OCT_4, MI_OCT_5, MI_OCT_6, MI_OCT_7, MI_OCTD, MI_OCTU,           MI_TRNS_0, KC_TRNS, MI_CH1,
	KC_TRNS, KC_TRNS, MI_Cs_1, MI_Ds_1, KC_TRNS, MI_Fs_1, MI_Gs_1, MI_As_1, KC_TRNS, MI_Cs_2, MI_Ds_2, KC_TRNS, MI_Fs_2,MI_ALLOFF, MI_TRNSU, MI_MODSU, MI_CHU,
	KC_TRNS, MI_C_1 , MI_D_1 , MI_E_1 , MI_F_1 , MI_G_1 , MI_A_1 , MI_B_1 , MI_C_2 , MI_D_2 , MI_E_2 , MI_F_2 , MI_G_2 ,MI_VEL_10, MI_TRNSD, MI_MODSD, MI_CHD,
	MI_MOD , KC_TRNS, MI_Cs  , MI_Ds  , KC_TRNS, MI_Fs  , MI_Gs  , MI_As  , KC_TRNS, MI_Cs_1, MI_Ds_1, KC_TRNS,         KC_TRNS ,                            
	MI_LEG , MI_C   , MI_D   , MI_E   , MI_F   , MI_G   , MI_A   , MI_B   , MI_C_1 , MI_D_1 , MI_E_1 ,                   MI_LEG ,           MI_BENDU,         
	MI_PORT, KC_TRNS, MI_SOST,                          MI_SUS ,                              MO(L_FN1), MI_SOST, KC_TRNS, MI_PORT,  MI_VELD, MI_BENDD, MI_VELU   ),
	[L_MIDI_FR] = LAYOUT_tkl_ansi( /*C F As Ds Gs Cs Fs B E A D G*/
	DF(L_BASE), MI_OCT_N2, MI_OCT_N1, MI_OCT_0, MI_OCT_1, MI_OCT_2, MI_OCT_3, MI_OCT_4, MI_OCT_5, MI_OCT_6, MI_OCT_7, MI_OCTD, MI_OCTU,           MI_TRNS_0, KC_TRNS, MI_CH1,
	KC_TRNS, MI_Ds_1, MI_E_1 , MI_F_1 , MI_Fs_1, MI_G_1 , MI_Gs_1, MI_A_1 , MI_As_1, MI_B_1 , MI_C_2 , MI_Cs_2, MI_D_2 ,MI_ALLOFF, MI_TRNSU, MI_MODSU, MI_CHU,
	KC_TRNS, MI_As  , MI_B   , MI_C_1 , MI_Cs_1, MI_D_1 , MI_Ds_1, MI_E_1 , MI_F_1 , MI_Fs_1, MI_G_1 , MI_Gs_1, MI_A_1 ,MI_VEL_10, MI_TRNSD, MI_MODSD, MI_CHD,
	MI_MOD , MI_F   , MI_Fs  , MI_G   , MI_Gs  , MI_A   , MI_As  , MI_B   , MI_C_1 , MI_Cs_1, MI_D_1 , MI_Ds_1,          KC_TRNS,                            
	MI_LEG , MI_C   , MI_Cs  , MI_D   , MI_Ds  , MI_E   , MI_F   , MI_Fs  , MI_G   , MI_Gs  , MI_A   ,                   MI_LEG ,           MI_BENDU,         
	MI_PORT, KC_TRNS, MI_SOST,                          MI_SUS ,                              MO(L_FN1), MI_SOST, KC_TRNS, MI_PORT,  MI_VELD, MI_BENDD, MI_VELU   ),
	[L_MIDI_FF] = LAYOUT_tkl_ansi( /*C G D A E B Fs Cs Gs Ds As F*/
	DF(L_BASE), MI_OCT_N2, MI_OCT_N1, MI_OCT_0, MI_OCT_1, MI_OCT_2, MI_OCT_3, MI_OCT_4, MI_OCT_5, MI_OCT_6, MI_OCT_7, MI_OCTD, MI_OCTU,           MI_TRNS_0, KC_TRNS, MI_CH1,
	KC_TRNS, MI_A_1 , MI_As_1, MI_B_1 , MI_C_2 , MI_Cs_2, MI_D_2 , MI_Ds_2, MI_E_2 , MI_F_2 , MI_Fs_2, MI_G_2 , MI_Gs_2,MI_ALLOFF, MI_TRNSU, MI_MODSU, MI_CHU,
	KC_TRNS, MI_D_1 , MI_Ds_1, MI_E_1 , MI_F_1 , MI_Fs_1, MI_G_1 , MI_Gs_1, MI_A_1 , MI_As_1, MI_B_1 , MI_C_2 , MI_Cs_2,MI_VEL_10, MI_TRNSD, MI_MODSD, MI_CHD,
	MI_MOD , MI_G   , MI_Gs  , MI_A   , MI_As  , MI_B   , MI_C_1 , MI_Cs_1, MI_D_1 , MI_Ds_1, MI_E_1 , MI_F_1 ,          KC_TRNS,                            
	MI_LEG , MI_C   , MI_Cs  , MI_D   , MI_Ds  , MI_E   , MI_F   , MI_Fs  , MI_G   , MI_Gs  , MI_A   ,                   MI_LEG ,           MI_BENDU,         
	MI_PORT, KC_TRNS, MI_SOST,                          MI_SUS ,                              MO(L_FN1), MI_SOST, KC_TRNS, MI_PORT,  MI_VELD, MI_BENDD, MI_VELU   ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(record->event.pressed){
	switch (keycode) {
        case UC_CCOP:
	    SEND_STRING("/*");
	    break;
        case UC_CCCL:
	    SEND_STRING("*/");
	    break;
        case UC_CCFL:
            SEND_STRING("/**/");
	    break;
	}
    }
    return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

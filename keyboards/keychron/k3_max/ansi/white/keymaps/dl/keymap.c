/* Copyright 2024 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"
#include "print.h"

#define OPEN_APP(name)                                               \
    do {                                                             \
        SEND_STRING(SS_LGUI(" ")); /* Cmd+Space to open Spotlight */ \
        wait_ms(200);                                                \
        SEND_STRING(SS_TAP(X_BSPC));                                 \
        SEND_STRING(name);                                           \
        wait_ms(200);                                                \
        SEND_STRING(SS_TAP(X_ENTER));                                \
    } while (0)

enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAC_BASE] = LAYOUT_ansi_84(
     KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  BL_DOWN,  BL_UP,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_SNAP,  KC_DEL,   BL_STEP,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_END,
     KC_LCTL,  KC_LOPT,  KC_LCMD,                                KC_SPC,                                 KC_GLOBMAC,TO(MAC_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[MAC_FN] = LAYOUT_ansi_84(
     _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  BL_TOGG,
     _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
     BL_TOGG,  BL_STEP,  BL_UP,    _______,  _______,  _______,  KC_PPLS,  KC_P7,    KC_P8,    KC_P9,    KC_PAST,  _______,  _______,  _______,            _______,
     _______,  _______,  BL_DOWN,  _______,  _______,  _______,  KC_PMNS,  KC_P4,    KC_P5,    KC_P6,    KC_PSLS,  _______,            _______,            _______,
     _______,            _______,  _______,  _______,  _______,  KC_P0,    KC_P1,    KC_P2,    KC_P3,    _______,  _______,            _______,  _______,  _______,
     _______,  _______,  _______,                                _______,                                _______,TO(MAC_BASE),_______,  _______,  _______,  _______),

[WIN_BASE] = LAYOUT_ansi_84(
     KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_DEL,   BL_STEP,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_END,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT, MO(WIN_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[WIN_FN] = LAYOUT_ansi_84(
     _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  BL_DOWN,  BL_UP,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,  BL_TOGG,
     _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
     BL_TOGG,  BL_STEP,  BL_UP,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
     _______,  _______,  BL_DOWN,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
     _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
     _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______)
};

// clang-format on
//
enum custom_keycodes {
    SPA = SAFE_RANGE, // ;s for Spotify
    CHR,              // ;c for Chrome
    OBS,              // ;o for Obsidian
    TER               // ;t for Terminal
};

static bool semicolon_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KC_SCLN) {
        semicolon_pressed = record->event.pressed; // true if pressed, false if released
        return true;                               // still send semicolon normally when pressed/released
    }

    if (record->event.pressed && semicolon_pressed) {
        switch (keycode) {
            case KC_S: // ; + s
                semicolon_pressed = false;
                OPEN_APP("Spotify");
                return false; // block normal 's' output
            case KC_C:        // ; + c
                semicolon_pressed = false;
                OPEN_APP("Google Chrome");
                return false;
            case KC_O: // ; + o
                semicolon_pressed = false;
                OPEN_APP("Obsidian");
                return false;
            case KC_T: // ; + t
                semicolon_pressed = false;
                OPEN_APP("Kitty");
                return false;
        }
    }
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }

    return true; // process all other keys normally
}
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {

// if (!process_record_keychron_common(keycode, record)) {
//     return false;
// }
// return true;
// }

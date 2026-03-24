/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _NUMSYM,
    _FUNNAV,
    _CORNE_SETTINGS
};

enum custom_keycodes {
    DEL_WRD = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record){
    switch (keycode) {
        case DEL_WRD:
            if (record->event.pressed){
                SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_BSPC)SS_UP(X_LCTL));
            }
            break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,    MT(MOD_LSFT, KC_A),    MT(MOD_LCTL, KC_S),    MT(MOD_LGUI, KC_D),    MT(MOD_LALT, KC_F),    KC_G,                         KC_H,    MT(MOD_RALT, KC_J),    MT(MOD_RGUI, KC_K),    MT(MOD_RCTL, KC_L), MT(MOD_RSFT, KC_SCLN), KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------------+--------|  |--------+--------------+---------+--------+--------+--------+--------|
                                          KC_LALT,   MO(_NUMSYM),  KC_SPC,     KC_ENT,   MO(_FUNNAV), KC_RGUI
                                      //`--------------------------------'  `---------------------------------'
  ),


    [_NUMSYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_EXLM,   KC_AT, KC_HASH, KC_AMPR, KC_PERC,                      KC_UNDS, KC_CIRC, KC_LBRC, KC_RBRC,  KC_DLR, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,  KC_GRV,                      KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR,  KC_EQL, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(_CORNE_SETTINGS), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_FUNNAV] = LAYOUT_split_3x6_3(
  // ,------------------------------------------------------------------.                   ,----------------------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,       KC_F4,        KC_F5,        KC_F6,                       KC_F7,        KC_F8,      KC_F9,   KC_F10,    KC_F11,  KC_F12,
  //|--------+--------+--------+--------~---+-------------+-------------|                   |----------+--------+-------------+-----------+---------+--------|
      XXXXXXX, XXXXXXX, MS_LEFT,     MS_DOWN,        MS_UP,      MS_RGHT,                     KC_LEFT,      KC_DOWN,      KC_UP, KC_RIGHT,   XXXXXXX, XXXXXXX,
  //|--------+--------+--------+------------+-------------+-------------|                   |----------+--------+-------------+-----------+---------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX,     MS_BTN3,      MS_BTN1,      MS_BTN2,                     KC_HOME, KC_PAGE_DOWN, KC_PAGE_UP,   KC_END, KC_INSERT, XXXXXXX,
  //|--------+--------+--------+------------+-------------+-------------+--------| |--------+--------+-------------+-----------+---------+----------+--------|
                                          KC_LGUI,   MO(_CORNE_SETTINGS),  KC_SPC,    KC_ENT, _______, KC_RALT
                                      //`----------------------------------------' `--------------------------'
  ),

    [_CORNE_SETTINGS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,------------------------------------------------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,            XXXXXXX,           XXXXXXX,       XXXXXXX, XXXXXXX,           AC_TOGG,
  //|--------+--------+--------+--------+--------+--------|                    |--------+-------------------+------------------+--------------+--------+------------------|
      XXXXXXX, RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX,                      XXXXXXX,   KC_BRIGHTNESS_UP,   KC_AUDIO_VOL_UP, KC_AUDIO_MUTE, XXXXXXX,     QK_BOOTLOADER,
  //|-------+-------+--------+--------+--------+---------|                    |--------+--------------------+------------------+--------------+--------+------------------|
      XXXXXXX, RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX,                      XXXXXXX, KC_BRIGHTNESS_DOWN, KC_AUDIO_VOL_DOWN,       XXXXXXX, XXXXXXX,   QK_CLEAR_EEPROM,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+-------------------+------------------+--------------+--------+------------------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif

/*
// OLED display customization
//
//Setup some mask which can be or'd with bytes to turn off pixels
const uint8_t single_bit_masks[8] = {127, 191, 223, 239, 247, 251, 253, 254};

static void fade_display(void) {
    //Define the reader structure
    oled_buffer_reader_t reader;
    uint8_t buff_char;
    if (random() % 30 == 0) {
        srand(timer_read());
        // Fetch a pointer for the buffer byte at index 0. The return structure
        // will have the pointer and the number of bytes remaining from this
        // index position if we want to perform a sequential read by
        // incrementing the buffer pointer
        reader = oled_read_raw(0);
        //Loop over the remaining buffer and erase pixels as we go
        for (uint16_t i = 0; i < reader.remaining_element_count; i++) {
            //Get the actual byte in the buffer by dereferencing the pointer
            buff_char = *reader.current_element;
            if (buff_char != 0) {
                oled_write_raw_byte(buff_char & single_bit_masks[rand() % 8], i);
            }
            //increment the pointer to fetch a new byte during the next loop
            reader.current_element++;
        }
    }
}
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}
void oled_render_boot(bool bootloader) {
    oled_clear();
    for (int i = 0; i < 16; i++) {
        oled_set_cursor(0, i);
        if (bootloader) {
            oled_write_P(PSTR("Awaiting New Firmware "), false);
        } else {
            oled_write_P(PSTR("Rebooting "), false);
        }
    }

    oled_render_dirty(true);
}

bool shutdown_user(bool jump_to_bootloader) {
    oled_render_boot(jump_to_bootloader);
    return false;
}
bool oled_task_user(void) {
    render_logo();
    fade_display();
    // // Host Keyboard Layer Status
    // oled_write_P(PSTR("Layer: "), false);
    //
    // switch (get_highest_layer(layer_state)) {
    //     case _BASE:
    //         oled_write_P(PSTR("Base\n"), false);
    //         break;
    //     case _NUMSYM:
    //         oled_write_P(PSTR("First\n"), false);
    //         break;
    //     case _FUNNAV:
    //         oled_write_P(PSTR("Second\n"), false);
    //         break;
    //     case _CORNE_SETTINGS:
    //         oled_write_P(PSTR("Third\n"), false);
    //         break;
    //     default:
    //         // Or use the write_ln shortcut over adding '\n' to the end of your string
    //         oled_write_ln_P(PSTR("Undefined"), false);
    // }
    // // WPN Calculation
    // int wpm = get_current_wpm();
    // int wpm_len = snprintf(NULL, 0, "%d", wpm);
    // char * wpm_str = malloc(wpm_len + 6);
    // snprintf(wpm_str, wpm_len + 6, "WPM: %d\n", wpm);
    //
    // // Host Keyboard LED Status
    // oled_write_ln_P(PSTR(wpm_str), false);
    // free(wpm_str);
    // led_t led_state = host_keyboard_led_state();
    // oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    // oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    // oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}
*/

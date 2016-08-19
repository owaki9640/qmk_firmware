#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |  Esc |           |   =  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | INT1 |           | INT3 |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------| INT4 |           | INT5 |------+------+------+------+------+--------|
 * | LShift |  Z   |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  NO  |  Meh | Hyper|   [  |   ]  |                                       | Left | Down |  Up  | Right|  NO  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LANG2| LCtl |       | RCtl | LANG1|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | LAlt |       | RAlt |      |      |
 *                                 | Enter|Delete|------|       |------|  BS  |Space |
 *                                 |      |      | LGui |       | RGui |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,   KC_1,         KC_2,         KC_3,     KC_4,     KC_5,     KC_ESC,
        KC_TAB,   KC_Q,         KC_W,         KC_E,     KC_R,     KC_T,     KC_INT1,
        KC_LCTL,  KC_A,         KC_S,         KC_D,     KC_F,     KC_G,
        KC_LSFT,  KC_Z,         KC_X,         KC_C,     KC_V,     KC_B,     KC_INT4,
        KC_NO,    MEH_T(KC_NO), ALL_T(KC_NO), KC_LBRC,  KC_RBRC,
                                                                  KC_LANG2, KC_LCTL,
                                                                            KC_LALT,
                                                        KC_ENT,   KC_DEL,   KC_LGUI,
        // right hand
                KC_EQL,  KC_6,      KC_7,     KC_8,     KC_9,   KC_0,     KC_MINS,
                KC_INT3, KC_Y,      KC_U,     KC_I,     KC_O,   KC_P,     KC_BSLS,
                         KC_H,      KC_J,     KC_K,     KC_L,   KC_SCLN,  KC_QUOT,
                KC_INT5, KC_N,      KC_M,     KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                                    KC_LEFT,  KC_DOWN,  KC_UP,  KC_RGHT,  KC_NO,
                KC_RCTL, KC_LANG1,
                KC_RALT,
                KC_RGUI, KC_BSPC,  KC_SPC
    ),
};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};

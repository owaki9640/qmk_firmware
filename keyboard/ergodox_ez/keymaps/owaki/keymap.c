#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0   // Basic layer
#define KPAD 1   // Arrow and keypad
#define MOUS 2   // Mouse keys
#define BASE_R 3 // Reverse basic layer
#define KPAD_R 4 // Reverse arrow and keypad

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | Esc  |           |  =   |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  L3  |  ~L2 |  ~L1 |   [  |   ]  |                                       | Left | Down |  Up  | Right|  L3  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |LANG2/| LCtl |       | RCtl |LANG1/|
 *                                        | ~L3  |      |       |      | ~L3  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | LAlt |       | RAlt |      |      |
 *                                 |Enter | DEL  |------|       |------|  BS  |Space |
 *                                 |      |      | LGui |       | RGui |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                 KC_ESC,
        KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                 KC_FN1,
        KC_LCTRL,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,
        KC_LSFT,    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                 ALL_T(KC_NO),
        KC_FN3,     KC_FN2,   KC_FN1,   KC_LBRC,  KC_RBRC,
                                                            LT(BASE_R,KC_LANG2),  KC_LCTL,
                                                                                  KC_LALT,
                                                  KC_ENT,   KC_DEL,               KC_LGUI,
        // right hand
                KC_EQL,       KC_6,                 KC_7,     KC_8,     KC_9,   KC_0,     KC_MINS,
                KC_FN1,       KC_Y,                 KC_U,     KC_I,     KC_O,   KC_P,     KC_BSLS,
                              KC_H,                 KC_J,     KC_K,     KC_L,   KC_SCLN,  KC_QUOT,
                MEH_T(KC_NO), KC_N,                 KC_M,     KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                                                    KC_LEFT,  KC_DOWN,  KC_UP,  KC_RGHT,  KC_FN3,
                KC_RCTL,      LT(BASE_R,KC_LANG1),
                KC_RALT,
                KC_RGUI,      KC_BSPC,              KC_SPC
    ),
/* Keymap 1: Keypad and Fn Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | PrtSc  |  F1  |  F2  |  F3  |  F4  |  F5  |  Esc |           |  KP= |NumLck|  KP7 |  KP8 |  KP9 |  KP* |  INT1  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | ScrLk  |  F6  |  F7  |  F8  |  F9  |  F10 | TRNS |           | TRNS |  NO  |  KP4 |  KP5 |  KP6 |  KP- |  INT3  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Pause  |  F11 |  F12 |Insert| Home | PgUp |------|           |------|  NO  |  KP1 |  KP2 |  KP3 |  KP+ |KP Enter|
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |  NO  |  NO  |Delete|  End |PgDown|      |           |      |  NO  |  KP0 |  KP, |  KP. |  KP/ | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  L4  |  NO  | TRNS |   ]  | NUHS |                                       | Left | Down |  Up  | Right|  L4  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | ~L4  | LCtl |       | RCtl | ~L4  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | LAlt |       | RAlt |      |      |
 *                                 |Enter | DEL  |------|       |------|  BS  |Space |
 *                                 |      |      | LGui |       | RGui |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Keypad and Fn
[KPAD] = KEYMAP(
        // left hand
        KC_PSCR,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_ESC,
        KC_SLCK,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_TRNS,
        KC_PSCR,  KC_F11,   KC_F12,   KC_INS,   KC_HOME,  KC_PGUP,
        KC_LSFT,  KC_NO,    KC_NO,    KC_DEL,   KC_END,   KC_PGDN,  ALL_T(KC_NO),
        KC_FN4,   KC_NO,    KC_TRNS,  KC_RBRC,  KC_NUHS,
                                                          KC_FN4,   KC_LCTL,
                                                                    KC_LALT,
                                                KC_ENT,   KC_DEL,   KC_LGUI,
        // right hand
                KC_PEQL,      KC_NLCK,    KC_P7,   KC_P8,   KC_P9,   KC_PAST, KC_RO,
                KC_TRNS,      KC_NO,      KC_P4,   KC_P5,   KC_P6,   KC_PMNS, KC_JYEN,
                              KC_NO,      KC_P1,   KC_P2,   KC_P3,   KC_PPLS, KC_PENT,
                MEH_T(KC_NO), KC_NO,      KC_P0,   KC_PCMM, KC_PDOT, KC_PSLS, KC_RSFT,
                                          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_FN4,
                KC_RCTL,      KC_FN4,
                KC_RALT,
                KC_RGUI,      KC_BSPC,    KC_SPC
),
/* Keymap 2: Mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |WhLeft| WhUp |WhDown|WhRght|  NO  |           |  NO  |WhLeft|WhDown| WhUp |WhRght|      |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft| MsUp |MsDown|MsRght|------|           |------|MsLeft|MsDown| MsUp |MsRght|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Btn4 | Btn3 | Btn2 | Btn1 | ESC  |      |           |      | ESC  | Btn1 | Btn2 | Btn3 | Btn4 |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  NO  |  NO  | Acc2 | Acc1 | Acc0 |                                       | Acc0 | Acc1 | Acc2 | Btn5 |  NO  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  NO  |      |       |      |  NO  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Btn1 | Btn2 |------|       |------| Btn2 | Btn1 |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MOUSE
[MOUS] = KEYMAP(
        // left hand
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_WH_L,  KC_WH_U,  KC_WH_D,  KC_WH_R,  KC_NO,
        KC_TRNS,  KC_TRNS,  KC_MS_L,  KC_MS_U,  KC_MS_D,  KC_MS_R,
        KC_TRNS,  KC_BTN4,  KC_BTN3,  KC_BTN2,  KC_BTN1,  KC_ESC,   KC_TRNS,
        KC_NO,    KC_TRNS,  KC_ACL2,  KC_ACL1,  KC_ACL0,
                                                          KC_NO,    KC_TRNS,
                                                                    KC_TRNS,
                                                KC_BTN1,  KC_BTN2,  KC_TRNS,
        // right hand
                KC_TRNS,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
                KC_NO,    KC_WH_L,  KC_WH_D,  KC_WH_U,  KC_WH_R,  KC_TRNS,  KC_F12,
                          KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_TRNS,  KC_TRNS,
                KC_TRNS,  KC_ESC,   KC_BTN1,  KC_BTN2,  KC_BTN3,  KC_BTN4,  KC_TRNS,
                                    KC_ACL0,  KC_ACL1,  KC_ACL2,  KC_BTN5,  KC_NO,
                KC_TRNS,  KC_NO,
                KC_TRNS,
                KC_TRNS,  KC_BTN2,  KC_BTN1
),
/* Keymap 3: Reverse basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   -    |   0  |   9  |   8  |   7  |   6  |  =   |           |  Esc |   5  |   4  |   3  |   2  |   1  |   `    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   \    |   P  |   O  |   I  |   U  |   Y  |  NO  |           |  NO  |   T  |   R  |   E  |   W  |   Q  | Tab    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   '    |   ;  |   L  |   K  |   J  |   H  |------|           |------|   G  |   F  |   D  |   S  |   A  | LCtrl  |
 * |--------+------+------+------+------+------| Meh  |           | Hyper|------+------+------+------+------+--------|
 * | RShift |   /  |   .  |   ,  |   M  |   N  |      |           |      |   B  |   V  |   C  |   X  |   Z  | LShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | TRNS | Left |  Up  | Down | Right|                                       |   ]  |   [  |  NO  |  NO  | TRNS |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | TRNS | RCtl |       | LCtl | TRNS |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | RAlt |       | LAlt |      |      |
 *                                 |Space |  BS  |------|       |------| DEL  | Enter|
 *                                 |      |      | RGui |       | LGui |      |      |
 *                                 `--------------------'       `--------------------'
 */
//
[BASE_R] = KEYMAP(
        // left hand
        KC_MINS,  KC_0,     KC_9,   KC_8,     KC_7,     KC_6,     KC_EQL,
        KC_BSLS,  KC_P,     KC_O,   KC_I,     KC_U,     KC_Y,     KC_NO,
        KC_QUOT,  KC_SCLN,  KC_L,   KC_K,     KC_J,     KC_H,
        KC_RSFT,  KC_SLSH,  KC_DOT, KC_COMM,  KC_M,     KC_N,     MEH_T(KC_NO),
        KC_TRNS,  KC_LEFT,  KC_UP,  KC_DOWN,  KC_RGHT,
                                                        KC_TRNS,  KC_RCTL,
                                                                  KC_RALT,
                                              KC_SPC,   KC_BSPC,  KC_RGUI,
        // right hand
                KC_ESC,       KC_5,     KC_4,     KC_3,     KC_2,   KC_1,   KC_GRV,
                KC_NO,        KC_T,     KC_R,     KC_E,     KC_W,   KC_Q,   KC_TAB,
                              KC_G,     KC_F,     KC_D,     KC_S,   KC_A,   KC_LCTL,
                ALL_T(KC_NO), KC_B,     KC_V,     KC_C,     KC_X,   KC_Z,   KC_LSFT,
                                        KC_RBRC,  KC_LBRC,  KC_NO,  KC_NO,  KC_TRNS,
                KC_LCTL,      KC_TRNS,
                KC_LALT,
                KC_LGUI,      KC_DEL,   KC_ENT
),
//
[KPAD_R] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                    KC_TRNS, KC_TRNS,
                                                             KC_TRNS,
                                           KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(KPAD),                // FN1 - Momentary Layer 1 (Keypad)
  [2] = ACTION_LAYER_TAP_TOGGLE(MOUS),                // FN2 - Momentary Layer 2 (Mouse)
  [3] = ACTION_LAYER_TAP_TOGGLE(BASE_R),              // FN3 - Momentary Layer 3 (Reverse Base)
  [4] = ACTION_LAYER_TAP_TOGGLE(KPAD_R)               // FN4 - Momentary Layer 4 (Reverse Keypad)
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

    static uint8_t leds[4];
    uint8_t led;
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case BASE:
            break;
        case KPAD:
            ergodox_right_led_on(1);
            ergodox_right_led_set(1, 7);
            break;
        case MOUS:
            led = 2;
            leds[led] = 7;
/*             if (leds[led] == 255) { */
/*                 leds[led] = 0; */
/*             } */
/*             else { */
/*                 leds[led]++; */
/*             } */
/*             ergodox_right_led_on(led); */
/*             ergodox_right_led_set(led, leds[led]); */
            ergodox_right_led_on(led);
            ergodox_right_led_set(led, leds[led]);
            break;
        case BASE_R:
            ergodox_right_led_on(3);
            ergodox_right_led_set(3, 7);
            break;
        case KPAD_R:
            ergodox_right_led_on(1);
            ergodox_right_led_set(1, 7);
            ergodox_right_led_on(3);
            ergodox_right_led_set(3, 7);
            break;
        default:
            // none
            break;
    }

};

#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0   // Basic layer
#define KPAD 1   // Arrow and keypad
#define BASR 2   // Reverse basic layer
#define KPDR 3   // Reverse arrow and keypad
#define NAVI 4   // Navigation and Mouse keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | Esc  |           |  =   |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|  L4  |           |  L4  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  L2  |  Meh | Hyper|   [  |   ]  |                                       | Left | Down |  Up  | Right|  L2  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |LANG2/| LCtl |       | RCtl |LANG1/|
 *                                        | ~L2  |      |       |      | ~L2  |
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
        KC_GRV,     KC_1,         KC_2,         KC_3,     KC_4,     KC_5,               KC_ESC,
        KC_TAB,     KC_Q,         KC_W,         KC_E,     KC_R,     KC_T,               KC_FN1,
        KC_LCTRL,   KC_A,         KC_S,         KC_D,     KC_F,     KC_G,
        KC_LSFT,    KC_Z,         KC_X,         KC_C,     KC_V,     KC_B,               KC_FN4,
        KC_FN2,     MEH_T(KC_NO), ALL_T(KC_NO), KC_LBRC,  KC_RBRC,
                                                                    LT(BASR,KC_LANG2),  KC_LCTL,
                                                                                        KC_LALT,
                                                          KC_ENT,   KC_DEL,             KC_LGUI,
        // right hand
                KC_EQL,   KC_6,               KC_7,     KC_8,     KC_9,   KC_0,     KC_MINS,
                KC_FN1,   KC_Y,               KC_U,     KC_I,     KC_O,   KC_P,     KC_BSLS,
                          KC_H,               KC_J,     KC_K,     KC_L,   KC_SCLN,  KC_QUOT,
                KC_FN4,   KC_N,               KC_M,     KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                                              KC_LEFT,  KC_DOWN,  KC_UP,  KC_RGHT,  KC_FN2,
                KC_RCTL,  LT(BASR,KC_LANG1),
                KC_RALT,
                KC_RGUI,  KC_BSPC,            KC_SPC
    ),
/* Keymap 1: Keypad and Fn Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | PrtSc  |  F1  |  F2  |  F3  |  F4  |  F5  |  Esc |           |  KP= |NumLck|  KP7 |  KP8 |  KP9 |  KP* |  INT1  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | ScrLk  |  F6  |  F7  |  F8  |  F9  |  F10 | TRNS |           | TRNS |  NO  |  KP4 |  KP5 |  KP6 |  KP- |  INT3  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Pause  |  F11 |  F12 |Insert| Home | PgUp |------|           |------|  NO  |  KP1 |  KP2 |  KP3 |  KP+ |KP Enter|
 * |--------+------+------+------+------+------|  L4  |           |  L4  |------+------+------+------+------+--------|
 * | LShift |  NO  |  NO  |Delete|  End |PgDown|      |           |      |  NO  |  KP0 |  KP, |  KP. |  KP/ | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  L3  |  Meh | Hyper|   ]  | NUHS |                                       | Left | Down |  Up  | Right|  L3  |
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
        KC_PSCR,  KC_F1,        KC_F2,        KC_F3,    KC_F4,    KC_F5,    KC_ESC,
        KC_SLCK,  KC_F6,        KC_F7,        KC_F8,    KC_F9,    KC_F10,   KC_TRNS,
        KC_PSCR,  KC_F11,       KC_F12,       KC_INS,   KC_HOME,  KC_PGUP,
        KC_LSFT,  KC_NO,        KC_NO,        KC_DEL,   KC_END,   KC_PGDN,  KC_FN4,
        KC_FN3,   MEH_T(KC_NO), ALL_T(KC_NO), KC_RBRC,  KC_NUHS,
                                                                  KC_FN3,   KC_LCTL,
                                                                            KC_LALT,
                                                        KC_ENT,   KC_DEL,   KC_LGUI,
        // right hand
                KC_PEQL,  KC_NLCK,  KC_P7,   KC_P8,   KC_P9,   KC_PAST, KC_RO,
                KC_TRNS,  KC_NO,    KC_P4,   KC_P5,   KC_P6,   KC_PMNS, KC_JYEN,
                          KC_NO,    KC_P1,   KC_P2,   KC_P3,   KC_PPLS, KC_PENT,
                KC_FN4,   KC_NO,    KC_P0,   KC_PCMM, KC_PDOT, KC_PSLS, KC_RSFT,
                                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_FN3,
                KC_RCTL,  KC_FN3,
                KC_RALT,
                KC_RGUI,  KC_BSPC,  KC_SPC
),
/* Keymap 2: Reverse basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   -    |   0  |   9  |   8  |   7  |   6  |  =   |           |  Esc |   5  |   4  |   3  |   2  |   1  |   `    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   \    |   P  |   O  |   I  |   U  |   Y  |  NO  |           |  NO  |   T  |   R  |   E  |   W  |   Q  | Tab    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   '    |   ;  |   L  |   K  |   J  |   H  |------|           |------|   G  |   F  |   D  |   S  |   A  | LCtrl  |
 * |--------+------+------+------+------+------|  NO  |           |  NO  |------+------+------+------+------+--------|
 * | RShift |   /  |   .  |   ,  |   M  |   N  |      |           |      |   B  |   V  |   C  |   X  |   Z  | LShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | TRNS | Left |  Up  | Down | Right|                                       |   ]  |   [  | Hyper|  Meh | TRNS |
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
[BASR] = KEYMAP(
        // left hand
        KC_MINS,  KC_0,     KC_9,   KC_8,     KC_7,     KC_6,     KC_EQL,
        KC_BSLS,  KC_P,     KC_O,   KC_I,     KC_U,     KC_Y,     KC_NO,
        KC_QUOT,  KC_SCLN,  KC_L,   KC_K,     KC_J,     KC_H,
        KC_RSFT,  KC_SLSH,  KC_DOT, KC_COMM,  KC_M,     KC_N,     KC_NO,
        KC_TRNS,  KC_LEFT,  KC_UP,  KC_DOWN,  KC_RGHT,
                                                        KC_TRNS,  KC_RCTL,
                                                                  KC_RALT,
                                              KC_SPC,   KC_BSPC,  KC_RGUI,
        // right hand
                KC_ESC,   KC_5,     KC_4,     KC_3,     KC_2,         KC_1,         KC_GRV,
                KC_NO,    KC_T,     KC_R,     KC_E,     KC_W,         KC_Q,         KC_TAB,
                          KC_G,     KC_F,     KC_D,     KC_S,         KC_A,         KC_LCTL,
                KC_NO,    KC_B,     KC_V,     KC_C,     KC_X,         KC_Z,         KC_LSFT,
                                    KC_RBRC,  KC_LBRC,  ALL_T(KC_NO), MEH_T(KC_NO), KC_TRNS,
                KC_LCTL,  KC_TRNS,
                KC_LALT,
                KC_LGUI,  KC_DEL,   KC_ENT
),
/* Keymap 3: Reverse keypad and Fn Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  INT1  |  KP* |  KP9 |  KP8 |  KP7 |NumLck|  KP= |           |  Esc |  F5  |  F4  |  F3  |  F2  |  F1  |  PrtSc |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  INT3  |  KP- |  KP6 |  KP5 |  KP4 |  NO  |  NO  |           |  NO  |  F10 |  F9  |  F8  |  F7  |  F6  |  ScrLk |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |KP Enter|  KP+ |  KP3 |  KP2 |  KP1 |  NO  |------|           |------| PgUp | Home |Insert|  F12 |  F11 |  Pause |
 * |--------+------+------+------+------+------|  NO  |           |  NO  |------+------+------+------+------+--------|
 * | RShift |  KP/ |  KP. |  KP, |  KP0 |  NO  |      |           |      |PgDown| End  |Delete|  NO  |  NO  | LShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | TRNS | Left |  Up  | Down | Right|                                       | NUHS |   ]  | Hyper|  Meh | TRNS |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | TRNS | RCtl |       | LCtl | TRNS |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | RAlt |       | LAlt |      |      |
 *                                 |Sapce |  BS  |------|       |------| DEL  |Enter |
 *                                 |      |      | RGui |       | LGui |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Reverse keypad and Fn
[KPDR] = KEYMAP(
        // left hand
        KC_INT1,  KC_PAST,  KC_P9,    KC_P8,    KC_P7,    KC_NLCK,  KC_PEQL,
        KC_INT3,  KC_PMNS,  KC_P6,    KC_P5,    KC_P4,    KC_NO,    KC_NO,
        KC_PENT,  KC_PPLS,  KC_P3,    KC_P2,    KC_P1,    KC_NO,
        KC_RSFT,  KC_PSLS,  KC_PDOT,  KC_PCMM,  KC_P0,    KC_NO,    KC_NO,
        KC_TRNS,  KC_LEFT,  KC_UP,    KC_DOWN,  KC_RGHT,
                                                          KC_TRNS,  KC_RCTL,
                                                                    KC_RALT,
                                                KC_SPC,   KC_BSPC,  KC_RGUI,
        // right hand
                KC_ESC,   KC_F5,    KC_F4,    KC_F3,    KC_F2,        KC_F1,        KC_PSCR,
                KC_NO,    KC_F10,   KC_F9,    KC_F8,    KC_F7,        KC_F6,        KC_SLCK,
                          KC_PGUP,  KC_HOME,  KC_INS,   KC_F12,       KC_F11,       KC_PAUS,
                KC_NO,    KC_PGDN,  KC_END,   KC_DEL,   KC_NO,        KC_NO,        KC_LSFT,
                                    KC_NUHS,  KC_RBRC,  ALL_T(KC_NO), MEH_T(KC_NO), KC_TRNS,
                KC_LCTL,  KC_TRNS,
                KC_LALT,
                KC_LGUI,  KC_DEL,   KC_ENT
),
/* Keymap 4: Navigation and Mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    `   | Btn1 |WhLeft| WhUp |WhDown|WhRght| Esc  |           |   =  |WhLeft|WhDown| WhUp |WhRght| Btn1 |    -   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   | Btn2 |MsLeft| MsUp |MsDown|MsRght|  NO  |           |  NO  |MsLeft|MsDown| MsUp |MsRght| Btn2 |    \   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  LCtrl | Btn3 | Left |  Up  | Down | Right|------|           |------| Left | Down |  Up  | Right| Btn3 |    '   |
 * |--------+------+------+------+------+------| TRNS |           | TRNS |------+------+------+------+------+--------|
 * | LShift | Btn4 | End  | PgUp |PgDown| Home |      |           |      | Home |PgDown| PgUp | End  | Btn4 | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  NO  | Btn5 | Acc2 | Acc1 | Acc0 |                                       | Acc0 | Acc1 | Acc2 | Btn5 |  NO  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  NO  | LCtl |       | RCtl |  NO  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | LAlt |       | RAlt |      |      |
 *                                 | Btn1 | Btn2 |------|       |------| Btn2 | Btn1 |
 *                                 |      |      | LGui |       | RGui |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Navi and MOUSE
[NAVI] = KEYMAP(
        // left hand
        KC_GRV,   KC_BTN1,  KC_WH_L,  KC_WH_U,  KC_WH_D,  KC_WH_R,  KC_ESC,
        KC_TAB,   KC_BTN2,  KC_MS_L,  KC_MS_U,  KC_MS_D,  KC_MS_R,  KC_NO,
        KC_LCTL,  KC_BTN3,  KC_LEFT,  KC_UP,    KC_DOWN,  KC_RGHT,
        KC_LSFT,  KC_BTN4,  KC_END,   KC_PGUP,  KC_PGDN,  KC_HOME,  KC_TRNS,
        KC_NO,    KC_BTN5,  KC_ACL2,  KC_ACL1,  KC_ACL0,
                                                          KC_NO,    KC_LCTL,
                                                                    KC_LALT,
                                                KC_BTN1,  KC_BTN2,  KC_LGUI,
        // right hand
                KC_EQL,   KC_WH_L,  KC_WH_D,  KC_WH_U,  KC_WH_R,  KC_BTN1,  KC_MINS,
                KC_NO,    KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_BTN2,  KC_BSLS,
                          KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_BTN3,  KC_QUOT,
                KC_TRNS,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_BTN4,  KC_RSFT,
                                    KC_ACL0,  KC_ACL1,  KC_ACL2,  KC_BTN5,  KC_NO,
                KC_RCTL,  KC_NO,
                KC_RALT,
                KC_RGUI,  KC_BTN2,  KC_BTN1
),
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(KPAD),                // FN1 - Momentary Layer 1 (Keypad)
  [2] = ACTION_LAYER_TAP_TOGGLE(BASR),                // FN2 - Momentary Layer 3 (Reverse Base)
  [3] = ACTION_LAYER_TAP_TOGGLE(KPDR),                // FN3 - Momentary Layer 4 (Reverse Keypad)
  [4] = ACTION_LAYER_TAP_TOGGLE(NAVI)                 // FN4 - Momentary Layer 2 (Navi/Mouse)
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
        case NAVI:
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
        case BASR:
            ergodox_right_led_on(3);
            ergodox_right_led_set(3, 7);
            break;
        case KPDR:
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

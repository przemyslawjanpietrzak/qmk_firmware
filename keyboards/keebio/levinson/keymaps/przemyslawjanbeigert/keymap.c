#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3                                                                /* Symbols, Media */
#define _RAISE 4                                                                /* Numbers, Arrows */
#define _FUNC  5                                                                /* Function Keys */
#define _NUMS  6                                                                /* Numpad */
#define _ADJUST 16

/* short layer aliases */
#define _QW _QWERTY
#define _LW _LOWER
#define _RS _RAISE
#define _NM _NUMS
#define _AD _ADJUST

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  MKITPNK,
  DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

#define DREC_1  DYN_REC_START1
#define DREC_2  DYN_REC_START2
#define DPLAY_1 DYN_MACRO_PLAY1
#define DPLAY_2 DYN_MACRO_PLAY2
#define DSTOP   DYN_REC_STOP


// Mod Tap Definitions
// -------------------
                                      //  Tap     Hold
                                      //  ------------------
#define GUI_GRV MT(MOD_LGUI, KC_GRV)  //  `       Meta
#define CTL_ESC MT(MOD_LCTL, KC_ESC)  //  Esc     Left Control
#define SFT_MIN MT(MOD_LSFT, KC_MINS) //  -       Left Shift
#define MEH_LBC MT(MOD_MEH,  KC_LBRC) //  [       Meh
#define CTL_BSP MT(MOD_LCTL, KC_BSPC)  // Bkspce  Left Control
#define HPR_RBC MT(MOD_HYPR, KC_RBRC) //  ]       Hyper
#define SFT_EQL MT(MOD_RSFT, KC_EQL)  //  =       Right Shift
#define GUI_BSL MT(MOD_RGUI, KC_BSLS) //  \       Meta

#define NUM_TAB LT(_NUMS, KC_TAB)     //  Tab     Layer Numpad

#define CTL_DEL MT(MOD_LCTL, KC_DEL)  //  Del     Left Control

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.    ,-----------------------------------------.
 * | Tab  |  Q   |  W   |  E   |  R   |  T   |    |  Y   |  U   |  I   |  O   |  P   | BKSP |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Esc  |  A   |  S   |  D   |  F   |  G   |    |  H   |  J   |  K   |  L   |  ;   |  '   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Shift|  Z   |  X   |  C   |  V   |  B   |    |  N   |  M   |  ,   |  .   |  /   |Shift |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Ctrl |      | Meta | Alt  | Lower| Space|    | Space| Raise| Alt  | Meta |      |      |
 * `-----------------------------------------'    `-----------------------------------------'
 */
    [_QW] = LAYOUT_ortho_4x12(
        KC_TAB  , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC ,
        KC_ESC  , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        KC_LSFT , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_LSFT,
        KC_LCTL , _______, KC_LGUI, KC_LALT, LOWER  , KC_SPC, KC_SPC , RAISE  , KC_RALT, KC_LGUI, _______, _______
        ),

/* Raise
 * ,-----------------------------------------.    ,-----------------------------------------.
 * |   ,  |  1   |  2   |  3   |  +   |  -   |    |  {   |  }   |  (   |  )   |      | DEL  |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |   .  |  4   |  5   |  6   |  #   |  *   |    |  F1  | F2   | F3   | F4   | F5   | F6   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Shift|  7   |  8   |  9   |  /   |  =   |    |  F7  | F8   | F9   | F10  | F11  | F12  |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |  0   |      |Adjust|Enter |    | ENTER| RAISE|      |      |      |      |
 * `-----------------------------------------'    `-----------------------------------------'
 */
    [_RS] = LAYOUT_ortho_4x12(
        KC_COMM , KC_1   , KC_2   , KC_3   , KC_PLUS, KC_MINS, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, _______, KC_DEL,
        KC_DOT  , KC_4   , KC_5   , KC_6   , KC_HASH, KC_ASTR, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,
        KC_LSFT , KC_7   , KC_8   , KC_9   , KC_SLSH, SFT_EQL, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
        _______ , _______, KC_0   , _______, _______, KC_ENT, KC_ENT, _______, _______, _______, _______, _______
        ),

/* Lower
 * ,-----------------------------------------.    ,-----------------------------------------.
 * |  `   |  !   |  @   |  #   |  $   |  %   |    |  ^   |  &   | *    |     |  (   |  )    |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      | Vol+ | Mute | Play |      | Ins  |    |  Left|  Down|  Up  | Right|  {   |  }   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      | Vol- | < M  |  M > |      |      |    | Home |PgDown| PgUp |      |  [   |  ]   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |LOWER |      |    | Shift|Adjust|      |      |      |      |
 * `-----------------------------------------'    `-----------------------------------------'
 */
    [_LW] = LAYOUT_ortho_4x12(
        KC_GRV  , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,    KC_CIRC , KC_AMPR, KC_ASTR, _______, KC_LPRN, KC_RPRN,
        _______ , KC_VOLU, KC_MUTE, KC_MPLY, _______, KC_INS ,    KC_LEFT , KC_DOWN, KC_UP  , KC_RIGHT, KC_LCBR, KC_RCBR,
        _______ , KC_VOLD, KC_MPRV, KC_MNXT, _______, _______,    KC_HOME , KC_PGDN, KC_PGUP, _______, KC_LBRC, KC_RBRC ,
        _______ , _______, _______, _______, _______, _______,    KC_LSFT , _______, _______, _______ , KC_LB, _______
        ),

/* Numpad
 * ,-----------------------------------------.    ,-----------------------------------------.
 * |      |      | PrSc | ScrLk| Pause|      |    |      |  7   |  8   |  9   |  0   | Lock |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      | Ins  | Home | PgUp |      |    |      |  4   |  5   |  6   |  /   |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      | Del  | End  | PgDn |      |    |      |  1   |  2   |  3   |  *   |  =   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |NUMPAD|      |      |      |      |      |    |      |  0   |  .   |  +   |  -   | Enter|
 * `-----------------------------------------'    `-----------------------------------------'
 */
    [_NM] = LAYOUT_ortho_4x12(
        XXXXXXX, XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS, XXXXXXX,    XXXXXXX, KC_7   , KC_8   , KC_9   , KC_0   , TO(_NM),
        XXXXXXX, XXXXXXX, KC_INS , KC_HOME, KC_PGUP, XXXXXXX,    XXXXXXX, KC_4   , KC_5   , KC_6   , KC_SLSH, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_DEL , KC_END , KC_PGDN, XXXXXXX,    XXXXXXX, KC_1   , KC_2   , KC_3   , KC_ASTR, KC_EQL ,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,    _______, KC_0   , KC_DOT , KC_PLUS, KC_MINS, _______
        ),

/* Adjust
 * ,-----------------------------------------.    ,-----------------------------------------.
 * | Reset|      |  Up  |      |      | Rec1 |    | Rec2 | Plain| Snake|Gradnt|      | Del  |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Caps | Left | Down | Right|MkItPk| Play1|    | Play2| RGB  | HUE+ | SAT+ | BRI+ |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      | Stop1|    | Stop2| MODE | HUE- | SAT- | BRI- |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |    |      |      |      |      |      |      |
 * `-----------------------------------------'    `-----------------------------------------'
 */
    [_ADJUST] = LAYOUT_ortho_4x12(
        RESET  , XXXXXXX,  KC_UP , XXXXXXX, XXXXXXX, DREC_1 ,    DREC_2 , RGB_M_P, RGB_M_SN,RGB_M_G, XXXXXXX, KC_DEL ,
        KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, MKITPNK, DPLAY_1,    DPLAY_2, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DSTOP  ,    DSTOP  , RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______,
        _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______
        )
};

void make_it_pink_blue(void) {
    uint16_t blue_hue = 210;
    uint16_t pink_hue = 315;

    /* key is pressed */
    uint16_t hue = rgblight_get_hue();
    uint8_t sat = rgblight_get_sat();
    uint8_t val = rgblight_get_val();

    if (hue != blue_hue)
        rgblight_sethsv(blue_hue, sat, val);
    else
        rgblight_sethsv(pink_hue, sat, val);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_dynamic_macro(keycode, record))
        return false;

    switch (keycode) {
      case QWERTY:
          if (record->event.pressed) {
              set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
      case LOWER:
          if (record->event.pressed) {
              layer_on(_LOWER);
              update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
              layer_off(_LOWER);
              update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
      case RAISE:
          if (record->event.pressed) {
              layer_on(_RAISE);
              update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
              layer_off(_RAISE);
              update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
      case ADJUST:
          if (record->event.pressed) {
              layer_on(_ADJUST);
          } else {
              layer_off(_ADJUST);
          }
          return false;
          break;
      case MKITPNK:
          if (record->event.pressed)
              make_it_pink_blue();
          return false;
          break;
    }
    return true;
}

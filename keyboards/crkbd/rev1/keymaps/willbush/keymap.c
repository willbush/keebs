#include QMK_KEYBOARD_H

enum crkbd_layers { _COLEMAK, _LOWER, _HYPER, _RAISE, _FN, _NUM, _ADJUST };

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define HYPER MO(_HYPER)
#define FN MO(_FN)
#define ADJUST MO(_ADJUST)
#define NUM TT(_NUM)

// right hand
#define ALT_DOT RALT_T(KC_DOT)
#define CTL_QOT RCTL_T(KC_QUOT)
#define SFT_ENT RSFT_T(KC_ENT)
// left hand
#define ALT_X LALT_T(KC_X)
#define CTL_ESC LCTL_T(KC_ESC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_split_3x6_3(
     KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U, KC_COMM, KC_SCLN, KC_BSPC,
    CTL_ESC,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O, CTL_QOT,
    KC_LSFT,    KC_Z,   ALT_X,    KC_C,    KC_D,    KC_V,                      KC_K,    KC_H,    KC_Y, ALT_DOT, KC_SLSH, SFT_ENT,
                                        KC_LGUI,   LOWER,   HYPER,  KC_SPC,   RAISE,  KC_RALT
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
    KC_LCTL, KC_TILD, KC_LPRN, KC_EXLM,  KC_EQL, KC_RPRN,                   KC_LCBR, KC_PERC, KC_AMPR, KC_RCBR, KC_PIPE,  KC_DEL,
    _______, XXXXXXX,   KC_LT,   KC_GT, XXXXXXX,      FN,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, KC_RSFT,
                                        XXXXXXX, _______, XXXXXXX, _______,  ADJUST, _______
  ),

  [_HYPER] = LAYOUT_split_3x6_3(
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
    KC_LCTL,  KC_GRV, KC_LBRC, KC_PLUS, KC_MINS, KC_RBRC,                   KC_CIRC, KC_ASTR, KC_HASH,  KC_DLR, KC_BSLS,  KC_DEL,
    _______, XXXXXXX,   KC_LT,   KC_GT, KC_UNDS,     NUM,                   XXXXXXX,   KC_AT, XXXXXXX, KC_RALT, XXXXXXX, KC_RSFT,
                                        XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, _______
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
    KC_LCTL, XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN,  KC_END,                   KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,  KC_DEL,
    _______, XXXXXXX, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, KC_RSFT,
                                        XXXXXXX,  ADJUST, _______, _______, _______, _______
  ),

  [_FN] = LAYOUT_split_3x6_3(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_F12,   KC_F7,   KC_F8,   KC_F9, XXXXXXX, XXXXXXX,
    KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_F11,   KC_F4,   KC_F5,   KC_F6, XXXXXXX,  KC_DEL,
    _______, XXXXXXX, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_F10,   KC_F1,   KC_F2,   KC_F3, XXXXXXX, KC_RSFT,
                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______
  ),

  [_NUM] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,    KC_7,    KC_8,    KC_9, KC_MINS, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,    KC_4,    KC_5,    KC_6, KC_PLUS, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX, KC_RSFT,
                                        XXXXXXX, XXXXXXX, _______, _______,    KC_0,  KC_DOT
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX
  )
};
// clang-format on

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_X:
        case ALT_DOT:
            // Do not select the hold action when another key is pressed.
            return false;
        default:
            // Immediately select the hold action when another key is pressed.
            return true;
    }
}

#include QMK_KEYBOARD_H

enum planck_layers {
  _COLEMAK,
  _SC2, // SC2 game layer
  _WOW, // WOW game layer
  _CAM, // camera locations and queen inject
  _SETCAM, // camera location saves; _CAM's shift lifted while held
  _GRID, // shifts the grid into home key position
  _GRID2, // WOW: right hand's five columns under the left hand
  _LOWER,
  _HYPER,
  _RAISE,
  _FN,
  _NUM,
  _ADJUST
};

#define COLEMAK PDF(_COLEMAK)
#define SC2 PDF(_SC2)
#define WOW PDF(_WOW)
#define LOWER MO(_LOWER)
#define CAM LM(_CAM, MOD_LSFT)
#define GRID MO(_GRID)
#define GRID2 MO(_GRID2)
#define RAISE MO(_RAISE)
#define HYPER MO(_HYPER)
#define FN MO(_FN)
#define NUM MO(_NUM)

#define IDLE LCTL(KC_F1) // select all idle workers (plain F1 cycles one at a time)
#define ARMY KC_F2       // select army

// SC2 camera location save binds
#define CAM1 LCTL(KC_1)
#define CAM2 LCTL(KC_2)
#define CAM3 LCTL(KC_3)
#define CAM4 LCTL(KC_4)
#define CAM5 LCTL(KC_5)
#define CAM6 LCTL(KC_6)
#define CAM7 LCTL(KC_7)
#define CAM8 LCTL(KC_8)

enum custom_keycodes {
  SETCAM = SAFE_RANGE // hold: _SETCAM with _CAM's shift lifted
};

// right hand
#define ALT_DOT RALT_T(KC_DOT)
#define CTL_QOT RCTL_T(KC_QUOT)
#define SFT_ENT RSFT_T(KC_ENT)

// left hand
#define CTL_ESC LCTL_T(KC_ESC)
#define ALT_X LALT_T(KC_X)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_planck_grid(
     KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U, KC_COMM, KC_SCLN, KC_BSPC,
    CTL_ESC,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O, CTL_QOT,
    KC_LSFT,    KC_Z,   ALT_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_Y, ALT_DOT, KC_SLSH, SFT_ENT,
    XXXXXXX,     NUM, XXXXXXX, KC_LGUI,   LOWER,   HYPER,  KC_SPC,   RAISE, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX
  ),
  // *** SC2 game ***
  [_SC2] = LAYOUT_planck_grid(
     KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U, KC_COMM, KC_SCLN, KC_BSPC,
    KC_LCTL,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O, CTL_QOT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_Y,  KC_DOT, KC_SLSH, SFT_ENT,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT,     CAM,    GRID,   KC_SPC,   RAISE, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX
  ),
  // *** WOW game ***
  [_WOW] = LAYOUT_planck_grid(
     KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U, KC_COMM, KC_SCLN, KC_BSPC,
    CTL_ESC,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O, CTL_QOT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_Y,  KC_DOT, KC_SLSH, SFT_ENT,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT,   LOWER,   GRID2,  KC_SPC,   RAISE, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX
  ),
  // Shift is held down while holding this layer. everything to the right of
  // the digit keys opts out of this though. Digits 1-8 are camera hot keys so
  // the point is to easily have layer hold key also hold shift which lets me
  // inject quickly. Shifted digits still resolve to the plain camera binds, so
  // no alternate bind is needed in the game. I set camera locations by holding
  // SETCAM (which lifts the shift).
  [_CAM] = LAYOUT_planck_grid(
    _______,    KC_1,    KC_2,    KC_3,    KC_4, _______,  KC_F12,   KC_F7,   KC_F8,   KC_F9, _______, _______,
     SETCAM,    KC_5,    KC_6,    KC_7,    KC_8, _______,  KC_F11,   KC_F4,   KC_F5,   KC_F6, _______, _______,
    _______, _______,    KC_9,    KC_0,    IDLE,    ARMY,  KC_F10,   KC_F1,   KC_F2,   KC_F3, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  // Held from _CAM via SETCAM: shift is lifted so clicks select normally and
  // digits send the exact Ctrl+n CameraSave binds.
  [_SETCAM] = LAYOUT_planck_grid(
    _______,    CAM1,    CAM2,    CAM3,    CAM4, _______, _______, _______, _______, _______, _______, _______,
    _______,    CAM5,    CAM6,    CAM7,    CAM8, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  // SC2: shifts the right hand's keys left by four columns
  [_GRID] = LAYOUT_planck_grid(
    _______,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U, KC_COMM, KC_SCLN, _______, _______, _______, _______,
    _______,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O, _______, _______, _______, _______,
    _______,    KC_D,    KC_V,    KC_K,    KC_H,    KC_Y, ALT_DOT, KC_SLSH, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  // Shifts the right hand's five columns onto the left hand, so every action
  // bar bind is reachable without leaving the mouse.
  [_GRID2] = LAYOUT_planck_grid(
    _______,    KC_J,    KC_L,    KC_U, KC_COMM, KC_SCLN, _______, _______, _______, _______, _______, _______,
    _______,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O, _______, _______, _______, _______, _______, _______,
    _______,    KC_K,    KC_H,    KC_Y,  KC_DOT, KC_SLSH, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  // *** game layouts ends ***
  [_LOWER] = LAYOUT_planck_grid(
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
    KC_LCTL, KC_TILD, KC_LPRN, KC_EXLM,  KC_EQL, KC_RPRN, KC_LCBR, KC_PERC, KC_AMPR, KC_RCBR, KC_PIPE,  KC_DEL,
    _______, XXXXXXX,   KC_LT,   KC_GT, XXXXXXX,      FN, XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, KC_RSFT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
  ),
  [_HYPER] = LAYOUT_planck_grid(
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
    KC_LCTL,  KC_GRV, KC_LBRC, KC_PLUS, KC_MINS, KC_RBRC, KC_CIRC, KC_ASTR, KC_HASH,  KC_DLR, KC_BSLS,  KC_DEL,
    _______, XXXXXXX,   KC_LT,   KC_GT, KC_UNDS, XXXXXXX, XXXXXXX,   KC_AT, XXXXXXX, KC_RALT, XXXXXXX, KC_RSFT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
  ),
  [_RAISE] = LAYOUT_planck_grid(
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
    KC_LCTL, XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,  KC_DEL,
    _______, XXXXXXX, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, KC_RSFT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
  ),
  [_FN] = LAYOUT_planck_grid(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_F12,  KC_F7,   KC_F8,   KC_F9, XXXXXXX, XXXXXXX,
    KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_F11,  KC_F4,   KC_F5,   KC_F6, XXXXXXX,  KC_DEL,
    _______, XXXXXXX, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX,   KC_F10,  KC_F1,   KC_F2,   KC_F3, XXXXXXX, KC_RSFT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
  ),
  [_NUM] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_7,    KC_8,    KC_9, KC_MINS, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_4,    KC_5,    KC_6, KC_PLUS, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX, KC_RSFT,
    XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,    KC_0, XXXXXXX,  KC_DOT, XXXXXXX, XXXXXXX
  ),
  [_ADJUST] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX,   AU_ON,  AU_OFF, XXXXXXX, XXXXXXX, COLEMAK,     SC2,     WOW, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DB_TOGG, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX
  )
};
// clang-format on

// _CAM's held shift would turn its F keys and selection binds into "add to
// selection", so lift it around the tap. _FN's F keys stay shiftable.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SETCAM:
            // Hold: _SETCAM with _CAM's shift lifted, so clicks select
            // normally and digits send plain Ctrl+n save binds.
            if (record->event.pressed) {
                unregister_mods(MOD_BIT(KC_LSFT));
                layer_on(_SETCAM);
            } else {
                layer_off(_SETCAM);
                if (IS_LAYER_ON(_CAM)) {
                    register_mods(MOD_BIT(KC_LSFT));
                }
            }
            return false;
        case KC_F1 ... KC_F12: // covers ARMY
        case IDLE:
            // The shift check skips the lift while SETCAM already has it off.
            if (record->event.pressed && IS_LAYER_ON(_CAM) &&
                (get_mods() & MOD_BIT(KC_LSFT))) {
                unregister_mods(MOD_BIT(KC_LSFT));
                tap_code16(keycode);
                register_mods(MOD_BIT(KC_LSFT));
                return false;
            }
            return true;
        default:
            return true;
    }
}

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

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  // The SC2 layer swaps LOWER for CAM, so it needs its own path to _ADJUST.
  // Must come after the call above, which clears _ADJUST.
  if (layer_state_cmp(state, _CAM) && layer_state_cmp(state, _RAISE)) {
    state |= (layer_state_t)1 << _ADJUST;
  }
  return state;
}

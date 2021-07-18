// Notes because you never can remember this stuff:
//
// [BUILDING]
//   util/docker_build.sh kinesis/stapelberg:dvorak_programmer
//   util/docker_build.sh kinesis/kint36:dvorak_programmer
//
// [FLASH FIRMWARE]
// To enter programming mode, hold LSHIFT + RSHIFT, then tap "B".
// In the QMK documentation, this is called command mode.
//
// [NUMLOCK]
// Go to the numpad layer. With the right hand, hit the thumb's
// top-left-most key. You gotta memorize this one...
//
//


#include "kinesis.h"

#define _DVORAK 0 // Base Dvorak layer
#define _NUMBERS 1  // Numpad layer

enum CustomKeycodes {
  LOCK_OR_UNLOCK = SAFE_RANGE,
  GNOME_SEARCH
};




/****************************************************************************************************
*
*
* ,--------------------------------------------------------------------------------------------------------------------.
* | SEARCH |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  ||  F9  |  F10 |  F12 | CAPS | lock | Vol- | Vol+ | numpad |
* |--------+------+------+------+------+------+----------------------------+------+------+------+------+------+--------|
* |   $    |  #   |  !   |  {   |  }   |  &   |                            |   |  |  [   |   ]  |  +   |  *   |        |
* |--------+------+------+------+------+------|                            +------+------+------+------+------+--------|
* | ESC    |  '"  |  ,<  |  .>  |   P  |   Y  |                            |   F  |   G  |   C  |   R  |   L  |  =+    |
* |--------+------+------+------+------+------|                            |------+------+------+------+------+--------|
* | Tab    |   A  |   O  |   E  |   U  |   I  |                            |   D  |   H  |   T  |   N  |   S  | -_     |
* |--------+------+------+------+------+------|                            |------+------+------+------+------+--------|
* | LShift(|  ;:  |   Q  |   J  |   K  |   X  |                            |   B  |   M  |   W  |  V   |   Z  | RShift)|
* `--------+------+------+------+------+-------                            `------+------+------+------+------+--------'
*          |  `~  |\numpd| Left | Right|                                          | Up   | Down |  /?  |  @   |
*          `---------------------------'                                          `---------------------------'
*                                        ,-------------.          ,-------------.
*                                        | Ctrl | Alt  |          | Gui  | Ctrl |
*                                 ,------|------|------|          |------+------+------.
*                                 |      |      | Home |          | PgUp |      |      |
*                                 | BkSp | Del  |------|          |------|Return| Space|
*                                 |      |      | End  |          | PgDn |      |      |
*                                 `--------------------'          `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DVORAK] = LAYOUT(
        // left hand
        GNOME_SEARCH,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5, KC_F6, KC_F7, KC_F8,
        KC_DOLLAR,   KC_HASH,    KC_EXCLAIM,    KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_AMPERSAND,
        KC_ESCAPE,   KC_QUOT, KC_COMM, KC_DOT,  KC_P,   KC_Y,
        KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,   KC_I,
        KC_LSPO,  KC_SCLN, KC_Q,    KC_J,    KC_K,   KC_X,
                  KC_GRAVE,  LT(_NUMBERS, KC_BSLASH), KC_LEFT, KC_RIGHT,
        // left thumb
                          KC_LCTRL, KC_LALT,
                                     KC_HOME,
                   KC_BSPC, KC_DEL,  KC_END,
        // right hand
        KC_F9,  KC_F10,   KC_F11,   KC_F12,   KC_CAPSLOCK, LOCK_OR_UNLOCK, KC_VOLD, KC__VOLUP, TG(_NUMBERS),
        KC_PIPE,   KC_LBRACKET,     KC_RBRACKET,     KC_PLUS,     KC_PAST,    KC_NO,
        KC_F,   KC_G,     KC_C,     KC_R,     KC_L,    KC_EQUAL,
        KC_D,   KC_H,     KC_T,     KC_N,     KC_S,    KC_MINUS,
        KC_B,   KC_M,     KC_W,     KC_V,     KC_Z,    KC_RSPC,
                          KC_UP,  KC_DOWN, KC_SLASH, KC_AT,
        // right thumb
        KC_LGUI, KC_RCTL,
        KC_PGUP,
        KC_PGDN, KC_ENT, KC_SPC
    ),

[_NUMBERS] = LAYOUT(
       // left hand
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                KC_NO,   KC_TRANSPARENT,   KC_NO,   KC_NO,
        // left thumb
                                           KC_NO,   KC_NO,
                                                    KC_NO,
                                  KC_TRANSPARENT,   KC_TRANSPARENT,   KC_TRANSPARENT,
       // right hand
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRANSPARENT,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_7,    KC_8,    KC_9,    KC_NO,   KC_NO,
       KC_NO,   KC_4,    KC_5,    KC_6,    KC_NO,   KC_NO,
       KC_NO,   KC_1,    KC_2,    KC_3,    KC_NO,   KC_NO,
                KC_TRANSPARENT,   KC_TRANSPARENT,   KC_DOT,   KC_NO,
       // right thumb
       KC_NUMLOCK, KC_O,
       KC_NO,
       KC_TRANSPARENT, KC_ENT, KC_P0
)
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


void matrix_init_user(void) {

}

void matrix_scan_user(void) {


}

// A timer used to determine LOCK_OR_UNLOCK macro.
uint16_t unlock_hold_timer = 0;

// Manually implement a MOD_TAP w/ macro for emitting "std::" and "::" on LCTL/RCTL.
uint16_t lctl_hold_timer = 0;
uint16_t rctl_hold_timer = 0;
bool other_key_hit = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case LOCK_OR_UNLOCK:
      // Lock if pressed and released.
      // Unlock if held and released.
      if(record->event.pressed) {
        unlock_hold_timer = timer_read();
      } else {
        if(timer_elapsed(unlock_hold_timer) < 360) {
          // GUI + L -> Lock
          SEND_STRING(SS_LGUI("l"));
        } else {
          // CTRL + ALT + DELETE -> Unlock (on Windows)
          SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_DELETE))));
        }
      }
      break;
    case GNOME_SEARCH:
      if(record->event.pressed) {
        // Open up the command line launch in Gnome.
        // Setup a DDG query with an "I'm feeling lucky" option.
        SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_F2) SS_UP(X_F2) SS_UP(X_LALT));
        SEND_STRING("xdg-open \"https://duckduckgo.com/?q=!+\"");
        // Move cursor so that it's within the double quotes.
        SEND_STRING(SS_TAP(X_LEFT));
        // ... type query and hit enter!
      }
      break;
    case KC_LCTL:
      if(record->event.pressed) {
        lctl_hold_timer = timer_read();
        register_code(KC_LCTL);
        other_key_hit = false;
      } else {
        unregister_code(KC_LCTL);
        if (timer_elapsed(lctl_hold_timer) < 350 && !other_key_hit) {
          SEND_STRING("std::");
          print("Saying std\n");
          //led_set_kb(255);
        }
      }
      break;
    case KC_RCTRL:
      if(record->event.pressed) {
        rctl_hold_timer = timer_read();
        register_code(KC_RCTRL);
        other_key_hit = false;
      } else {
        unregister_code(KC_RCTRL);
        if (timer_elapsed(rctl_hold_timer) < 350 && !other_key_hit) {
          SEND_STRING("::");
        }
      }
      break;
    default:
      other_key_hit = true;
      break;
  }
  return true;
}

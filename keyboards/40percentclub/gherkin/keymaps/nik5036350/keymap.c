#include QMK_KEYBOARD_H

#include "quantum.h"

#define FN1_SPC     LT(1, KC_SPC)
#define FN2_BSPC    LT(2, KC_BSPC)
#define FN3_C       LT(3, KC_C)
#define FN_GIT_G    LT(_GIT, KC_G)
#define FN4_V       LT(4, KC_V)
#define FN5_B       LT(5, KC_B)
#define CTL_Z       CTL_T(KC_Z)
#define ALT_X       ALT_T(KC_X)
#define ALT_N       ALGR_T(KC_N)
#define CTL_M       RCTL_T(KC_M)
#define SFT_ENT     RSFT_T(KC_ENT)
#define SFT_A       LSFT_T(KC_A)


// enum custom_keycodes {
//    M_GIT_COMMIT,
// };

// apps layers
#define _GIT 6

// Tap Dance declarations
enum {
    TD_Q_ESC,
    TD_A_CAPS
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
    [TD_A_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_CAPS),
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_ortho_3x10(
    TD(TD_Q_ESC),    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,            KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_LEAD,
    CTL_Z,           ALT_X,   FN3_C,   FN4_V,   FN2_BSPC,    FN1_SPC, FN5_B,   ALT_N,   CTL_M,   SFT_ENT
  ),

  [1] = LAYOUT_ortho_3x10(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______
  ),

  [2] = LAYOUT_ortho_3x10(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, KC_GRV,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [3] = LAYOUT_ortho_3x10(
    _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    KC_TAB,  _______, _______, _______, _______, KC_COMM, KC_DOT,  KC_SLSH, KC_SCLN, KC_QUOT,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  [4] = LAYOUT_ortho_3x10(
    _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    KC_TAB,  _______, _______, _______, _______, KC_LABK, KC_RABK, KC_QUES, KC_COLN, KC_DQUO,
    _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
  ),

  [5] = LAYOUT_ortho_3x10(
    KC_CALC, KC_WHOM, KC_MAIL, KC_MYCM, _______, _______, _______, _______, _______, KC_PSCR,
    _______, _______, _______, _______, _______, _______, _______, _______, BL_DEC,  BL_INC,
    _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______
  ),

//   [_GIT] = LAYOUT_ortho_3x10(
//     KC_CALC, KC_WHOM, KC_MAIL,      KC_MYCM, _______, _______, _______, _______, _______, KC_PSCR,
//     _______, _______, _______,      _______, _______, _______, _______, _______, BL_DEC,  BL_INC,
//     _______, _______, M_GIT_COMMIT, _______, _______,   _______, _______, _______, _______, _______
//   )

};

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  setPinOutput(D5);
  setPinOutput(B0);
}

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinLow(D5);
  } else {
    writePinHigh(D5);
  }

  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinLow(B0);
  } else {
    writePinHigh(B0);
  }
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
// 	// if (record->event.pressed) {
// 	// 	switch(keycode) {
// 	// 		case M_GIT_COMMIT:
// 	// 			SEND_STRING("git commit -m");
// 	// 			return false;
// 	// 	}
// 	// }
// 	return true;
// };

void tap(uint16_t keycode){
    register_code(keycode);
    unregister_code(keycode);
};

void crlWrap(uint16_t keycode) {
                    register_code(KC_LCTL);
                    tap(keycode);
                    unregister_code(KC_LCTL);
        };

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_A) {
            crlWrap(KC_A);
        }

        SEQ_ONE_KEY(KC_S) {
            crlWrap(KC_S);
        }

        SEQ_ONE_KEY(KC_Z) {
            crlWrap(KC_Z);
        }

        SEQ_ONE_KEY(KC_X) {
            crlWrap(KC_X);
        }

        SEQ_ONE_KEY(KC_C) {
            crlWrap(KC_C);
        }

        SEQ_ONE_KEY(KC_V) {
            crlWrap(KC_V);
        }

        SEQ_TWO_KEYS(KC_A, KC_A) {  // select all and copy
            register_code(KC_LCTL);
            tap(KC_A);
            tap(KC_C);
            unregister_code(KC_LCTL);
        }

        // git section
        SEQ_TWO_KEYS(KC_G, KC_S) {  // select all and copy
            SEND_STRING("git status");
            tap(KC_ENT);
        }
        SEQ_TWO_KEYS(KC_G, KC_C) {  // select all and copy
            SEND_STRING("git connit -m");
        }
        SEQ_THREE_KEYS(KC_G, KC_C, KC_A) {  // select all and copy
            SEND_STRING("git connit --ammend");
            tap(KC_ENT);
        }
    }
}

enum combo_events {
  ZC_COPY,
  XV_PASTE,
  GP_GITPUL,
  GPO_GITPULLORIGIN
};

const uint16_t PROGMEM copy_combo[] = {KC_G, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_G, KC_S, COMBO_END};
const uint16_t PROGMEM gitpull_combo[] = {KC_G, KC_P, COMBO_END};
const uint16_t PROGMEM gitpullorigin_combo[] = {KC_G, KC_P ,KC_O, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [ZC_COPY] = COMBO_ACTION(copy_combo),
  [XV_PASTE] = COMBO_ACTION(paste_combo),
  [GP_GITPUL] = COMBO_ACTION(gitpull_combo),
  [GPO_GITPULLORIGIN] = COMBO_ACTION(gitpullorigin_combo),
};

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
    case ZC_COPY:
      if (pressed) {
        SEND_STRING("git commit -m");
      }
      break;
    case XV_PASTE:
      if (pressed) {
        SEND_STRING("git status");
      }
      break;
    case GPO_GITPULLORIGIN:
      if (pressed) {
        SEND_STRING("git pull origin");
      }
    break;
    case GP_GITPUL:
      if (pressed) {
        SEND_STRING("git pull");
      }
      break;
  }
}

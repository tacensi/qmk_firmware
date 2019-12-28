#include QMK_KEYBOARD_H

#define TAPPING_TOGGLE 3

#define _QWERTY  0
#define _LOWER   1
#define _RAISE   2
#define _NUMPAD  3
#define _EMOJI   4


enum emoji_map {
    LOL,    // 😂
    ROFL,   // 🤣
    CUTE,   // 😊
    YUM,    // 😋
    INLOV,  // 😍
    KISS,   // 😘
    YUK,    // 😣
    SKULL,  // 💀
    POO,    // 💩
    JOIA,   // 👍
    DIO,    // 🤘
    FYOU,   // 🖕
    HEART,  // ❤️
    CHEERS, // 🍻
    DICK,   // 🍆
    BUTT,   // 🍑
    TINTIN, // 🥂
    BB,     // 🅱️
    KEEB    // ⌨️
};

const uint32_t PROGMEM unicode_map[] = {
    [LOL] = 0x1F602,    // 😂
    [ROFL] = 0x1F923,   // 🤣
    [CUTE] = 0x1F60A,   // 😊
    [YUM] = 0x1F60B,    // 😋
    [INLOV] = 0x1F60D,  // 😍
    [KISS] = 0x1F618,   // 😘
    [YUK] = 0x1F623,    // 😣
    [SKULL] = 0x1F480,  // 💀
    [POO] = 0x1F4A9,    // 💩
    [JOIA] = 0x1F44D,   // 👍
    [DIO] = 0x1F918,    // 🤘
    [FYOU] = 0x1F595,   // 🖕
    [HEART] = 0x2764,   // ❤️
    [CHEERS] = 0x1F37B, // 🍻
    [DICK] = 0x1F346,   // 🍆
    [BUTT] = 0x1F351,   // 🍑
    [TINTIN] = 0x1F942, // 🥂
    [BB] = 0x1F171,     // 🅱️
    [KEEB] = 0x2328     // ⌨️
};


enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    CC_ARRW,
    CC_PRN,
    CC_BRC,
    CC_CBR,
    CC_PHP,
    SHRUG,
    FU,
    TFLIP,
    TFLIP2,
    LENNY,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |      |      |      |      |      |      |      |      |      |      |      |emoji |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |  Ctrl | NP  | GUI  | Alt  |Lower | Spc  | Spc  |Raise | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */

[_QWERTY] = LAYOUT_ortho_4x12( \
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_BSPC, \
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, LT( _EMOJI, KC_QUOT), \
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,  KC_COMM,  KC_DOT,  KC_SLSH, KC_ENT, \
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
      KC_LCTL, TT(3), KC_LGUI, KC_LALT, MO(1),   KC_SPC,  KC_SPC,   MO(2),  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT),

  /* Lower
   * ,-----------------------------------------------------------------------------------.
   * |   "  |  !   |   @  |   #  |  $   |  %   |  ^   |  &   |   *  |   (  |   )  |  DEL |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | CAPS | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |  {   |   }  |   (  |   )  |  `   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | ____ |CC_PHP|CC_ARRW|CC_PRN|CC_BRC|CC_CBR|KC_NO|   [  |   ]  |   \  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | XXXX | XXXX | XXXX | XXXX |Lower | XXXX | XXXX | XXXX | Menu | XXXX | XXXX | XXXX |
   * `-----------------------------------------------------------------------------------'
   *
    , ,
   */
[_LOWER] = LAYOUT_ortho_4x12( \
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     KC_QUOT, KC_EXLM, KC_AT  , KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     KC_CAPS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_GRV, \
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     KC_TRNS, CC_PHP,  CC_ARRW, CC_PRN,   KC_NO,  KC_NO,   KC_NO,   KC_LBRC, KC_RBRC, KC_BSLS, KC_SLSH, KC_TRNS, \
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_APP,   KC_NO,   KC_NO,   KC_NO),


  /* Raise
   * ,-----------------------------------------------------------------------------------.
   * |   "  |  1/! |  2/@ |  3/# |  4/$ |  5/% |  6/" |  7/& |  8\* |  9/( |  0/) | DEL  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | ____ |  f1  |  F2  |  F3  |  F4  |  F5  |  F6  | INS  | HOME |  PUP |  ^   |  ~   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | XXXX |  F7  |  F8  |  F9  | F10  | F11  | F12  | DEL  | END  | PDWN |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | XXXX | XXXX | XXXX | XXXX |Lower | XXXX | XXXX | Raise| Menu | XXXX | XXXX | XXXX |
   * `-----------------------------------------------------------------------------------'
   */

[_RAISE] = LAYOUT_ortho_4x12( \
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     KC_NO,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_DEL, \
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     KC_CAPS, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NO, KC_MINS, KC_UNDS, KC_CIRC, KC_TILDE, \
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     KC_TRNS, KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_TRNS, \
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_TRNS, KC_HOME, KC_PGUP, KC_PGDN, KC_END),



  /* Numpad
   * ,-----------------------------------------------------------------------------------
   * | TO(0)| XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |   7  |   8  |   9  |   =  | ____ |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | ____ | RGB  | RGB  | RGB  | RGB  | XXXX | XXXX |   4  |   5  |   6  |   -  |   =  |
   * |      | Togl | Hue+ | Sat+ | Brt+
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | XXXX |      | RGB  | RGB  | RGB  | XXXX | XXXX |   1  |   2  |   3  |   +  | ____ |
   * |      | Term | Hue- | Sat- | Brt-
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | |||||| RGB  |      |      |      | XXXX | XXXX |  0   |  .   |  ,   |   /  |  _   |
   * | |Fn||| Mode | Alt  |
   * `-----------------------------------------------------------------------------------'
   */

[_NUMPAD] = LAYOUT_ortho_4x12( \
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     TO(0),   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_TRNS, \
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     KC_NO,  RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,   KC_NO,   KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_PPLS,  KC_EQL, \
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     KC_NO,  KC_NO,   RGB_HUD, RGB_SAD, RGB_VAD,   KC_NO,   KC_NO,   KC_P1,   KC_P2,   KC_P3,   KC_PAST, KC_TRNS, \
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_TRNS, KC_P0,   KC_PDOT, KC_PCMM, KC_PSLS,  KC_UNDS),


  /* Emoji
   * ,-----------------------------------------------------------------------------------.
   * | XXXX |SHRUG |TFLIP |TFLIP2|  FU  | XXXX | XXXX | XXXX | XXXX |   -  |   =  | ____ |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | ____ |  😂  |  🤣  |  😊  |  😋  |  😍  |  😘  |  ❤️  |  👍  |  🤘  |   )  | XXXX |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | XXXX |  😣  |  💀  |  💩  |  🖕  |  🍻  |  🥂  |  🍆  |  🍑  |  🅱️  |  ⌨️  | XXXX |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
   * `-----------------------------------------------------------------------------------'
   */
[_EMOJI] = LAYOUT_ortho_4x12( \
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     KC_NO,   SHRUG ,  TFLIP,   TFLIP2,   FU,     LENNY,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   \
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     KC_NO,   X(LOL), X(ROFL), X(CUTE),  X(YUM), X(INLOV),X(KISS), X(HEART),X(JOIA),  X(DIO),  KC_NO,   KC_NO,   \
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     KC_NO,   X(YUK), X(SKULL), X(POO), X(FYOU),X(CHEERS),X(TINTIN),X(DICK), X(BUTT), X(BB),  X(KEEB),   KC_NO,   \
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO  )
};


void matrix_init_user(void) {
    set_unicode_input_mode(UC_LNX);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case CC_ARRW:
                SEND_STRING("->");
                return false;
            case CC_PRN:
                SEND_STRING("()"SS_TAP(X_LEFT));
                return false;
            case CC_BRC:
                SEND_STRING("[]"SS_TAP(X_LEFT));
                return false;
            case CC_CBR:
                SEND_STRING("{}"SS_TAP(X_LEFT));
                return false;
            case CC_PHP:
                SEND_STRING("<?php  ?>"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
                return false;
            case FU:       // t(-_-t)
                SEND_STRING("t(-_-t)");
                return false;
            case SHRUG: // ¯\_(ツ)_/¯
                send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
                return false;
            case TFLIP:         // (╯°□°)╯ ︵ ┻━┻
                send_unicode_hex_string("0028 256F 00B0 25A1 00B0 0029 256F 0020 FE35 0020 253B 2501 253B");
                return false;
            case TFLIP2:         // ┻━┻︵ \(°□°)/ ︵ ┻━┻
                send_unicode_hex_string("253B 2501 253B FE35 0020 005C 0028 00B0 25A1 00B0 0029 002F 0020 FE35 0020 253B 2501 253B");
                return false;
            case LENNY:         // ( ͡° ͜ʖ ͡°)
                send_unicode_hex_string("0028 0020 00cd 00a1 00c2 00b0 0020 00cd 009c 00ca 0096 0020 00cd 00a1 00c2 00b0 0029");
                return false;
        }
    }
    return true;
}


// Runs just one time when the keyboard initializes.
void matrix_scan_user(void) {
  static bool has_ran_yet;
  if (!has_ran_yet) {
    has_ran_yet = true;
        rgblight_setrgb (16, 10, 0);
  }
}
uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case _RAISE:
        rgblight_setrgb(0, 16, 0); //yellow
        break;
    case _LOWER:
        rgblight_setrgb(0, 0, 16); //blue
        break;
    case _EMOJI:
        rgblight_setrgb (16, 0, 16); //purple
        break;
    case _NUMPAD:
        rgblight_setrgb (16, 0, 0); //red
        break;

    default: //  for any other layers, or the default layer
        rgblight_setrgb (16, 9, 0); //orange
        break;
    }
  return state;
}

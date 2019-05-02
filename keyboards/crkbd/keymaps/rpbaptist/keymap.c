#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

// #ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
// extern rgblight_config_t rgblight_config;
// #endif

extern uint8_t is_master;

#define _FN 7
#define _SYM 8
#define _UTIL 9
#define _NAV 10
#define _TEMPLATE 16

#define KC_CLMK TO(0)
#define KC_QWERT TO(1)
#define KC_GAME TO(3)

// #define KC_T_SYM TT(8)
// #define KC_S_SYM MO(8)

#define KC_NV_ENT LT(_NAV, KC_ENT)
#define KC_FN_ESC LT(_FN, KC_ESC)
#define KC_UT_TAB LT(_UTIL, KC_TAB)
#define KC_SYMSPC LT(_SYM, KC_SPC)

#define KC_LCTBR LCTL_T(KC_LBRACKET)
#define KC_RCTBR RCTL_T(KC_RBRACKET)

// #define KC_ALSPC LALT_T(KC_SPC)
#define KC_ALTSF LALT(KC_LSFT)

#define KC_TABFWD LCTL(KC_TAB)
#define KC_TABBCK LCTL(LSFT(KC_TAB))

#define _COLEMAKDHM 0
#define _QWERTY 1
#define _GAME 3

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_RST   RESET
#define KC_LRST  RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LSMOD RGB_SMOD
#define KC_LFMOD  RGB_MOD
#define KC_LRMOD  RGB_RMOD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAKDHM] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
     FN_ESC,     Q,     W,     F,     P,     B,                      J,     L,    U,     Y,   SCLN,  BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     UT_TAB,     A,     R,     S,     T,     G,                      M,     N,     E,     I,     O,  QUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      LCTBR,     Z,     X,     C,     D,     V,                      K,     H,  COMM,   DOT,  SLSH, RCTBR,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                   LALT,  LSPO, SYMSPC,  NV_ENT,  RSPC,  RGUI \
                              //`--------------------'  `--------------------'
  ),

  [_QWERTY] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _____, _____, _____,     E,     R,     T,                      Y,     U,     I,     O,     P, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____,     S,     D,     F, _____,                      H,     J,     K,     L,  SCLN, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____, _____, _____,     V,     B,                  _____,     N,     M, _____, _____, _____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____, _____,    _____, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_GAME] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _____, _____, _____, _____, _____, _____,                  _____, _____, _____, _____, _____, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____, _____, _____, _____, _____,                  _____, _____, _____, _____, _____, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LCTL, _____, _____, _____, _____, _____,                  _____, _____, _____, _____, _____,  RCTL,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, LSFT,  _____,    _____,  RSFT, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_SYM] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        GRV,     1,     2,     3,     4,     5,                      6,     7,     8,     9,     0,  BSLS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       TILD,  EXLM,    AT,  HASH,   DLR,  PERC,                   CIRC,  AMPR,  ASTR,  MINS,  PLUS,  PIPE,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____, _____, _____, ALTSF, _____,                  _____, _____, _____,  UNDS,   EQL, _____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____, _____,      DEL, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_NAV] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        ESC,  WH_U,TABBCK,  MS_U,TABFWD,  BTN2,                   PGUP,  HOME,    UP,   END, XXXXX,   DEL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       TILD,  WH_D,  MS_L,  MS_D,  MS_R,  BTN1,                   PGDN,  LEFT,  DOWN,  RGHT, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, XXXXX,  WH_L, XXXXX,  WH_R, XXXXX,                  XXXXX,  ACL0,  ACL1,  ACL2, XXXXX, _____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+-----+-------|
                                  _____, _____,   SPC,    _____, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_FN] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _____,    F1,    F2,    F3,    F4,    F5,                     F6,    F7,    F8,    F9,   F10,   F11,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
        RST, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                   LTOG, LFMOD,  LHUI,  LSAI,  LVAI,   F12,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____,  CLMK,  GAME, QWERT, XXXXX, XXXXX,                  XXXXX, LRMOD,  LHUD,  LSAD,  LVAD, _____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____,   SPC,      ENT, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_UTIL] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      ESC,   XXXXX,  MSTP,  VOLU,  MNXT, XXXXX,                  XXXXX,  KP_7,  KP_8,  KP_9,  PSLS,  PAST,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, XXXXX,  MPRV,  VOLD,  MPLY, XXXXX,                   PDOT,  KP_4,  KP_5,  KP_6,  MINS,  PLUS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                  XXXXX,  KP_1,  KP_2,  KP_3,  PDOT,  EQL,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____,   SPC,      ENT,  KP_0,  PDOT \
                              //`--------------------'  `--------------------'
  ),

  [_TEMPLATE] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _____, _____, _____, _____, _____, _____,                  _____, _____, _____, _____, _____, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____, _____, _____, _____, _____,                  _____, _____, _____, _____, _____, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____, _____, _____, _____, _____,                  _____, _____, _____, _____, _____, _____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____, _____,    _____, _____, _____ \
                              //`--------------------'  `--------------------'
  )
};

// void matrix_init_keymap(void) {
//   //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
//   #ifdef SSD1306OLED
//     iota_gfx_init(!has_usb());   // turns on the display
//   #endif
//  }


//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_logo(void);

char matrix_line_str[24];

const char *read_layer_state(void) {
  uint8_t layer = biton32(layer_state);

  strcpy(matrix_line_str, "Layer: ");

  switch (layer) {
    case _UTIL:
      strcat(matrix_line_str, "Utility");
      break;
    case _FN:
      strcat(matrix_line_str, "Function");
      break;
    case _NAV:
      strcat(matrix_line_str, "Navigation");
      break;
    case _SYM:
      strcat(matrix_line_str, "Symbol");
      break;
    case _QWERTY:
      strcat(matrix_line_str, "QWERT");
      break;
    case _COLEMAKDHM:
      strcat(matrix_line_str, "Colemak DHm");
      break;
    case _GAME:
      strcat(matrix_line_str, "Gaming");
      break;
    default:
      sprintf(matrix_line_str + strlen(matrix_line_str), "Unknown (%d)", layer);
  }

  return matrix_line_str;
}

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    matrix_write_ln(matrix, read_layer_state());
   } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED
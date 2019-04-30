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

#define CLMK TO(0)
#define QWERT TO(1)
#define GAME TO(3)

#define T_NAV TT(10)
#define S_NAV MO(10)

#define SYM_SP LT(_SYM, KC_SPC)
#define NV_ENT LT(_NAV, KC_ENT)
#define FN_ESC LT(_FN, KC_ESC)
#define UT_TAB LT(_UTIL, KC_TAB)

#define SH_BS LSFT_T(KC_BSPC)
#define SH_ENT RSFT_T(KC_ENT)


#define LCTBR LCTL_T(KC_LBRACKET)
#define RCTBR RCTL_T(KC_RBRACKET)

#define RCTLENT RCTL_T(KC_ENT)

#define TABFWD LCTL(KC_TAB)
#define TABBCK LCTL(LSFT(KC_TAB))

#define ALT_TAB LALT(KC_TAB)
#define ALT_SFT LALT(KC_LSFT)

#define KC_ALTAB ALT_TAB
#define KC_ALSFT ALT_SFT

#define _COLEMAKDHM 0
#define _QWERTY 1
#define _GAME 3

#define _FN 7
#define _SYM 8
#define _UTIL 9
#define _NAV 10
#define _TEMPLATE 16

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

#define KC_CLMK  CLMK
#define KC_QWERT  QWERT
#define KC_GAME  GAME

#define KC_T_NAV T_NAV
#define KC_S_NAV S_NAV

#define KC_SYM_SP SYM_SP
#define KC_NV_ENT NV_ENT
#define KC_FN_ESC FN_ESC
#define KC_UT_TAB UT_TAB

#define KC_TABFWD TABFWD
#define KC_TABBCK TABBCK

#define KC_LCTBR LCTBR
#define KC_RCTBR RCTBR

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAKDHM] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
     FN_ESC,     Q,     W,     F,     P,     B,                      J,     L,    U,     Y,   SCLN,  BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     UT_TAB,     A,     R,     S,     T,     G,                      M,     N,     E,     I,     O,  QUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      LCTBR,     Z,     X,     C,     D,     V,                      K,     H,  COMM,   DOT,  SLSH, RCTBR,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                   LALT,  LSPO, SYM_SP,   NV_ENT, RSPC, RGUI \
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
                                  _____, LSFT,  _____,    _____,   RSFT, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_SYM] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        GRV,     1,     2,     3,     4,     5,                      6,     7,     8,     9,     0,  BSLS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       TILD,  EXLM,    AT,  HASH,   DLR,  PERC,                   CIRC,  AMPR,  ASTR,  MINS,  PLUS,  PIPE,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____, _____, _____, ALSFT, _____,                  _____, _____, _____,  UNDS,   EQL, _____,\
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
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____,  SPC,    T_NAV, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_FN] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _____,  CLMK,  GAME, QWERT, XXXXX, XXXXX,                     F1,    F2,    F3,    F4,    F5, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
        RST,  LHUI,  LSAI,  LVAI, LFMOD, LTOG,                      F6,    F7,    F8,    F9,   F10, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____,  LHUD,  LSAD,  LVAD, LRMOD, XXXXX,                    F11,   F12, XXXXX, XXXXX, XXXXX, _____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____,   SPC,      ENT, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_UTIL] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      ESC,   XXXXX,  MSTP,  VOLU,  MNXT, XXXXX,                  XXXXX,  KP_7,  KP_8,  KP_9,  PSLS,  PAST,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, XXXXX,  MPRV,  VOLD,  MPLY, XXXXX,                   KP_0,  KP_4,  KP_5,  KP_6,  MINS,  PLUS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                  XXXXX,  KP_1,  KP_2,  KP_3,  PDOT,  EQL,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____,   SPC,      ENT, _____, _____ \
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
char layer_state_str[24];

const char* read_layer_state(void) {
  switch (biton32(layer_state)) {
    case _UTIL:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Utility ");
      break;
    case _FN:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Function ");
      break;
    case _NAV:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Navigation ");
      break;
    case _SYM:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Symbol ");
      break;
    case _QWERTY:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: QWERTY ");
      break;
    case _COLEMAKDHM:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Colemak DHm ");
      break;
    case _GAME:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Game ");
      break;
    default:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }
  return layer_state_str;
}

// const char *read_layer_state(void) {
//   static char layer_state_str[24];
//   char layer_name[17];

//   switch (biton32(layer_state)) {
//     case _UTIL:
//       strcpy(layer_name, "Utility");
//       break;
//     case _FN:
//       strcpy(layer_name, "Function");
//       break;
//     case _NAV:
//       strcpy(layer_name, "Navigation");
//       break;
//     case _SYM:
//       strcpy(layer_name, "Symbol");
//       break;
//     case _QWERTY:
//       strcpy(layer_name, "QWERT");
//       break;
//     case _COLEMAKDHM:
//       strcpy(layer_name, "Colemak DH");
//       break;
//     case _GAME:
//       strcpy(layer_name, "Gaming");
//       break;
//     default:
//       snprintf(layer_name, sizeof(layer_name), "Undef-%ld", layer_state);
//   }

//   strcpy(layer_state_str, "Layer: ");

//   strcat(layer_state_str, layer_name);
//   strcat(layer_state_str, "\n");
//   return layer_state_str;
// }


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

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

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

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

#define LCTLBR LCTL_T(KC_LBRACKET)
#define RCTLBR RCTL_T(KC_RBRACKET)

#define TABFWD LCTL(KC_TAB)
#define TABBCK LCTL(LSFT(KC_TAB))

#define _COLEMAKDHM 0
#define _QWERTY 1
#define _GAME 3

#define _FN 7
#define _SYM 8
#define _UTIL 9
#define _NAV 10

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
     LCTLBR,     Z,     X,     C,     D,     V,                      K,     H,  COMM,   DOT,  SLSH, RCTLBR,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                   LALT,  LSPO, SYM_SP,   S_NAV,  RSPC, RGUI \
                              //`--------------------'  `--------------------'
  ),

  [_QWERTY] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _____, _____, _____,     E,     R,     T,                      Y,     U,     I,     O,     P, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____,     S,     D,     F, _____,                      H,     J,     K,     L,  SCLN, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____, _____, _____,     V,     B,                  _____,     N,     M, _____, _____  _____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____, _____,    _____, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_GAMING] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        ESC, _____, _____, _____, _____, _____,                  _____, _____, _____, _____, _____, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
        TAB, _____, _____, _____, _____, _____,                  _____, _____, _____, _____, _____, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LCTL, _____, _____, _____, _____, _____,                  _____, _____, _____, _____, _____   RCTL,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                    LALT, LSPO,   SPC,      ENT,  RSPC,  RGUI \
                              //`--------------------'  `--------------------'
  ),

  [_SYM] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        GRV,     1,     2,     3,     4,     5,                      6,     7,     8,     9,     0,  BSLS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       TILD,  EXLM,    AT,  HASH,   DLR,  PERC,                   CIRC,  AMPR,  ASTR,  MINS,  PLUS,  PIPE,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____, _____,  LCBR,  LBRC,  LPRN,                   RPRN,  RBRC,  RCBR,  UNDS,   EQL, _____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____, _____,      DEL, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_NAV] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        ESC,  WH_U,TABBCK,  MS_U,TABFWD,  BTN2,                   PGUP,  HOME,    UP,   END, XXXXX,   DEL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       TILD,  WH_D,  MS_L,  MS_D,  MS_R,  BTN1,                   CIRC,  PGDN,  LEFT,  DOWN,  RGHT, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, XXXXX,  WH_L, XXXXX,  WH_R, XXXXX,                  XXXXX,  ACL0,  ACL1,  ACL2, XXXXX, _____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____,  BSPC,    T_NAV, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_FN] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      RESET,  CLMK,  GAME, QWERT, XXXXX, XXXXX,                     F1,    F2,    F3,    F4,    F5, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      XXXXX,  LHUI,  LSAI,  LVAI, LFMOD, LTOG,                      F6,    F7,    F8,    F9,   F10, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____,  LHUD,  LSAD,  LVAD, LRMOD, XXXXX,                    F11,   F12, XXXXX, XXXXX, XXXXX, _____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____,   SPC,      ENT, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_UTIL] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _____,  MSTP,  VOLU,  MNXT, XXXXX, XXXXX,                  XXXXX,  KP_7,  KP_8,  KP_9,  PSLS,  PAST,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____,  MPRV,  VOLD,  MPLY, XXXXX, XXXXX,                   PDOT,  KP_4,  KP_5,  KP_6,  MINS,  PLUS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                   KP_0,  KP_1,  KP_2,  KP_3,  XXXXX,  EQL,\
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

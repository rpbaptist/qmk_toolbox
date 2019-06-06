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

#define _COLEMAKDHM 0
#define _QWERTY 1
#define _GAME 3
#define _FN 7
#define _SYM 8
#define _UTIL 9
#define _NAV 10
#define _TEMPLATE 16

#define KC_CLMK DF(0)
#define KC_QWERT DF(1)
#define KC_GAME DF(3)

// #define KC_T_SYM TT(8)
// #define KC_S_SYM MO(8)

#define KC_T_NAV TT(10)
#define KC_S_NAV MO(10)

#define KC_NV_ENT LT(_NAV, KC_ENT)
#define KC_FN_ESC LT(_FN, KC_ESC)
#define KC_UT_TAB LT(_UTIL, KC_TAB)
#define KC_SYMSPC LT(_SYM, KC_SPC)

#define KC_LCTLT LCTL_T(KC_LT)

#define KC_CTRGUI LCTL_T(KC_LGUI)
#define KC_CTLENT RCTL_T(KC_ENT)

#define KC_ALTBR LALT_T(KC_LBRACKET)
#define KC_GUIBR RGUI_T(KC_RBRACKET)

// #define KC_ALSPC LALT_T(KC_SPC)
// #define KC_ALTSF LALT(KC_LSFT)

#define KC_TABFWD LCTL(KC_TAB)
#define KC_TABBCK LCTL(LSFT(KC_TAB))

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
     CTRGUI,     Z,     X,     C,     D,     V,                      K,     H,  COMM,   DOT,  SLSH, CTLENT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  ALTBR,  LSPO, SYMSPC,   T_NAV,  RSPC, GUIBR \
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
        TAB, _____, _____, _____, _____, _____,                  _____, _____, _____, _____, _____, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LCTL, _____, _____, _____, _____, _____,                  _____, _____, _____, _____, _____, _____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                   LALT, LSFT,  _____,    _____,  RSFT, RGUI \
                              //`--------------------'  `--------------------'
  ),

  [_SYM] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        GRV,     1,     2,     3,     4,     5,                      6,     7,     8,     9,     0,  BSLS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       TILD,  EXLM,    AT,  HASH,   DLR,  PERC,                   CIRC,  AMPR,  ASTR,  MINS,  PLUS,  PIPE,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LCPO, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX,  UNDS,   EQL,  RCPC,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____, _____,     LGUI,  RALT, RGUI \
                              //`--------------------'  `--------------------'
  ),

  [_NAV] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        ESC,  WH_U,TABBCK,  MS_U,TABFWD,  BTN2,                   PGUP,  HOME,    UP,   END, XXXXX,   DEL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
        TAB,  WH_D,  MS_L,  MS_D,  MS_R,  BTN1,                   PGDN,  LEFT,  DOWN,  RGHT, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, XXXXX,  WH_L, XXXXX,  WH_R, XXXXX,                  XXXXX,  ACL0,  ACL1,  ACL2, XXXXX, _____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+-----+-------|
                                  _____, _____,   SPC,    S_NAV, _____,  RGUI \
                              //`--------------------'  `--------------------'
  ),

  [_FN] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _____,    F1,    F2,    F3,    F4,    F5,                     F6,    F7,    F8,    F9,   F10,   F11,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
        RST, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                   LTOG, LFMOD,  LHUI,  LSAI,  LVAI,   F12,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       PSCR,  CLMK,  GAME, QWERT, XXXXX, XXXXX,                  XXXXX, LRMOD,  LHUD,  LSAD,  LVAD,  CAPS,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____,   SPC,    XXXXX, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_UTIL] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      ESC,   XXXXX,  MSTP,  VOLU,  MNXT, XXXXX,                   NLCK,  KP_7,  KP_8,  KP_9,  PSLS,  PAST,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, XXXXX,  MPRV,  VOLD,  MPLY, XXXXX,                   PDOT,  KP_4,  KP_5,  KP_6,  MINS,  PLUS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                   KP_0,  KP_1,  KP_2,  KP_3,   EQL,   ENT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____,   SPC,    XXXXX,  KP_0,  PDOT \
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

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_master) {
    return OLED_ROTATION_270;
  } else {
    return OLED_ROTATION_180;
  }
}

void render_crkbd_logo(void) {
  static const char PROGMEM crkbd_logo[] = {
      0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
      0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
      0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
      0};
  oled_write_P(crkbd_logo, false);
}


void render_status(void) {
  // oled_write_P(PSTR("Layout: "), false);
  switch (biton32(default_layer_state)) {
    case _COLEMAKDHM:
      oled_write_P(PSTR("ORBIT"), false);
      break;
    case _GAME:
      oled_write_P(PSTR("PULSE"), false);
      break;
    case _QWERTY:
      oled_write_P(PSTR("DELAY"), false);
      break;
  }

  oled_write_P(PSTR("\n"), false);

  switch (biton32(layer_state)) {
    case 0:
      oled_write_P(PSTR("     "), false);
      break;
    case _FN:
      oled_write_P(PSTR("Abort"), false);
      break;
    case _SYM:
      oled_write_P(PSTR("Comm "), false);
      break;
    case _UTIL:
      oled_write_P(PSTR("Stage"), false);
      break;
    case _NAV:
      oled_write_P(PSTR("Gyro "), false);
      break;
    default:
      oled_write_P(PSTR("Unkn "), false);
      break;
  }
  oled_write_P(PSTR("\n"), false);

  uint8_t modifiers = get_mods();

  oled_write_P( (modifiers & MOD_MASK_CTRL)  ? PSTR("PROG ") : PSTR("     "), false);
  oled_write_P( (modifiers & MOD_MASK_SHIFT) ? PSTR("FUEL ") : PSTR("     "), false);
  oled_write_P( (modifiers & MOD_MASK_ALT)   ? PSTR("AUX  ") : PSTR("     "), false);
  oled_write_P( (modifiers & MOD_MASK_GUI)   ? PSTR("DOCK ") : PSTR("     "), false);

  oled_write_P(PSTR("\n"), false);

  uint8_t led_usb_state = host_keyboard_leds();
  oled_write_P(PSTR("Mode:\n"), false);
  oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK)    ? PSTR(" NUM ") : PSTR("     "), false);
  oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK)   ? PSTR(" CAPS") : PSTR("     "), false);
  oled_write_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR(" SCRL") : PSTR("     "), false);
}


void oled_task_user(void) {
  if (is_master) {
    render_status();     // Renders the current keyboard state (layer, lock, caps, scroll, etc)
  } else {
    render_crkbd_logo();
    // oled_scroll_left();  // Turns on scrolling
  }
}
#endif


#ifndef RGBLIGHT_RECONFIG_H
#define RGBLIGHT_RECONFIG_H

#ifdef RGBLIGHT_ANIMATIONS
   // for backward compatibility
   #define RGBLIGHT_EFFECT_BREATHING
   #define RGBLIGHT_EFFECT_RAINBOW_MOOD
   #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#endif

#ifdef RGBLIGHT_STATIC_PATTERNS
   #define RGBLIGHT_EFFECT_STATIC_GRADIENT
#endif

// check dynamic animation effects chose ?
#if defined(RGBLIGHT_EFFECT_BREATHING) || \
    defined(RGBLIGHT_EFFECT_RAINBOW_MOOD) || \
    defined(RGBLIGHT_EFFECT_RAINBOW_SWIRL)
  #define RGBLIGHT_USE_TIMER
  #ifndef RGBLIGHT_ANIMATIONS
    #define RGBLIGHT_ANIMATIONS  // for backward compatibility
  #endif
#endif

#endif // RGBLIGHT_RECONFIG_H

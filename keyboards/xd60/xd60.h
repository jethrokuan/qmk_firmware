#ifndef XD60_H
#define XD60_H

#include "quantum.h"
#include "led.h"

/* XD60 LEDs
 *   GPIO pads
 *   0 F7 not connected
 *   1 F6 RGB PWM Underglow
 *   2 F5 Backlight LED
 *   3 F4 not connected
 *   B2 Capslock LED
 *   B0 not connected
 */
inline void xd60_caps_led_on(void)    { DDRB |=  (1<<2); PORTB &= ~(1<<2); }
inline void xd60_bl_led_on(void)    	{ DDRF |=  (1<<5); PORTF &= ~(1<<5); }

inline void xd60_caps_led_off(void)   { DDRB &= ~(1<<2); PORTB &= ~(1<<2); }
inline void xd60_bl_led_off(void)   	{ DDRF &= ~(1<<5); PORTF &= ~(1<<5); }

/* XD60 Keymap Definition Macro */
#define KEYMAP(                                                         \
               K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,       K014, \
               K100,       K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, \
               K200,       K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, \
               K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311,       K313, K314, \
               K400, K401,       K403,             K406,                   K410, K411,       K413, K414 \
                ) {                                                     \
    { K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,  KC_NO, K014 }, \
    { K100,  KC_NO, K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,  K113,  K114 }, \
    { K200,  KC_NO, K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,  K213,  KC_NO }, \
    { KC_NO, K301,  K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  K311,  KC_NO, K313,  K314 }, \
    { K400,  K401,  KC_NO, K403,  KC_NO, KC_NO, K406,  KC_NO, KC_NO, KC_NO, K410,  K411,  KC_NO, K413,  K414 } \
      }

#endif

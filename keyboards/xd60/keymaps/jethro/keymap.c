#include "xd60.h"
#include "action_layer.h"

#undef KEYMAP
#define KEYMAP(                                                         \
               K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C,  K0D, \
               K10,  K11,  K12,  K13,  K14,  K15,  K16,  K17,  K18,  K19,  K1A,  K1B,  K1C,  K1D, \
               K20,  K21,  K22,  K23,  K24,  K25,  K26,  K27,  K28,  K29,  K2A,  K2B,        K2D, \
               K30,        K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3D,  K3C, \
               K40,  K41,  K42,              K45,                          K4A,  K4B,  K4C,  K4D \
                                                                        ) { \
    { K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C,  K0D }, \
    { K10,  K11,  K12,  K13,  K14,  K15,  K16,  K17,  K18,  K19,  K1A,  K1B,  K1C,  K1D }, \
    { K20,  K21,  K22,  K23,  K24,  K25,  K26,  K27,  K28,  K29,  K2A,  K2B,  KC_NO,  K2D }, \
    { K30,  KC_NO,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C,  K3D }, \
    { K40,  K41,  K42,  KC_NO,KC_NO,K45,  KC_NO, KC_NO,  KC_NO,  KC_NO,  K4A,  K4B,  K4C,  K4D } \
  }

/* Multi-keys */
#define CTLBSPC MT(MOD_LCTL, KC_BSPC)
#define N_PLUS KC_KP_PLUS
#define N_SLSH KC_KP_SLASH
#define N_MNUS KC_KP_MINUS
#define N_ASTK KC_KP_ASTERISK

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // 0: Base Layer (QWERTY)
  /*

   ╭────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────────╮
   | `  │ 1  │ 2  │ 3  │ 4  │ 5  │  6 │  7 │  8 │  9 │  0 │ -  │ =  |   BSPC │
   ├────┴┬───┴┬─-─┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───────┤
   │ TAB | Q  | W  │ E  |  R │ T  │ Y  │ U  │ I  │ O  │ P  │ [  │ ]  │   \   │
   ├─────┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴───────┤
   │C/BSP │ A  │ S  │ D  │ F  │ G  │ H  │ J  │ K  │ L  │ ;  │ '  | ENT       │
   ├──────┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴──────┬────┤
   │ LSHFT │ Z  │ X  │ C  │ V  │ B  │ N  │ M  │ ,  │ .  │ /  │      UP  |DEL │
   ├──────┬┴────┴┬───┴──┬─┴────┴────┴────┴────┴────┴─┬──┴──┬─┴───┬────┬─┴────┤
   │ LCTL │LGUI  │ LALT │           SPC              │ F(0)|LEFT │DOWN| RGHT │
   ╰──────┴──────┴──────┴────────────────────────────┴─────┴─────┴────┴──────╯

  */
  KEYMAP(
         KC_GRAVE, KC_1,    KC_2,    KC_3,   KC_4, KC_5,    KC_6,    KC_7,      KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
         KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R, KC_T,    KC_Y,    KC_U,      KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
         CTLBSPC,  KC_A,    KC_S,    KC_D,   KC_F, KC_G,    KC_H,    KC_J,      KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT, \
         KC_LSFT,  KC_Z,    KC_X,    KC_C,   KC_V, KC_B,    KC_N,    KC_M,      KC_COMM, KC_DOT, KC_SLSH, KC_UP,   KC_DEL, \
         KC_LCTL,  KC_LGUI, KC_LALT, KC_SPC, F(0), KC_LEFT, KC_DOWN, KC_RIGHT), 

  // 1: Function Layer

  /*

    ╭────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────────╮
    | ESC│ F1 │ F2 │ F3 │ F4 │ F5 │ F6 │ F7 │ F8 │ F9 │ F10│ F11│ F12|  DEL   │
    ├────┴┬───┴┬─-─┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───────┤
    │     |PSC |LCK │PAUS|    │    │    |    │  1 │ 2  │ 3  │ +  | *  | NLCK  │
    ├─────┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴───────┤
    │      │VOLU│VOLD│MUTE│    │    |    │    │ 4  │ 5  │ 6  │ -  | /         │
    ├──────┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴──────┬────┤
    │       │PGUP│PGDN│HOME|END │    |    │    │  7 │ 8  │ 9  | 0        |BSPC│
    ├──────┬┴────┴┬───┴──┬─┴────┴────┴────┴────┴────┴─┬──┴──┬─┴───┬────┬─┴────┤
    │ RESET│      │      │                            │ F(0)| DOT │ENT |      │
    ╰──────┴──────┴──────┴────────────────────────────┴─────┴─────┴────┴──────╯

  */

  KEYMAP(
         KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,   KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  \
         KC_NO,  KC_PSCR, KC_SLCK, KC_PAUS, KC_NO,  KC_NO,   KC_NO,  KC_NO,  KC_1, KC_2, KC_3, N_PLUS, N_ASTK, KC_NO, \
         KC_NO,  KC_VOLU, KC_VOLD, KC_MUTE, KC_NO,  KC_NO,   KC_NO,  KC_NO,  KC_4, KC_5, KC_6, KC_MINUS, N_SLSH, \
         KC_NO,  KC_PGUP, KC_PGDN, KC_HOME, KC_END, KC_NO,   KC_NO,  KC_NO,  KC_7, KC_8, KC_9, KC_0, KC_BSPC, \
         RESET,  KC_NO,   KC_NO,   KC_NO,   F(0),  KC_DOT, KC_ENT, KC_NO),
};

// Custom Actions
const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay 
};

// Macros
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

  // MACRODOWN only works in this function
  switch(id) {
  case 0:
    if (record->event.pressed) { register_code(KC_RSFT); }
    else { unregister_code(KC_RSFT); }
    break;
  }

  return MACRO_NONE;
};

// Loop
void matrix_scan_user(void) {
  // Empty
};

#include QMK_KEYBOARD_H

// readability
#define _______ KC_TRNS
#define XXXXXXX KC_NO
enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _NUMPAD,
  _FUNCTION,
  _RGB
};

enum macro_Keycodes {
    FMT_A = SAFE_RANGE,  // Format all code macro
    CMT_CD,  // Comment code macro
	UNCMT_CD // Uncomment code macro
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	/* Layer QWERTY
	 * ,-----------------------------------------------------------------------------------.
	 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
	 * |------+------+------+------+------+-------------+------+------+------+------+------|
	 * |Tab/Lo|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |  
	 * |------+------+------+------+------+------|------+------+------+------+------+------|
	 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * | Ctrl |  GUI | ALT  |NUMPAD|LOWER |    Space    |RAISE |FUNC  | Left | Down |Right |
	 * `-----------------------------------------------------------------------------------'
	 */
	[_QWERTY] = LAYOUT_planck_mit(
		KC_GESC,             KC_Q,     KC_W,    KC_E,        KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,          KC_O,    KC_P,    KC_BSPC,
		LT(_LOWER, KC_TAB),  KC_A,     KC_S,    KC_D,        KC_F,   KC_G,   KC_H,   KC_J,    KC_K,          KC_L,    KC_SCLN, KC_QUOT,
		KC_LSFT,             KC_Z,     KC_X,    KC_C,        KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM,       KC_DOT,  KC_UP,   KC_ENT,
		KC_LCTRL,            KC_LGUI,  KC_LALT, MO(_NUMPAD), _LOWER,     KC_SPC,     _RAISE,  MO(_FUNCTION), KC_LEFT, KC_DOWN, KC_RIGHT
  ),


   /* LOWER
		
	* ,-----------------------------------------------------------------------------------.
	* |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   Up |   (  |   )  | Bksp |
	* |------+------+------+------+------+-------------+------+------+------+------+------|
	* |      |      |      |      |      |      | Home | Left | Down |Right | End  |      |
	* |------+------+------+------+------+------|------+------+------+------+------+------|
	* |      |      |      |      |      |      |      |wordLe|      |wordRi|      |      |
	* |------+------+------+------+------+------+------+------+------+------+------+------| 
	* |      |      |      |      |      |             |      |      |      |      |      |
	* `-----------------------------------------------------------------------------------'
	*/
	[_LOWER] = LAYOUT_planck_mit(
		KC_GRAVE, KC_EXLM, KC_AT,   KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,   KC_AMPR,         KC_UP,    KC_LPRN,         KC_RPRN,  KC_BSPC,
		_______, _______, _______,  _______,  _______,  _______,  KC_HOME,   KC_LEFT,         KC_DOWN,  KC_RIGHT,        KC_END,   _______,
		_______, _______, _______,  _______,  _______,  _______,  _______,   LALT(KC_LEFT),   _______,  LALT(KC_RIGHT),  _______,  _______,
		_______, _______, _______,  _______,  _______,      _______,         _______,         _______,  _______,         _______,  _______
	),


   /* RAISE
	* ,-----------------------------------------------------------------------------------.
	* |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
	* |------+------+------+------+------+-------------+------+------+------+------+------|
	* |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   {  |   }  |  \   |
	* |------+------+------+------+------+------|------+------+------+------+------+------|
	* |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   _  |   /  |   [  |  ]   |Enter |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      |      |      |      |             |      |      |      |      |      |
	* `-----------------------------------------------------------------------------------'
	*/
	[_RAISE] = LAYOUT_planck_mit(
		KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
		_______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS,    KC_EQL,     KC_LCBR, KC_RCBR, KC_BSLASH,
		_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_UNDS,    KC_SLSH,    KC_LBRC, KC_RBRC,  KC_PIPE,
		_______, _______, _______, _______, _______,     _______,      _______,    _______,    _______, _______, _______
	),



  	/* NUMPAD 
	 * ,-----------------------------------------------------------------------------------.
	 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |      |      | save |      |Format|      |      |   4  |   5  |   6  |      |      |
	 * |------+------+------+------+------+------|------+------+------+------+------+------|
	 * |      |      |      |Commen|UNCMT*|      |      |   1  |   2  |   3  |      |      |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |      |      |      |      |      |             |      |   0  |      |      |      |
	 * `-----------------------------------------------------------------------------------'
	 */ 
	[_NUMPAD] = LAYOUT_planck_mit(
		_______, KC_1,    KC_2,          KC_3,    KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
		_______, _______, LCTL(S(KC_S)), _______, FMT_A,    _______, _______, KC_4,    KC_5,    KC_6, _______, KC_DEL,
		_______, _______, _______,       CMT_CD,  UNCMT_CD, _______, _______, KC_1,    KC_2,    KC_3, _______, _______,
		_______, _______, _______,       _______, _______,     _______,   _______,    KC_0, _______, _______, _______
    ),



    /* RGB control. Raise and Lower at the same time. 
   * ,-----------------------------------------------------------------------------------.
   * | RESET|RGBtog|RGBmod|RGBhud|RGBhui|RGBsai|RGBsad|      |      |      |      |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |BLtogg|BLstep|      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |Prev  |Play  |Next  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |VolDo |Mute  |Vol U |
   * `-----------------------------------------------------------------------------------'
   HUE Increase = HUI
   Saturation Increase = SAI
   */ 
  [_RGB] = LAYOUT_planck_mit(
    RESET, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAI, RGB_SAD, _______, _______, _______, _______, _______,
    _______, BL_TOGG, BL_STEP, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______,  _______,  _______,  _______,  _______,   _______,   _______,  _______,  _______,  _______,
	_______, _______, _______,  _______,  _______,      _______,        _______,   _______,   _______,  _______,  _______
  ),

   /* ,-----------------------------------------------------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |Prev  |Play  |Next  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |VolDo |Mute  |Vol U |
   * `-----------------------------------------------------------------------------------'
   */ 
  [_FUNCTION] = LAYOUT_planck_mit(
    KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_F6,   KC_F7,    KC_F8,     KC_F9,   KC_F10,  KC_F11,   KC_F12,
    _______, _______, _______,  _______,  _______,  _______, _______, _______,  _______,   _______, _______, _______,
	_______, _______, _______,  _______,  _______,  _______, _______, _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  _______,
	_______, _______, _______,  _______,  _______,      _______,      _______,  _______,  KC_VOLD,  KC_MUTE,  KC_VOLU
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case _LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _RGB);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _RGB);
      }
      return false;
      break;
    case _RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _RGB);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _RGB);
      }
      return false;
      break;
	 case FMT_A:
		SEND_STRING(SS_LGUI("akf"));
		return false;
		break;
	case CMT_CD:
		SEND_STRING(SS_LGUI("k")SS_LGUI("c"));
		return false;
		break;
	case UNCMT_CD:
		SEND_STRING(SS_LGUI("k")SS_LGUI("u"));
		return false;
		break;
  }
  return true;
}

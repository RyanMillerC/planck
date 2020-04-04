/* Copyright 2019 Ryan Miller, 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _FUNCTION,
  _NAVIGATION,
  _ADJUST
};

enum planck_keycodes {
  BASE = SAFE_RANGE,
  BACKLIT,
};

// Layers
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNCTION MO(_FUNCTION)
#define NV_TAB LT(_NAVIGATION, KC_TAB)
#define NV_SEMI LT(_NAVIGATION, KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base
   * ,-----------------------------------------------------------------------------------.
   * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bspc |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Tab* |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  | Semi*| Enter|
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Func | Ctrl | GUI  | Alt  | Lower|    Space    | Raise| Alt  | GUI  | Ctrl |CapsLk|
   * `-----------------------------------------------------------------------------------'
   *  Tab*   --> Hold for Navigation layer; Press for Tab
   *  Quote* --> Hold for Shift; Press for quote
   *  Semi*  --> Hold for Navigation layer; Press for Semi-colon
   */
  [_BASE] = LAYOUT_planck_grid(
      KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      NV_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    NV_SEMI, KC_ENT,
      KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
      FUNCTION, KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RALT, KC_RGUI, KC_RCTL, KC_CAPS
  ),

  /* Lower
   * ,-----------------------------------------------------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |   _  |   +  |   {  |   }  |   :  |   |  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |   <  |   >  |   ?  |   "  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
   * `-----------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT_planck_grid(
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
      _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_COLN, KC_PIPE,
      _______, _______, _______, _______, _______, _______, _______, _______, KC_LABK, KC_RABK, KC_QUES, KC_DQUO,
      _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
  ),

  /* Raise
   * ,-----------------------------------------------------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |   -  |   =  |   [  |   ]  |   ;  |  \   |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |   ,  |   .  |   /  |  '   |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
   * `-----------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT_planck_grid(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
      _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_SCLN, KC_BSLS,
      _______, _______, _______, _______, _______, _______, _______, _______, KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
      _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
  ),

  /* Function
   * ,-----------------------------------------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |  F11 |  F12 |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_FUNCTION] = LAYOUT_planck_grid(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
      _______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Navigation
   * ,-----------------------------------------------------------------------------------.
   * |      |      |      |      |      |      | Home |      |      | End  |      | Del  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      | Left | Down | Up   | Right|      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      | Ctrl-|Pg Dwn| Pg Up| Ctrl+|      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_NAVIGATION] = LAYOUT_planck_grid(
      _______, _______, _______, _______, _______, _______, KC_HOME,    _______, _______, KC_END,      _______, KC_DEL,
      _______, _______, _______, _______, _______, _______, KC_LEFT,    KC_DOWN, KC_UP,   KC_RIGHT,    _______, _______,
      _______, _______, _______, _______, _______, _______, C(KC_LEFT), KC_PGDN, KC_PGUP, C(KC_RIGHT), _______, _______,
      _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,     _______, _______
  ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------------------------------------------------.
   * |      | Reset| Debug|      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_ADJUST] = LAYOUT_planck_grid(
      _______, RESET,   DEBUG,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

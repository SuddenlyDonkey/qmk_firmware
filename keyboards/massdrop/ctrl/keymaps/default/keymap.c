#include QMK_KEYBOARD_H

enum alt67_keycodes {
    L_BRI = SAFE_RANGE, //LED Brightness Increase
    L_BRD,              //LED Brightness Decrease
    L_PTN,              //LED Pattern Select Next
    L_PTP,              //LED Pattern Select Previous
    L_PSI,              //LED Pattern Speed Increase
    L_PSD,              //LED Pattern Speed Decrease
    L_T_MD,             //LED Toggle Mode
    L_T_ONF,            //LED Toggle On / Off
    L_ON,               //LED On
    L_OFF,              //LED Off
    L_T_BR,             //LED Toggle Breath Effect
    L_T_PTD,            //LED Toggle Scrolling Pattern Direction
    L_MODE,             //LED change mode
    U_T_AUTO,           //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,           //USB Toggle Automatic GCR control
    L_KFSI,             // LED keypress fade increase
    L_KFSD,             // LED keypress fade decrease
    L_RI,               // LED reactive fade increase
    L_RD,               // LED reactive fade decrease
    DBG_TOG,            //DEBUG Toggle On / Off
    DBG_MTRX,           //DEBUG Toggle Matrix Prints
    DBG_KBD,            //DEBUG Toggle Keyboard Prints
    DBG_MOU            //DEBUG Toggle Mouse Prints
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN, \
        KC_NO, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                              KC_UP, \
        KC_LCTL, KC_LGUI, KC_LALT,                  KC_SPC,                              KC_RALT, MO(1),   KC_APP,  KC_RCTL,            KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [1] = LAYOUT(
        DBG_TOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_MUTE, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_MPLY, KC_MSTP, KC_VOLU, \
        L_T_BR,  L_PSD,   L_BRI,   L_PSI,   KC_TRNS, KC_TRNS, KC_TRNS, U_T_AUTO,U_T_AGCR,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_MPRV, KC_MNXT, KC_VOLD, \
        L_T_PTD, L_PTP,   L_BRD,   L_PTN,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, L_T_MD,  L_T_ONF, KC_TRNS, KC_TRNS, KC_TRNS, TG_NKRO, L_MODE,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              L_RI, \
        KC_TRNS, KC_TRNS, KC_TRNS,                  KC_TRNS,                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            L_KFSD, L_RD, L_KFSI \
    ),
    /*
    [X] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG_NKRO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,                  KC_TRNS,                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS \
    ),
    */
};

const uint16_t PROGMEM fn_actions[] = {

};

uint32_t lfsr113_Bits (void) {
   static uint32_t z1 = 51358, z2 = 12858, z3 = 98731, z4 = 38645;
   uint32_t b;
   b  = ((z1 << 6) ^ z1) >> 13;
   z1 = ((z1 & 4294967294U) << 18) ^ b;
   b  = ((z2 << 2) ^ z2) >> 27;
   z2 = ((z2 & 4294967288U) << 2) ^ b;
   b  = ((z3 << 13) ^ z3) >> 21;
   z3 = ((z3 & 4294967280U) << 7) ^ b;
   b  = ((z4 << 3) ^ z4) >> 12;
   z4 = ((z4 & 4294967168U) << 13) ^ b;
   return (z1 ^ z2 ^ z3 ^ z4);
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT  (keyboard_report->mods & MOD_BIT(KC_LSHIFT) || keyboard_report->mods & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (keyboard_report->mods & MOD_BIT(KC_LCTL) || keyboard_report->mods & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (keyboard_report->mods & MOD_BIT(KC_LALT) || keyboard_report->mods & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(record->event.pressed) {
        // don't do funny business on the locking keys, since they already light
        // differently when held and it's not destinguishable anymore what they
        // do.
        if(keycode != KC_CAPS && keycode != KC_SLCK) {
            uint16_t scan_code = record->event.key.row * 15 + record->event.key.col;
            // we can just modify the read_buffer, since the LEDs are set
            // from read buffer and the led job then fills the write buffer.
            // we also set a brightness array as we don't need to interpolate for keypress fade
            desired_brightness[scan_code] = 1.0f;
            desired_interpolation[read_buffer][scan_code] = 1.0f;
            desired_interpolation[write_buffer][scan_code] = 1.0f;
            if(debug_enable) {
                dpf("kc=%d | sc=%d\r\n", keycode, scan_code);
            }
            /*
            uint32_t r = lfsr113_Bits();
            // reinterpret the uint32 as an uint32, which allows us to acces bits directly
            uint8_t *randomness = (uint8_t *)&r;
            uint16_t scan_color = scan_code * 3;
            target_color[scan_color] = randomness[3];
            target_color[scan_color + 1] = randomness[2];
            target_color[scan_color + 2] = randomness[1];
            */
        }
    }
    switch (keycode) {
        case L_BRI:
            if (record->event.pressed) {
                if (LED_GCR_STEP > LED_GCR_MAX - gcr_desired) gcr_desired = LED_GCR_MAX;
                else gcr_desired += LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_BRD:
            if (record->event.pressed) {
                if (LED_GCR_STEP > gcr_desired) gcr_desired = 0;
                else gcr_desired -= LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_PTN:
            if (record->event.pressed) {
                if (led_animation_id == led_setups_count - 1) led_animation_id = 0;
                else led_animation_id++;
            }
            return false;
        case L_PTP:
            if (record->event.pressed) {
                if (led_animation_id == 0) led_animation_id = led_setups_count - 1;
                else led_animation_id--;
            }
            return false;
        case L_PSI:
            if (record->event.pressed) {
                led_animation_speed += ANIMATION_SPEED_STEP;
            }
            return false;
        case L_PSD:
            if (record->event.pressed) {
                led_animation_speed -= ANIMATION_SPEED_STEP;
                if (led_animation_speed < 0) led_animation_speed = 0;
            }
            return false;
        case L_T_MD:
            if (record->event.pressed) {
                led_lighting_mode++;
                if (led_lighting_mode > LED_MODE_MAX_INDEX) led_lighting_mode = LED_MODE_NORMAL;
            }
            return false;
        case L_T_ONF:
            if (record->event.pressed) {
                led_enabled = !led_enabled;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_ON:
            if (record->event.pressed) {
                led_enabled = 1;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_OFF:
            if (record->event.pressed) {
                led_enabled = 0;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_T_BR:
            if (record->event.pressed) {
                led_animation_breathing = !led_animation_breathing;
                if (led_animation_breathing)
                {
                    gcr_breathe = gcr_desired;
                    led_animation_breathe_cur = BREATHE_MIN_STEP;
                    breathe_dir = 1;
                }
            }
            return false;
        case L_MODE:
            if(record->event.pressed) {
               led_anim_mode = led_anim_mode ? 0 : 1;
            }
            return false;
        case L_T_PTD:
            if (record->event.pressed) {
                led_animation_direction = !led_animation_direction;
            }
            return false;
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                usb_extra_manual = !usb_extra_manual;
                CDC_print("USB extra port manual mode ");
                CDC_print(usb_extra_manual ? "enabled" : "disabled");
                CDC_print("\r\n");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                usb_gcr_auto = !usb_gcr_auto;
                CDC_print("USB GCR auto mode ");
                CDC_print(usb_gcr_auto ? "enabled" : "disabled");
                CDC_print("\r\n");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                debug_enable = !debug_enable;
                CDC_print("Debug mode ");
                CDC_print(debug_enable ? "enabled" : "disabled");
                CDC_print("\r\n");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                debug_matrix = !debug_matrix;
                CDC_print("Debug matrix ");
                CDC_print(debug_matrix ? "enabled" : "disabled");
                CDC_print("\r\n");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                debug_keyboard = !debug_keyboard;
                CDC_print("Debug keyboard ");
                CDC_print(debug_keyboard ? "enabled" : "disabled");
                CDC_print("\r\n");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                debug_mouse = !debug_mouse;
                CDC_print("Debug mouse ");
                CDC_print(debug_mouse ? "enabled" : "disabled");
                CDC_print("\r\n");
            }
            return false;
        case L_KFSI:
            if (record->event.pressed) {
                led_keypress_fade_speed += KEY_PRESS_FADE_STEP;
            }
            return false;
        case L_KFSD:
            if (record->event.pressed) {
                led_keypress_fade_speed -= KEY_PRESS_FADE_STEP;
                if (led_keypress_fade_speed < 0.0005) led_keypress_fade_speed = 0.0005;
            }
            case L_RI:
                if (record->event.pressed) {
                    led_react_speed += REACT_FADE_STEP;
                }
                return false;
            case L_RD:
                if (record->event.pressed) {
                    led_react_speed -= REACT_FADE_STEP;
                    if (led_react_speed < 0.01) led_react_speed = 0.01;
                }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}

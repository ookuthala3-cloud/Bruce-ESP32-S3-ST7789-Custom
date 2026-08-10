#include "core/powerSave.h"
#include <interface.h>
#include <Arduino.h>

// ======================================================
//  ESP32-S3 ST7789 240x240 - 5 Push Buttons
// ======================================================

#ifndef BTN_UP
#define BTN_UP 12
#endif

#ifndef BTN_DOWN
#define BTN_DOWN 13
#endif

#ifndef BTN_LEFT
#define BTN_LEFT 17
#endif

#ifndef BTN_RIGHT
#define BTN_RIGHT 9
#endif

#ifndef BTN_SELECT
#define BTN_SELECT 14
#endif

#ifndef TFT_BL
#define TFT_BL 4
#endif

#define DEBOUNCE_TIME 50

// ======================================================
// GPIO SETUP
// ======================================================

void _setup_gpio() {
    pinMode(BTN_UP, INPUT_PULLUP);
    pinMode(BTN_DOWN, INPUT_PULLUP);
    pinMode(BTN_LEFT, INPUT_PULLUP);
    pinMode(BTN_RIGHT, INPUT_PULLUP);
    pinMode(BTN_SELECT, INPUT_PULLUP);

    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);
}

void _post_setup_gpio() {}

// ======================================================
// BATTERY
// ======================================================

int getBattery() {
    return 0;
}

// ======================================================
// BRIGHTNESS
// ======================================================

void _setBrightness(uint8_t brightval) {
    analogWrite(TFT_BL, brightval);
}

// ======================================================
// INPUT
// ======================================================

void InputHandler(void) {

    checkPowerSaveTime();

    PrevPress = false;
    NextPress = false;
    SelPress = false;
    AnyKeyPress = false;
    EscPress = false;
    DownPress = false;

    bool up     = digitalRead(BTN_UP) == LOW;
    bool down   = digitalRead(BTN_DOWN) == LOW;
    bool left   = digitalRead(BTN_LEFT) == LOW;
    bool right  = digitalRead(BTN_RIGHT) == LOW;
    bool select = digitalRead(BTN_SELECT) == LOW;

    bool anyButton =
        up ||
        down ||
        left ||
        right ||
        select;

    // --------------------------------------------------
    // Wake screen / reset Bruce power-save timer
    // --------------------------------------------------

    if (anyButton) {

        if (!wakeUpScreen()) {
            AnyKeyPress = true;
        } else {
            goto END;
        }
    }

    // --------------------------------------------------
    // Main Menu
    // LEFT / RIGHT navigate
    // --------------------------------------------------

    if (menuOptionLabel == "Main Menu") {

        if (left) {
            PrevPress = true;
            AnyKeyPress = true;
        }

        if (right) {
            NextPress = true;
            AnyKeyPress = true;
        }

        if (up) {
            PrevPress = true;
            AnyKeyPress = true;
        }

        if (down) {
            NextPress = true;
            AnyKeyPress = true;
        }
    }

    // --------------------------------------------------
    // Sub Menus
    // UP / DOWN navigate
    // LEFT = Back
    // RIGHT = extra/right action
    // --------------------------------------------------

    else {

        if (up) {
            PrevPress = true;
            AnyKeyPress = true;
        }

        if (down) {
            NextPress = true;
            AnyKeyPress = true;
        }

        if (left) {
            EscPress = true;
            AnyKeyPress = true;
        }

        if (right) {
            DownPress = true;
            AnyKeyPress = true;
        }
    }

    // --------------------------------------------------
    // SELECT / OK
    // --------------------------------------------------

    if (select) {
        SelPress = true;
        AnyKeyPress = true;
    }

END:

    // --------------------------------------------------
    // Debounce + wait until buttons released
    // --------------------------------------------------

void InputHandler(void) {

    checkPowerSaveTime();

    // --------------------------------------------------
    // Clear previous button states
    // --------------------------------------------------
    PrevPress = false;
    NextPress = false;
    UpPress = false;
    DownPress = false;
    SelPress = false;
    EscPress = false;
    AnyKeyPress = false;

    // --------------------------------------------------
    // Read physical buttons
    // Button -> GPIO -> GND
    // --------------------------------------------------
    bool up     = digitalRead(BTN_UP) == LOW;
    bool down   = digitalRead(BTN_DOWN) == LOW;
    bool left   = digitalRead(BTN_LEFT) == LOW;
    bool right  = digitalRead(BTN_RIGHT) == LOW;
    bool select = digitalRead(BTN_SELECT) == LOW;

    bool anyButton =
        up ||
        down ||
        left ||
        right ||
        select;

    // --------------------------------------------------
    // Wake screen / reset power-save timer
    // --------------------------------------------------
    if (anyButton) {

        if (!wakeUpScreen()) {
            AnyKeyPress = true;
        } else {
            goto END;
        }
    }

    // --------------------------------------------------
    // 5-way navigation
    //
    // UP     = UpPress
    // DOWN   = DownPress
    // LEFT   = PrevPress
    // RIGHT  = NextPress
    // SELECT = SelPress
    // --------------------------------------------------

    if (up) {
        UpPress = true;
        AnyKeyPress = true;
    }

    if (down) {
        DownPress = true;
        AnyKeyPress = true;
    }

    if (left) {
        PrevPress = true;
        AnyKeyPress = true;
    }

    if (right) {
        NextPress = true;
        AnyKeyPress = true;
    }

    if (select) {
        SelPress = true;
        AnyKeyPress = true;
    }

END:

    // --------------------------------------------------
    // Debounce + wait until button released
    // --------------------------------------------------
    if (AnyKeyPress) {

        delay(DEBOUNCE_TIME);

        unsigned long start = millis();

        while (
            digitalRead(BTN_UP) == LOW ||
            digitalRead(BTN_DOWN) == LOW ||
            digitalRead(BTN_LEFT) == LOW ||
            digitalRead(BTN_RIGHT) == LOW ||
            digitalRead(BTN_SELECT) == LOW
        ) {
            delay(5);

            // Safety timeout
            if (millis() - start > 1000) {
                break;
            }
        }
    }
}

// ======================================================
// KEYBOARD
// ======================================================

String keyboard(String mytext, int maxSize, String msg) {
    return mytext;
}

// ======================================================
// POWER
// ======================================================

void powerOff() {}

void checkReboot() {}

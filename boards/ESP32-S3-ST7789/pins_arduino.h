#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "soc/soc_caps.h"
#include <stdint.h>

// ======================================================
// ESP32-S3 USB / SERIAL
// ======================================================

#define USB_VID 0x303A
#define USB_PID 0x1001

static const uint8_t TX = 43;
static const uint8_t RX = 44;

static const uint8_t TXD2 = 1;
static const uint8_t RXD2 = 2;

// ======================================================
// I2C
// ======================================================

static const uint8_t SDA = 18;
static const uint8_t SCL = 8;

#define GROVE_SDA 18
#define GROVE_SCL 8

// Bruce BadUSB serial pins
#define BAD_TX GROVE_SDA
#define BAD_RX GROVE_SCL

// ======================================================
// MAIN SPI BUS
// Display + SD + CC1101 + NRF24
// ======================================================

static const uint8_t SS   = 11;
static const uint8_t MOSI = 6;
static const uint8_t MISO = 41;
static const uint8_t SCK  = 5;

#define SPI_SCK_PIN  5
#define SPI_MOSI_PIN 6
#define SPI_MISO_PIN 41
#define SPI_SS_PIN   11

// ======================================================
// GPIO ALIASES
// ======================================================

static const uint8_t G0  = 0;
static const uint8_t G1  = 1;
static const uint8_t G2  = 2;
static const uint8_t G3  = 3;
static const uint8_t G4  = 4;
static const uint8_t G5  = 5;
static const uint8_t G6  = 6;
static const uint8_t G7  = 7;
static const uint8_t G8  = 8;
static const uint8_t G9  = 9;
static const uint8_t G10 = 10;
static const uint8_t G11 = 11;
static const uint8_t G12 = 12;
static const uint8_t G13 = 13;
static const uint8_t G14 = 14;
static const uint8_t G15 = 15;
static const uint8_t G16 = 16;
static const uint8_t G17 = 17;
static const uint8_t G18 = 18;

static const uint8_t G21 = 21;

static const uint8_t G40 = 40;
static const uint8_t G41 = 41;
static const uint8_t G42 = 42;
static const uint8_t G43 = 43;
static const uint8_t G44 = 44;
static const uint8_t G47 = 47;
static const uint8_t G48 = 48;

// ======================================================
// DISPLAY - ST7789 240x240
// ======================================================

#define USE_HSPI_PORT
#define HAS_SCREEN 1

#define USER_SETUP_LOADED 1
#define ST7789_DRIVER

#define TFT_WIDTH  240
#define TFT_HEIGHT 240

#define TFT_CS   16
#define TFT_DC   7
#define TFT_RST  15

#define TFT_MOSI 6
#define TFT_SCLK 5
#define TFT_MISO 41

#define TFT_BL 4
#define TFT_BACKLIGHT_ON HIGH

#define TFT_RGB_ORDER TFT_RGB

#define SMOOTH_FONT 1

#define SPI_FREQUENCY      27000000
#define SPI_READ_FREQUENCY 16000000

#define ROTATION 1
#define MINBRIGHT 1

#define FP 1
#define FM 2
#define FG 3

// ======================================================
// 5 PUSH BUTTONS
// Button -> GPIO -> GND
// ======================================================

#define BTN_UP     12
#define BTN_DOWN   13
#define BTN_LEFT   17
#define BTN_RIGHT  9
#define BTN_SELECT 14

#define HAS_BTN 1
#define BTN_ALIAS "\"OK\""
#define BTN_PIN BTN_SELECT
#define BTN_ACT LOW

// ======================================================
// SD CARD
// ======================================================

#define SDCARD_CS   40
#define SDCARD_SCK  5
#define SDCARD_MISO 41
#define SDCARD_MOSI 6

// ======================================================
// CC1101
// Shares SPI bus
// ======================================================

#define CC1101_GDO0_PIN 21
#define CC1101_SS_PIN   47

#define CC1101_MOSI_PIN SPI_MOSI_PIN
#define CC1101_SCK_PIN  SPI_SCK_PIN
#define CC1101_MISO_PIN SPI_MISO_PIN

// ======================================================
// NRF24L01
// Shares SPI bus
// ======================================================

#define NRF24_CE_PIN 3
#define NRF24_SS_PIN 42

#define NRF24_MOSI_PIN SPI_MOSI_PIN
#define NRF24_SCK_PIN  SPI_SCK_PIN
#define NRF24_MISO_PIN SPI_MISO_PIN

// ======================================================
// IR
// ======================================================

#define IR_TX_PINS '{{"IR TX", 1}}'
#define IR_RX_PINS '{{"IR RX", 2}}'

#define TXLED 48
#define LED_ON HIGH
#define LED_OFF LOW

// ======================================================
// BATTERY
// ======================================================

#define BAT_PIN 10

#endif

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"

// I2C LCD 설정
#define I2C_PORT    i2c0
#define I2C_SDA_PIN 0
#define I2C_SCL_PIN 1
#define LCD_ADDR    0x27  // I2C 주소 (0x3F인 경우도 있음)

// PCF8574 → HD44780 비트 매핑
#define LCD_RS  0x01
#define LCD_EN  0x04
#define LCD_BL  0x08  // 백라이트
// D4~D7 = 비트 4~7

static void lcd_i2c_write(uint8_t data) {
    i2c_write_blocking(I2C_PORT, LCD_ADDR, &data, 1, false);
}

static void lcd_pulse_enable(uint8_t data) {
    lcd_i2c_write(data | LCD_EN);
    sleep_us(1);
    lcd_i2c_write(data & ~LCD_EN);
    sleep_us(50);
}

static void lcd_write_nibble(uint8_t nibble, uint8_t flags) {
    uint8_t data = (nibble << 4) | flags | LCD_BL;
    lcd_pulse_enable(data);
}

static void lcd_command(uint8_t cmd) {
    lcd_write_nibble(cmd >> 4, 0);
    lcd_write_nibble(cmd & 0x0F, 0);
    if (cmd <= 0x03) sleep_ms(2);
}

static void lcd_data(uint8_t ch) {
    lcd_write_nibble(ch >> 4, LCD_RS);
    lcd_write_nibble(ch & 0x0F, LCD_RS);
}

void lcd_init() {
    sleep_ms(50);
    lcd_write_nibble(0x03, 0); sleep_ms(5);
    lcd_write_nibble(0x03, 0); sleep_us(150);
    lcd_write_nibble(0x03, 0); sleep_us(150);
    lcd_write_nibble(0x02, 0);  // 4비트 모드 진입

    lcd_command(0x28);  // 2행 / 5x8 폰트 / 4비트
    lcd_command(0x0C);  // 디스플레이 ON, 커서 OFF
    lcd_command(0x06);  // 자동 증가
    lcd_command(0x01);  // 화면 지우기
    sleep_ms(2);
}

void lcd_set_cursor(uint8_t col, uint8_t row) {
    uint8_t row_offsets[] = {0x00, 0x40};
    lcd_command(0x80 | (col + row_offsets[row]));
}

void lcd_print(const char *str) {
    while (*str) lcd_data((uint8_t)*str++);
}

void lcd_clear() {
    lcd_command(0x01);
    sleep_ms(2);
}

int main() {
    stdio_init_all();

    // I2C 초기화 (100kHz)
    i2c_init(I2C_PORT, 100 * 1000);
    gpio_set_function(I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA_PIN);
    gpio_pull_up(I2C_SCL_PIN);

    lcd_init();

    lcd_set_cursor(0, 0);
    lcd_print("  Hello, Pico!  ");
    lcd_set_cursor(0, 1);
    lcd_print("  LCD Ready!    ");

    while (true) {
        sleep_ms(1000);
    }
}

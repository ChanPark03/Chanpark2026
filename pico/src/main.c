#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

// 핀 정의 (회로도 기준)
const uint TRIG_PIN = 4;
const uint ECHO_PIN = 5;

// 거리 측정 함수 (마이크로초 단위 계산)
float get_distance() {
    // 1. Trig 핀으로 10us 동안 신호 발사
    gpio_put(TRIG_PIN, 1);
    sleep_us(10);
    gpio_put(TRIG_PIN, 0);

    // 2. Echo 핀이 High가 될 때까지 대기
    while (gpio_get(ECHO_PIN) == 0) tight_loop_contents();
    absolute_time_t start_time = get_absolute_time();

    // 3. Echo 핀이 Low가 될 때까지 대기
    while (gpio_get(ECHO_PIN) == 1) tight_loop_contents();
    absolute_time_t end_time = get_absolute_time();

    // 4. 시간 차이 계산 (us)
    uint64_t diff = absolute_time_diff_us(start_time, end_time);

    // 5. 거리 계산 (음속 343m/s 기준: 시간 * 0.0343 / 2)
    return (diff * 0.0343f) / 2.0f;
}

int main() {
    stdio_init_all();

    // GPIO 초기화
    gpio_init(TRIG_PIN);
    gpio_set_dir(TRIG_PIN, GPIO_OUT);
    gpio_init(ECHO_PIN);
    gpio_set_dir(ECHO_PIN, GPIO_IN);

    printf("FitPico 센서부 시작!\n");

    while (true) {
        float dist = get_distance();
        printf("현재 거리: %.2f cm\n", dist);

        // 푸쉬업 로직 예시 (임계값 15cm)
        if (dist < 15.0f) {
            printf("--- 푸쉬업 감지! ---\n");
        }

        sleep_ms(500); // 0.5초마다 측정
    }
}
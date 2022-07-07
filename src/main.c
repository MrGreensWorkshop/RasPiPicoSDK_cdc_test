#include "main.h"

int main() {

    stdio_init_all();

    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    absolute_time_t lastSampleTime = get_absolute_time();
    bool toggle = false;
    int chr = 0;
    while (1) {
        absolute_time_t nextSampleTime = delayed_by_us(lastSampleTime, 500000);//500ms
        while (get_absolute_time() < nextSampleTime)
        {
            // Busy Wait.
        }
        lastSampleTime = nextSampleTime;

        gpio_put(LED_PIN, toggle);
        toggle = !toggle;
        printf("pico\n");

        chr = getchar_timeout_us(0);
        if (chr != PICO_ERROR_TIMEOUT) {
            printf("pico rcv: %c\n", chr);
        }
    }
}
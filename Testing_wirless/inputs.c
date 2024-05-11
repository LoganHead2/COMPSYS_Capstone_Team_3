#include "inputs.h"

#define TARE_BUTTON 7
#define LED_1 15
#define LED_2 13

void initPins() {
    gpio_init(TARE_BUTTON); // TARE BUTTON
    gpio_set_dir(TARE_BUTTON, GPIO_IN); // TARE BUTTON WHEN PRESSED IS LOW
    gpio_pull_up(TARE_BUTTON);
    gpio_init(LED_2); // LED 2
    gpio_set_dir(LED_2, GPIO_OUT);
    gpio_init(LED_1); // LED 1
    gpio_set_dir(LED_1, GPIO_OUT);
}

bool checkTare() {

    if (!gpio_get(TARE_BUTTON)) {
        return true;
    } else {
        return false;
    }

}
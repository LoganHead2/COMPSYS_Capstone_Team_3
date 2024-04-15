#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

char ssid[] = "Kay and Winter";
char pass[] = "yucazohote";

int main() {
    stdio_init_all();
    if (cyw43_arch_init_with_country(CYW43_COUNTRY_UK)) {
        printf("failed to initialise\n");
        return 1;
    }
    printf("initialised\n");
    cyw43_arch_enable_sta_mode();

    while (true) {
        if (cyw43_arch_wifi_connect_timeout_ms(ssid, pass, CYW43_AUTH_WPA2_AES_PSK, 10000)) {
            printf("failed to connect\n");
        } else {
            printf("connected\n");
        }
        sleep_ms(10000); // Retry every 10 seconds or perform other tasks
    }
}
/*
 * Copyright (c) 2023 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
// "worldtimeapi.org""capstoneapi.danielmartinez.co.nz"
#define TLS_CLIENT_SERVER        "capstoneapi.danielmartinez.co.nz"
#define TLS_CLIENT_HTTP_REQUEST  "POST /api/data HTTP/1.1\r\n" \
                                 "Host: " TLS_CLIENT_SERVER "\r\n" \
                                 "Content-Type: application/json\r\n" \
                                 "Content-Length: %d\r\n" \
                                 "Connection: close\r\n" \
                                 "\r\n" \
                                 "%s"

#define TLS_CLIENT_TIMEOUT_SECS  15

extern bool run_tls_client_test(const uint8_t *cert, size_t cert_len, const char *server, const char *request, int timeout);

void send_http_post_request(const char* json_data){

    int content_length = strlen(json_data);
    // Prepare the request buffer
    char http_request[1024];  // Ensure this buffer is large enough for your request
    snprintf(http_request, sizeof(http_request), TLS_CLIENT_HTTP_REQUEST, content_length, json_data);

    bool pass = run_tls_client_test(NULL, 0, TLS_CLIENT_SERVER, http_request, TLS_CLIENT_TIMEOUT_SECS);
    if (pass) {
        printf("Test passed\n");
        
    } else {
        printf("Test failed\n");
    }

}


int main() {
    
    stdio_init_all();

    if (cyw43_arch_init()) {
        printf("failed to initialise\n");
        return 1;
    }
    cyw43_arch_enable_sta_mode();

    
    if (cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASSWORD, CYW43_AUTH_WPA2_AES_PSK, 30000)) {
        printf("failed to connect\n");
        return 1;
    }
    // bool pass = run_tls_client_test(NULL, 0, TLS_CLIENT_SERVER, TLS_CLIENT_HTTP_REQUEST, TLS_CLIENT_TIMEOUT_SECS);
    // if (pass) {
    //     printf("Test passed\n");
        send_http_post_request("{\"ScaleID\": 8888, \"Weight\": 999}");
    // } else {
    //     printf("Test failed\n");
    // }
    /* sleep a bit to let usb stdio write out any buffer to host */
    sleep_ms(100);

    cyw43_arch_deinit();
    printf("All done\n");
    return 0;
    
}


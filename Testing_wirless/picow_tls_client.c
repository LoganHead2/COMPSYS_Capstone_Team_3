/*
 * Copyright (c) 2023 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "includes.h"
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


// Variables
enum state STATE = IDLE;
double weight = 0.0;
double tare = 0.0;
double displayWeight;


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


void main() {

    stdio_init_all();
    initPins();
    tare = adcConvert();
    while(1) {

        // Switch statement to enable state machine function
        switch (STATE) {
        case IDLE:
            
            // Check wifi connection if connected do nothing, if not connected attempt to find a connection
           stdio_init_all();

            if (cyw43_arch_init()) {
                printf("failed to initialise\n");
                
            }
            cyw43_arch_enable_sta_mode();


            if (cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASSWORD, CYW43_AUTH_WPA2_AES_PSK, 30000)) {
                printf("failed to connect\n");
                
            }

            send_http_post_request("{\"ScaleID\": 8888, \"Weight\": 999}");

            sleep_ms(100);

            cyw43_arch_deinit();
            printf("All done\n");

        break;
        case SLEEP:
            // Deactivates wifi
            // disconnectWifi(); // NOT EXIST

            // // Check for inputs from scale, if true move to WEIGH state
            // if (checkWeight() == 1) { // NOT EXIST
            //     // Reset tare when waking
            //     tare = 0.0;
            //     STATE = WEIGH;
            // }
            // // Check for inputs from tare button, if true move to TARE state
           

        break;
        case TARE:
            // Set current weight to be zero
            tare = weight;
            // Move to IDLE state
            STATE = IDLE;

        break;
        case WEIGH:
            // Activate ADC
            weight = adcControl();
            
            if (checkTare() == true) { 
                STATE = TARE;
            }

            displayWeight = weight - tare;

            printf("voltage: %f V\n", displayWeight);
            sleep_ms(500);
            // if (displayWeight > 0) {
            //     STATE = SEND;
            // }

            // Move to SEND state? (If they want to tare how long do they need to do that before it sends)
            // Check for inputs from tare button, if true move to TARE state
            // If weight is removed, move to IDLE state

        break;
        case SEND:
            // The weight is sent to the backend via HTTPS
            // Move to the WEIGH state

        break;
        default:
        break;
        }
    }
}


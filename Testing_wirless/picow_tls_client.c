/*
 * Copyright (c) 2023 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "includes.h"


// Variables
enum state STATE = IDLE;
double weight = 0.0;
double tare = 0.0;
double displayWeight;




void main() {

    stdio_init_all();
    initPins();
    tare = adcConvert();
    while(1) {

        // Switch statement to enable state machine function
        switch (STATE) {
        case IDLE:
            
            // Check wifi connection if connected do nothing, if not connected attempt to find a connection
        //    stdio_init_all();
        //    cyw43_arch_init();

        //     if (cyw43_arch_init()) {
        //         printf("failed to initialise\n");
                
        //     }
        //     cyw43_arch_enable_sta_mode();


        //     if (cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASSWORD, CYW43_AUTH_WPA2_AES_PSK, 30000)) {
        //         printf("failed to connect\n");
                
        //     }

        //     send_http_post_request("{\"ScaleID\": 8888, \"Weight\": 999}");

        //     sleep_ms(100);

        //     // cyw43_arch_deinit();
        //     printf("All done\n");

        //     STATE = SLEEP;
        break;
        case SLEEP:

        // Tbh if its only for disconnect Wifi then we probally not need this state 
            // Deactivates wifi
            // NOT EXIST
            // cyw43_arch_deinit();
            
            
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
            stdio_init_all();
            cyw43_arch_init();

            if (cyw43_arch_init()) {
                printf("failed to initialise\n");
                
            }
            cyw43_arch_enable_sta_mode();


            if (cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASSWORD, CYW43_AUTH_WPA2_AES_PSK, 30000)) {
                printf("failed to connect\n");
                
            }

            send_http_post_request("{\"ScaleID\": 8888, \"Weight\": 999}");

            sleep_ms(100);

            cyw43_arch_deinit(); // i believe this dia=sable wifi modual 
            printf("All done\n");


        break;
        default:
        break;
        }
    }
}


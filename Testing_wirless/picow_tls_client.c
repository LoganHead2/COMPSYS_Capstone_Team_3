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
            
            printf("IDLE\n");

            connect_to_wifi();
            printf("test\n");
            // send_http_post_request("{\"ScaleID\": 8888, \"Weight\": 999}");
            send_http_post_request("{\"value\": 999}");
            // send_http_post_request("{value: 999}");

            sleep_ms(100);

            
            printf("All done\n");

            STATE = SLEEP;
        break;
        case SLEEP:

        
            // Deactivates wifi
            // NOT EXIST
            disconnect_to_wifi();
            
            STATE = IDLE;  // for testing wifi reconnect 

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
            
            send_http_post_request("{\"value\": 999}");
            sleep_ms(100);

            
        break;
        default:
        break;
        }
    }
}


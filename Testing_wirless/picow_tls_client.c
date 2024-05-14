/*
 * Copyright (c) 2023 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "includes.h"


// Variables
enum state STATE = WEIGH;
double weight = 0.0;
double tare = 0.0;
double displayWeight;
double displayWeights[20];
int index = 0; 



void main() {

    stdio_init_all();
    initPins();
    tare = adcConvert(); // adc already active??
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

            // STATE = SLEEP; // for wifi testing
        break;
        case SLEEP:

        
            // Deactivates wifi
            // NOT EXIST
            disconnect_to_wifi();
            
            // STATE = IDLE;  // for testing wifi reconnect 
            // maby be disabale adc ??

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
            STATE = WEIGH;

        break;
        case WEIGH:
            // Activate ADC
            weight = adcControl();
            
            if (checkTare() == true) { 
                STATE = TARE;
            }

            index = index + 1;
            displayWeights[index] = (weight - tare)/0.1642;
            if (index == 20) {
                if (adcMinMax() == 1) {
                    displayWeight = adcAverage();
                }else {
                    displayWeight = 0;
                }
                index = 0;
            }
        
            printf("tare: %f \n", tare);
            printf("original weight: %f V \n", weight);
            printf("voltage: %f V\n", (weight - tare));
            printf("weight: %f \n", displayWeights[index]);

            if (displayWeight != 0) {
                printf("Final weight: %f \n", displayWeight);
                //STATE = SEND; 
            }

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

bool adcMinMax() {
    double max = INT_MIN;
    double min = INT_MAX; 

    for (int i = 0; i < 20; i++) {
        if (displayWeights[i] > max) {
            max = displayWeights[i];
        }
        if (displayWeights[i] < min) {
            min = displayWeights[i];
        }
    }

    if (max - min <= average_weight) {
        return true;
    } else {
        return false; 
    }
}

double adcAverage() {
    double average;
    double sum = 0;

    for (int i = 0; i < 20; i++) {
        sum += displayWeights[i];
    }

    average = sum / 20;

    return average;

}
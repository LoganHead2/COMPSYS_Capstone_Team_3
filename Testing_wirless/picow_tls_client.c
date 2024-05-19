/*
 * Copyright (c) 2023 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "includes.h"


// Variables
enum state STATE = IDLE;
double weight = 0.0;
double tare = 0.27;
double displayWeight;
double displayWeight_cmp;
double displayWeights[20];
int ind = 0; 
bool sendReady = 0;
char json_data[50];

double sleepWeight = 0.0;
int sleepCount = 0;
double sleepVar = 0.1;
int sleepTimer = 240;
double static_weight = 0.0;

bool disconnected = false;
double sleepAdc = 0.0;

bool dipalyWeightMinMax() {
    double max = INT_MIN;
    double min = INT_MAX; 

    for (int i = 0; i < 5; i++) {
        if (displayWeights[i] > max) {
            max = displayWeights[i];
        }
        if (displayWeights[i] < min) {
            min = displayWeights[i];
        }
    }

    printf("max-min: %f \n", (min - max));
    printf("average_weight: %f \n", average_weight);
    if (max - min <= average_weight) {
        return true;
    } else {
        return false; 
    }
}

double dipalyWeightAverage() {
    double average;
    double sum = 0;

    for (int i = 0; i < 5; i++) {
        sum += displayWeights[i];
    }

    average = sum / 5;

    return average;

}

void main() {

    stdio_init_all();
    initPins();
    
    while(1) {

        // Switch statement to enable state machine function
        switch (STATE) {
        case IDLE:
            gpio_put(LED_1, true);             
            gpio_put(LED_2, true); 
            sleep_ms(500);
            gpio_put(LED_1, false); 
            gpio_put(LED_2, false); 
            // Check wifi connection if connected do nothing, if not connected attempt to find a connection
            
            // printf("IDLE\n");
            printf("IDLE\n");
            connect_to_wifi();
            
            // send_http_post_request("{\"ScaleID\": 8888, \"Weight\": 999}");
            // send_http_post_request("{\"value\": 999}");
            // send_http_post_request("{value: 999}");
            //tare = adcConvert(); // adc already active??
            // sleep_ms(100);

            tare = 0.27;
            

            STATE = WEIGH; // for wifi testing
        break;
        case SLEEP:

        
            // Deactivates wifi
            // NOT EXIST
            if (disconnected == false){
                disconnect_to_wifi();
                disconnected = true;
            }
            
            sleepAdc = adcConvert();
            // STATE = IDLE;  // for testing wifi reconnect 
            // maby be disabale adc ??
            printf("SleepADC: %f", sleepAdc);
            printf("static_weight: %f", static_weight);
            if ((sleepAdc > (static_weight + 0.016)) || (sleepAdc < (static_weight - 0.016))){
                disconnected = false;
                STATE = IDLE;
            }
            // // Check for inputs from scale, if true move to WEIGH state
            // if (checkWeight() == 1) { // NOT EXIST
            //     // Reset tare when waking
            //     tare = 0.0;
            //     STATE = WEIGH;
            // }
            // // Check for inputs from tare button, if true move to TARE state
           printf("WE'RE SLEEPING\n");
           sleep_ms(500);

        break;
        case TARE:
            // Set current weight to be zeros
            tare = weight;
            sleep_ms(300);
            gpio_put(LED_2, false); 
            // Move to IDLE state
            STATE = WEIGH;

        break;
        case WEIGH:
            // Activate ADC
            weight = adcControl();
            
            if (checkTare() == true) { 
                STATE = TARE;
            }

            // displayWeight_cmp = (weight - tare)/0.1642;// to compare
            
           
            displayWeights[ind] = (weight - tare)/0.1642;
            
           
            
            if (ind == 4) {
                // if (dipalyWeightMinMax() == 1) {
                    displayWeight = displayWeights[ind];
                // }else {
                    // displayWeight = 0;
                // }
                
                ind = 0;
            }

            ind = ind + 1;
        
            printf("tare: %f \n", tare);
            printf("original voltage: %f V \n", weight);
            printf("voltage: %f V\n", (weight - tare));
            // printf("cmp_weight: %f \n", displayWeight_cmp);
            printf("weight: %f \n", displayWeight);

            if (displayWeight >= 0.1 && sendReady == 0) {
                sendReady = 1;
                displayWeight = 0;

            } else if (displayWeight >= 0.1 && sendReady == 1) {
                printf("Final weight: %f \n", displayWeight);
                sendReady = 0;
                STATE = SEND; 
            }


            if (displayWeights[ind] > sleepWeight + sleepVar || displayWeights[ind] < sleepWeight - sleepVar) {
                sleepWeight = displayWeights[ind];
                sleepCount = 0;

            } else if (sleepCount == sleepTimer) {
                sleepCount = 0;
                static_weight = weight;
                STATE = SLEEP;

            } else {
                sleepCount += 1;
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
            
            printf("SEND weight: %f \n", displayWeight);
            snprintf(json_data, sizeof(json_data), "{\"value\": %f}", displayWeight);
            send_http_post_request(json_data);
            gpio_put(LED_1, true); 
            // send_http_post_request("{\"value\": 999}");
            sleep_ms(1000);
            gpio_put(LED_1, false); 
            displayWeight = 0;
            

            STATE = WEIGH;
        break;
        default:
        break;
        }
    }
}


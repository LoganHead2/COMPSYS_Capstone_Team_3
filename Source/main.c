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
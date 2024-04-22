#include "includes.h"

// Variables
enum state STATE = IDLE;
float weight = 0.0;

void main() {

    stdio_init_all();

    while(1) {

        // Switch statement to enable state machine function
        switch (STATE) {
        case IDLE:
            // Check wifi connection if connected do nothing, if not connected attempt to find a connection
            // Check for inputs from scale, if true move to WEIGH state
            // Check for inputs from tare button, if true move to TARE state
            
            break;

        case SLEEP:
            // Deactivates wifi
            // Check for inputs from scale, if true move to IDLE state
            // Check for inputs from buttons, if true move to IDLE state

            break;

        case TARE:
            // Set current weight to be zero
            // Move to IDLE state

            break;

        case WEIGH:
            // Activate ADC
            // Wait for weight to stabalise
            // Calculate the ADC value
            // Move to SEND state? (If they want to tare how long do they need to do that before it sends)
            // Check for inputs from tare button, if true move to TARE state
            // If weight is removed, move to IDLE state

            break;

        case SEND:
            // The weight is sent to the backend via HTTPS
            // Move to the IDLE state

            break;
        
        default:
            break;
        }
    }
}
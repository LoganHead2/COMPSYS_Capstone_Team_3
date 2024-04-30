#include "adc.h"


// ADC.C
// For all ADC functions
// Includes can be found in adc.h

// User ADC inputs are on 0-3 (GPIO 26-29)
/*
If we want to use interrupts we have this
static void adc_irq_set_enabled (bool enabled)
This enables adc interrupts, we'll prob just use polling
*/

double adcWeights[50];
int position = 0;

uint16_t adcConvert() {

    // Initialise the ADC HW
    adc_init();

    // Initialise the gpio for use as an ADC pin
    // Make sure GPIO is high-impedance, no pullups etc
    adc_gpio_init(26);

    // ADC input select.
    // Select ADC input 0 (GPIO26)
    adc_select_input(0);

    // Assumes VREF == 3.3V
    const float conversion_factor = 3.3f / (1 << 12);
    // Perform a single conversion.
    uint16_t result = adc_read();
    printf("Raw value: 0x%03x, voltage: %f V\n", result, result * conversion_factor);

    return result;

} 


double adcControl() {
    position = position + 1;

    adcWeights[position] = (double) adcConvert();

    if (position == 50) {
        position = 0;
    }

    // displayWeight = weight - tare;
    // // Display weight
    // showWeight(); // NOT EXIST

    if (adcMinMax() == 1) {
        return adcAverage();
    } else {
        return 0;
    }

}

bool adcMinMax() {
    double max = INT_MIN;
    double min = INT_MAX; 

    for (int i = 0; i < 50; i++) {
        if (adcWeights[i] > max) {
            max = adcWeights[i];
        }
        if (adcWeights[i] < min) {
            min = adcWeights[i];
        }
    }

    if (max - min <= varible_weight) {
        return true;
    } else {
        return false; 
    }
}

double adcAverage() {
    double average;
    double sum = 0;

    for (int i = 0; i < 50; i++) {
        sum += adcWeights[i];
    }

    average = sum / 50;

    return average;

}
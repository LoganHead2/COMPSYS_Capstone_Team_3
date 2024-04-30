#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "constants.h"
#include "inputs.h"
#include "stdbool.h"
#include "limits.h"

uint16_t adcConvert();
double adcControl();
bool adcMinMax();
double adcAverage();
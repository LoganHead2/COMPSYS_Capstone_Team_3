#include <stdio.h>
#include <cstdint>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

uint16_t adcConvert();
void adcControl();
void adcAverage();
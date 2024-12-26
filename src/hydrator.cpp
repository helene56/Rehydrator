// purpose of this is to read from the Capaltive Soil Moisture Sensor
#include "hardware/adc.h"

double read_moisture() 
{
    constexpr double conversion_factor {3.3f / (1 << 12)}; // Convert to voltage
    uint16_t result = adc_read(); // Read raw sensor value from ADC0
    // return the voltage
    return result * conversion_factor;
}
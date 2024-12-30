// purpose of this is to read from the Capaltive Soil Moisture Sensor
#include "hardware/adc.h"
#include <stdio.h>

namespace moisture
{
    constexpr double DRY {2.00f};
    constexpr uint sensor {26}; // ADC0 attached

} // namespace moisture


void initialize_moisture_sensor()
{
    adc_init(); //initiliaze adc module
    adc_gpio_init(moisture::sensor);
    adc_select_input(0); // selects ADC0 as the input
}

double read_moisture()
{
    constexpr double conversion_factor {3.3f / (1 << 12)}; // Convert to voltage
    uint16_t result {adc_read()};                          // Read raw sensor value from ADC0
    // return the voltage
    printf("result voltage: %f\n", result * conversion_factor);
    return result * conversion_factor;
}


bool test_moisture()
{
    initialize_moisture_sensor();
    return (read_moisture() > moisture::DRY);
}
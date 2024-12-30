#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>
// pio program
#include "build/rgbLed.pio.h"
// user lib
#include "rgbLed.h"
#include "hydrator.h"

int main()
{
    stdio_init_all();

    constexpr uint rgb_din {16};

    PIO pio     = pio0;
    int sm      = 0;
    uint offset = pio_add_program(pio, &rgbLed_program);
    rgbLed_program_init(pio, sm, offset, rgb_din, 800000);
    
    bool lit {false};
    constexpr uint led {1};
    gpio_init(led);
    gpio_set_dir(led, GPIO_OUT);
    while (true)
    {
        // printf("Hello, world!\n");
        // gpio_put(led, 1);
        // sleep_ms(1000);
        // gpio_put(led, 0);
        // sleep_ms(1000);

        if (test_moisture())
        {
            put_pixel((0b0 << 16) | (0b0 << 8) | 0b10000000);
            sleep_ms(200);
            put_pixel((0b0 << 16) | (0b0 << 8) | 0b0);
            sleep_ms(200);
            lit = false;
        }
        else if (!lit)
        {
            put_pixel((0b0 << 16) | (0b0 << 8) | 0b10000000);
            lit = true;
        }
    }
}

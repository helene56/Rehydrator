#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>
// pio program
#include "build/rgbLed.pio.h"

#include "rgbLed.h"

int main()
{
    stdio_init_all();

    uint const rgb_din {16};

    PIO pio     = pio0;
    int sm      = 0;
    uint offset = pio_add_program(pio, &rgbLed_program);
    rgbLed_program_init(pio, sm, offset, rgb_din, 800000);

    put_pixel((0b0 << 16) | (0b0 << 8) | 0b11111111);

    uint const led {1};
    gpio_init(led);
    gpio_set_dir(led, GPIO_OUT);
    while (true)
    {
        printf("Hello, world!\n");
        gpio_put(led, 1);
        sleep_ms(1000);
        gpio_put(led, 0);
        sleep_ms(1000);
    }
}

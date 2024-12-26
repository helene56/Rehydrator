#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <stdio.h>
// pio program
#include "build/rgbLed.pio.h"

int main()
{
    stdio_init_all();

    uint const rgb_din {16};

    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &rgbLed_program);
    rgbLed_program_init(pio, sm, offset, rgb_din, 800000);

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

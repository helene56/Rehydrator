#include "pico/stdlib.h"
#include <stdio.h>

int main()
{
    stdio_init_all();
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

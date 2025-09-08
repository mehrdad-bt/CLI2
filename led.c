#include "led.h"

void Led_init(Led_t *led)
{
    led->state = LED_OFF;
}

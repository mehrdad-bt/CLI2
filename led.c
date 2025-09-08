#include "led.h"

void Led_init(Led_t *led)
{
    led->state = LED_OFF;
}

void Led_off(Led_t *led)
{
    led->state = LED_OFF;
}

void Led_on(Led_t *led)
{
    led->state = LED_ON;
}


// void Led_toggle(Led_t *led)
// {
//     if(led->state == LED_OFF)
//     {
//         led->state = LED_ON;
//     }
//     else if(led->state = LED_ON)
//     {
//         led->state == LED_OFF;
//     }
// }
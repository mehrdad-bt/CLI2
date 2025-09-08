#pragma once

typedef enum
{
    LED_OFF,
    LED_ON,

}LedState_t;

typedef struct Led_t{

    LedState_t state;
}Led_t;


void Led_init(Led_t*);
void Led_off(Led_t*);
void Led_on(Led_t*);
//void Led_toggle(Led_t*);


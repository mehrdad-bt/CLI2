#include <stdio.h>
#include <string.h>
#include "app.h"
#include "command.h"


void app(char *input){

    Command_t mode;
    Led_t led;
    Led_init(&led);
    Command_init(&mode); 
    
    CommandState_t command = Command_GetState(&mode, input);

    switch(command)
    {

        case C_HELP:
        {
             printf("help mode\n");
        }
        break;


        case C_LED_ON:
        {
            
            
            if(led.state == LED_OFF)
            {
                Led_on(&led);
                printf("Led is on\n");
            }

        }
        break;

        case C_LED_OFF:
        {
            if(led.state == LED_ON)
            {
                Led_off(&led);
                printf("Led is off\n");
            }

        }
        break;


    }

}
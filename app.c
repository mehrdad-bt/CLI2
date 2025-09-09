#include <stdio.h>
#include <string.h>
#include "app.h"
#include "command.h"
#include "uart.h"

void App_init(App_t *app)
{
    
    Led_init(&app->led);
    Uart_init(&app->uart);
    Command_init(&app->command);
}

void App_Process(App_t *app, char *input){


    
     
    
    CommandState_t command = Command_GetState(&app->command, input);

    switch(command)
    {

        case C_HELP:
        {
           
            printf("> led on\nLED ON\n> led off\nLED OFF\n> uart send hello\n5 bytes queued\n> uart status\nTX Count : 5\nRX Count : 0\n> uart tx\nSending : hello\n> uart status\nTX Count : 0\nRX Count : 0\n");
        }
        break;


        case C_LED_ON:
        {
            
            
            if(app->led.state == LED_OFF)
            {
                Led_on(&app->led);
                printf("Led is on\n");
            }
            else
            {
                printf("Led is already on\n");  
            }

        }
        break;

        case C_LED_OFF:
        {
            if(app->led.state == LED_ON)
            {
                Led_off(&app->led);
                printf("Led is off\n");
            }
            else
            {
                printf("Led is already off\n");  
            }

        }
        break;

        case C_UART_SEND:
        {
            
            Uart_Send(&app->uart, app->command.token3);

        }
        break;

        case C_UART_STATUS:
        {
            Uart_Status(&app->uart);

        }
        break;

        case C_UART_TX:
        {
            Uart_Tx(&app->uart);

        }
        break;

    }

}
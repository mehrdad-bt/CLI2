#include <stdio.h>
#include <string.h>
#include "app.h"
#include "command.h"
#include "uart.h"


void app(char *input){

    static int initialized = 0;
    static Led_t led;
    static UART_t uart;


    if(!initialized)
    {
        Led_init(&led);
        Uart_init(&uart);
        initialized = 1;
    }

    Command_t mode;
    
    Command_init(&mode); 
    
    CommandState_t command = Command_GetState(&mode, input);

    switch(command)
    {

        case C_HELP:
        {
           
            printf("> led on\nLED ON\n> led off\nLED OFF\n> uart send hello\n5 bytes queued\n> uart status\nTX Count : 5\nRX Count : 0\n> uart tx\nSending : hello\n> uart status\nTX Count : 0\nRX Count : 0\n");
        }
        break;


        case C_LED_ON:
        {
            
            
            if(led.state == LED_OFF)
            {
                Led_on(&led);
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
            if(led.state == LED_ON)
            {
                Led_off(&led);
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
            
            Uart_Send(&uart, mode.token3);

        }
        break;

        case UART_STATUS:
        {
            Uart_Status(&uart);

        }
        break;

        case UART_TX:
        {
            Uart_Tx(&uart);

        }
        break;

    }

}
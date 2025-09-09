#include <stdio.h>
#include <string.h>
#include "command.h"





void Command_init(Command_t *command)
{
    command->state = C_IDLE;
}

CommandState_t Command_GetState(Command_t *command, char *input)
{


    char token1[20];
    char token2[20];
    

    input = strtok(input, " \n");
    
      while(input != NULL)
            {
            strcpy(token1, input);
            input = strtok(NULL, " \n");
            
            if(input == NULL)
            {
                break;
            }

            strcpy(token2, input);
            input = strtok(NULL, " \n");

            if(input == NULL)
            {
                break;
            }

            strcpy(command->token3, input);
            input = strtok(NULL, " \n");                        
            }
            
        
    /*conditions*/
    if((strcmp(token1, "help") == 0))
    {
        command->state = C_HELP;
    }

    if((strcmp(token1, "led") == 0) && (strcmp(token2, "on") == 0) && (strcmp(command->token3, "") == 0))
    {
        command->state = C_LED_ON;
    }

    if((strcmp(token1, "led") == 0) && (strcmp(token2, "off") == 0) && (strcmp(command->token3, "") == 0))
    {
        
        command->state = C_LED_OFF;
    }

    if((strcmp(token1, "uart") == 0) && (strcmp(token2, "send") == 0))
    {
        command->state = C_UART_SEND;
    }

    if((strcmp(token1, "uart") == 0) && (strcmp(token2, "status") == 0))
    {
         command->state = UART_STATUS;
    }

    if((strcmp(token1, "uart") == 0) && (strcmp(token2, "tx") == 0))
    {
         command->state = UART_TX;
    }


  
    return (command->state);
       
       

}
#include <stdio.h>
#include <string.h>
#include "command.h"




void Command_init(Command_t *command)
{
    command->state = C_IDLE;

}

CommandState_t Command_GetState(Command_t *command, char *input)
{



    CommandTable_t table[] =
    {
    {"led", "on",    C_LED_ON},
    {"led", "off",   C_LED_OFF},
    {"uart", "send", C_UART_SEND},
    {"uart", "status",   C_UART_STATUS},
    {"uart", "tx",   C_UART_TX},
    {"help", "",         C_HELP}

    };

    char *token1;
    char *token2;
    char *token3;
    

    token1 = strtok(input, " \n");
    token2 = strtok(NULL, " \n");
    token3 = strtok(NULL, " \n");
    
    if(token2 == NULL)
    {
        token2 = "";
    }

    if(token3 != NULL)
    {
    strcpy(command->token3, token3);
    }

    else
    {
    command->token3[0] = '\0';
    }
        
    /*conditions*/
    for(int i = 0; i < 6; i++)
    {
        if(strcmp(token1, table[i].cmd1) == 0 && strcmp(token2, table[i].cmd2) == 0)
        {
            return table[i].state;
        }
    }

        
       

}
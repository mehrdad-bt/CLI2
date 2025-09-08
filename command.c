#include <stdio.h>
#include <string.h>
#include "command.h"
#define Command_GetState(input) Command_GetState_Default(NULL, input)

Command_t command;

void Command_init(Command_t *command)
{
    command->state = C_IDLE;
}

Command_t Command_GetState_Default(Command_t *command, char *input)
{

    char *token1, *token2, *token3;

    input = strtok(input, sizeof(input), " \n");
    while(input != NULL)
    {
        strcpy(token1, input);
        
    }

}
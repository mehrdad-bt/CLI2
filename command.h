#pragma once

typedef enum{
    C_IDLE,
    C_UART,
    C_LED,
    C_HELP
}CommandState_t;

typedef struct Command_t{

    CommandState_t state;
}Command_t;

void Command_init(Command_t*);
Command_t Command_GetState_Default(Command_t*, char*);
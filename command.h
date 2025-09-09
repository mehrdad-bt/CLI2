#pragma once

typedef enum{
    C_IDLE,
    C_UART_SEND,
    UART_STATUS,
    UART_TX,
    C_LED_ON,
    C_LED_OFF,
    C_HELP
}CommandState_t;

typedef struct Command_t{

    CommandState_t state;
    char token3[20];
}Command_t;

void Command_init(Command_t*);
CommandState_t Command_GetState(Command_t*, char*);

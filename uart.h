#pragma once

typedef struct UartState_t{

    char Buffer_Rx[8];
    int Head_Tx, Tail_Tx, Count_Tx;
    char Buffer_Tx[8];
    int Head_Rx, Tail_Rx, Count_Rx;

}UartState_t;

typedef struct UART_t{
    UartState_t state;
}UART_t;

void Uart_init(UART_t*);
void Uart_Send(UART_t*, char*);
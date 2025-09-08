#include <stdio.h>
#include <string.h>
#include "uart.h"
#define SIZE 8

void Uart_init(UART_t *uart)
{
    memset(uart->state.Buffer_Rx, 0, sizeof(SIZE));
    memset(uart->state.Buffer_Tx, 0, sizeof(SIZE));
    uart->state.Head_Tx = 0;
    uart->state.Head_Rx = 0;
    uart->state.Tail_Tx = 0;
    uart->state.Tail_Rx = 0;
    uart->state.Count_Tx = 0;
    uart->state.Count_Rx = 0;
}


void Uart_Send(UART_t *uart, char *token3)
{
    printf("inside uart\n");
    for(int i = 0; i < 5 ; i++)
    {

        uart->state.Buffer_Tx[uart->state.Head_Tx] = token3[i];
        uart->state.Head_Tx = (uart->state.Head_Tx + 1) % SIZE ;

        printf("test");

    }
}



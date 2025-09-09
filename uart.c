#include <stdio.h>
#include <string.h>
#include "uart.h"
#define SIZE 8

void Uart_init(UART_t *uart)
{
    memset(uart->state.Buffer_Rx, 0, sizeof(uart->state.Buffer_Rx));
    memset(uart->state.Buffer_Tx, 0, sizeof(uart->state.Buffer_Rx));
    uart->state.Head_Tx = 0;
    uart->state.Head_Rx = 0;
    uart->state.Tail_Tx = 0;
    uart->state.Tail_Rx = 0;
    uart->state.Count_Tx = 0;
    uart->state.Count_Rx = 0;
}


void Uart_Send(UART_t *uart, char *token3)
{
    int len = strlen(token3);
    if(uart->state.Count_Tx > 7)
    {
        printf("TX Buffer is full !\n");
        return;
    }
    for(int i = 0; i < len ; i++)
    {
        if(uart->state.Count_Tx > 7)
        {
        printf("TX Buffer is full !\n");
        return;
        }

        uart->state.Buffer_Tx[uart->state.Head_Tx] = token3[i];
        uart->state.Head_Tx = (uart->state.Head_Tx + 1) % SIZE ;
        uart->state.Count_Tx++;
        
    }
    printf("%d bytes Queued\n", uart->state.Count_Tx);
}

void Uart_Status(UART_t *uart){

    printf("Tx Count : %d\nRx Count : %d\n", uart->state.Count_Tx, uart->state.Count_Rx);
}

void Uart_Tx(UART_t *uart)
{
    int index = uart->state.Tail_Tx;
    int index_count = uart->state.Count_Tx;
    if(uart->state.Count_Tx == 0)
    {
        printf("Nothing in Buffer to send !\n");
        return;
    }
    printf("Sending : ");
    for(int i = 0; i < index_count; i++)
    {
        printf("%c", uart->state.Buffer_Tx[index]);
        uart->state.Tail_Tx = (uart->state.Tail_Tx + 1) % 8;
        index = (index + 1) % 8;
        uart->state.Count_Tx--;
    }
    printf("\n");
}



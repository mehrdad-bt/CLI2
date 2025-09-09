#include "led.h"
#include "uart.h"
#include "command.h"


typedef struct App_t{
    Led_t led;
    UART_t uart;
    Command_t command;
}App_t;

void App_init(App_t*);
void App_Process(App_t*, char*);
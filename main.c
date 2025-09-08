#include <stdio.h>
#include <string.h>
#include "command.h"
#include "app.h"



int main(){
    char input[40];
    while(1)
    {
        fgets(input, sizeof(input), stdin);
        if(strcmp(input, "exit\n") == 0)
            break;
        
        app(input);

    }


    return 0;
}
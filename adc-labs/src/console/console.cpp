#include "console.h"

#include <Arduino.h>

#define CONSOLE_PORT                        Serial
#define CONSOLE_BAUDRATE                    115200

void console_cfg(void)
{
    // Prepare the console port for use
    CONSOLE_PORT.begin((long)CONSOLE_BAUDRATE);
}

void console_action(void)
{
    // Display the "hello world" message
    CONSOLE_PORT.print("Hello World!\r\n"); 
}
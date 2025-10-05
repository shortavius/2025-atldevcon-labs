#include "console.h"

#include <Arduino.h>

#define RTRN_CHAR                           0x0Du
#define CONSOLE_PORT                        Serial
#define CONSOLE_BAUDRATE                    115200


static void display_prompt(void);


void console_cfg(void)
{
    // Prepare the console port for use
    CONSOLE_PORT.begin((long)CONSOLE_BAUDRATE);

    // Display the basic prompt
    display_prompt();
}

void console_action(void)
{
    // Check to see if a character had been sent to the board
    if (0 < CONSOLE_PORT.available())
    {
        // Grab a byte out of the receive buffer
        const uint8_t in_byte = (uint8_t)(0xFF & CONSOLE_PORT.read());

        // Check to see if the character is the return character
        if ((uint8_t)RTRN_CHAR == in_byte)
        {
            CONSOLE_PORT.print("\r\n");
            display_prompt();
        }
    }
}

static void display_prompt(void)
{
    CONSOLE_PORT.print("$ ");
}

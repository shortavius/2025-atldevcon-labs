#include "console.h"
#include "../cmd_process/cmd_process.h"

#include <Arduino.h>

#include <string.h>


#define CHAR_BS                             0x08u
#define CHAR_CR                             0x0Du
#define CONSOLE_PORT                        Serial
#define CONSOLE_BAUDRATE                    115200


// This is used to indicate which position in the string is currently being
// modified.
static uint8_t cmd_byte_pos = 0u;

// This is the command string that we are building up.
static uint8_t cmd_str[CONSOLE_MAX_LINE_SZ + 1] = { 0u };


static void display_prompt(void);
static void display_delete_character(void);


void console_cfg(void)
{
    // Prepare the console port for use
    CONSOLE_PORT.begin((long)CONSOLE_BAUDRATE);
}

void console_action(void)
{
    // Check to see if a character had been sent to the board
    if (0 < CONSOLE_PORT.available())
    {
        // Grab a byte out of the receive buffer
        const uint8_t in_byte = (uint8_t)(0xFF & CONSOLE_PORT.read());

        // Check to see if this is a backspace character
        if ((uint8_t)CHAR_BS == in_byte)
        {
            if ((uint8_t)0 != cmd_byte_pos)
            {
                display_delete_character();
                cmd_byte_pos--;
                cmd_str[cmd_byte_pos] = (uint8_t)0u;
            }
        }
        // Check to see if the character is the return character
        else if ((uint8_t)CHAR_CR == in_byte)
        {
            CONSOLE_PORT.print("\r\n");
            cmd_process_load_cmd(cmd_str, cmd_byte_pos);
            cmd_process_process_cmd();
            CONSOLE_PORT.print("\r\n");
            (void)memset(
                (void *)&cmd_str,
                0x00,
                (sizeof(uint8_t) * CONSOLE_MAX_LINE_SZ));
            cmd_byte_pos = 0u;
            display_prompt();
        }
        // Add the character to the string and echo it back
        else if (((uint8_t)0x1F < in_byte) && ((uint8_t)0x7F > in_byte))
        {
            if ((uint8_t)CONSOLE_MAX_LINE_SZ > cmd_byte_pos)
            {
                cmd_str[cmd_byte_pos] = in_byte;
                cmd_byte_pos++;
                CONSOLE_PORT.print((char)in_byte);
            }
        }
    }
}

void console_display_str_nl(const uint8_t * const str)
{
    CONSOLE_PORT.println((char *)str);
}

static void display_prompt(void)
{
    CONSOLE_PORT.print("$ ");
}

static void display_delete_character(void)
{
    CONSOLE_PORT.print("\b \b");
}

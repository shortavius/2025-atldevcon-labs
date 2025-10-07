#include "cmd_process.h"
#include "../console/console.h"


#include <string.h>
#include <stdlib.h>


// This is a copy of the command string that needs to be processed.
static uint8_t cmd_process_str[CONSOLE_MAX_LINE_SZ] = { 0u };

// This is the length of the command string to be processed.
static uint8_t cmd_process_str_len = 0u;

// This lets this module know if there is work to do.
static bool cmd_process_do_work = false;


static uint8_t skip_spaces(char *idx);


void cmd_process_cfg(void)
{
    (void)memset(
        (void *)cmd_process_str,
        0,
        sizeof(uint8_t) * CONSOLE_MAX_LINE_SZ);
    cmd_process_str_len = 0u;
    cmd_process_do_work = false;
}

void cmd_process_load_cmd(
    const uint8_t * const in_cmd,
    uint8_t cmd_len)
{
    (void)memcpy(
        (void *)cmd_process_str,
        (void *)in_cmd,
        (sizeof(uint8_t) * CONSOLE_MAX_LINE_SZ));
    cmd_process_str_len = cmd_len;
    cmd_process_do_work = true;
}

void cmd_process_process_cmd(void)
{
    // See if there is work to do
    if ((!cmd_process_do_work) ||
        (0u == cmd_process_str_len))
    {
        // No work to do so exit
        return;
    }

        char * cmd_idx = (char *)&cmd_process_str[0];
    cmd_idx += skip_spaces(cmd_idx);

    // Check if the command is help or not
    if ((0 == strncmp(cmd_idx, "help", strlen("help"))) ||
        ((1 == cmd_process_str_len)) && ('?' == *cmd_idx))
    {
        console_display_str_nl((uint8_t *)"Help menu");
        console_display_str_nl((uint8_t *)"Available commands: ");
        console_display_str_nl((uint8_t *)"    help or ? - Display this help message");
    }

    cmd_process_do_work = false;
}

static uint8_t skip_spaces(char *idx)
{
    char *end = idx;

    while (' ' == *end)
    {
        end++;
    }

    return (uint8_t)(end - idx);
}

#include "cmd_hrtbt.h"
#include "cmd_process.h"
#include "../console/console.h"
#include "../hrtbt/hrtbt.h"


#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#define CMD_HRTBT_MAIN_HELP                                                   \
"  hrtbt     - sends commands to the heartbeat module add an <?> after the"   \
"\r\n"                                                                        \
"              command to get more help on the hrtbt command (hrtbt ?)"
#define CMD_HRTBT_HELP                                                        \
"  delay - read or make changes to the heartbeat LED delay value. For \r\n"   \
"          more about the delay command (hrtbt delay ?)"
#define CMD_HRTBT_DELAY_HELP                                                  \
"  get - display the heartbeat LED delay value\r\n"                           \
"  set - update the heartbeat LED delay value"
#define CMD_HRTBT_DELAY_SET_HELP                                              \
"  <int> - this is an integer representing the number of milliseconds to\r\n" \
"          wait before toggling the LED state"


static bool hrtbt_x(char *cmd);
static void hrtbt_help(void);
static bool hrtbt_delay_x(char *cmd);
static void hrtbt_delay_help(void);
static void hrtbt_delay_get(void);
static bool hrtbt_delay_set_x(char *cmd);
static void hrtbt_delay_set_help(void);
static void hrtbt_delay_set_int(char *cmd);


void cmd_hrtbt_main_hlp(void)
{
    console_display_str_nl((uint8_t *)CMD_HRTBT_MAIN_HELP);
}

bool cmd_is_hrtbt(char *cmd)
{
    bool rv = false;

    if (0 == strncmp(cmd, "hrtbt", strlen("hrtbt")))
    {
        cmd += strlen("hrtbt");
        cmd += skip_spaces(cmd);
        rv = hrtbt_x(cmd);
    }

    return rv;
}

static bool hrtbt_x(char *cmd)
{
    bool rv = false;

    if (0 == strncmp(cmd, "?", strlen("?")))
    {
        hrtbt_help();
        rv = true;
    }
    else if (0 == strncmp(cmd, "delay", strlen("delay")))
    {
        cmd += strlen("delay");
        cmd += skip_spaces(cmd);
        rv = hrtbt_delay_x(cmd);
    }

    return rv;
}

static void hrtbt_help(void)
{
    console_display_str_nl((uint8_t *)"");
    console_display_str_nl((uint8_t *)CMD_HRTBT_HELP);
}

static bool hrtbt_delay_x(char *cmd)
{
    bool rv = false;

    if (0 == strncmp(cmd, "?", strlen("?")))
    {
        hrtbt_delay_help();
        rv = true;
    }
    else if (0 == strncmp(cmd, "get", strlen("get")))
    {
        hrtbt_delay_get();
        rv = true;
    }
    else if (0 == strncmp(cmd, "set", strlen("set")))
    {
        cmd += strlen("set");
        cmd += skip_spaces(cmd);
        rv = hrtbt_delay_set_x(cmd);
    }

    return rv;
}

static void hrtbt_delay_help(void)
{
    console_display_str_nl((uint8_t *)"");
    console_display_str_nl((uint8_t *)CMD_HRTBT_DELAY_HELP);
}

static void hrtbt_delay_get(void)
{
    char * buff = console_get_buffer();
    const unsigned int delay = hrtbt_get_delay();

    console_clear_buffer();
    sprintf(buff, "heartbeat LED delay: %d milliseconds", delay);

    console_display_str_nl((uint8_t *)"");
    console_display_str_nl((uint8_t *)buff);
}

static bool hrtbt_delay_set_x(char *cmd)
{
    bool rv = false;

    if (0 == strncmp(cmd, "?", strlen("?")))
    {
        hrtbt_delay_set_help();
        rv = true;
    }
    else
    {
        hrtbt_delay_set_int(cmd);
        rv = true;
    }

    return rv;
}

static void hrtbt_delay_set_help(void)
{
    console_display_str_nl((uint8_t *)"");
    console_display_str_nl((uint8_t *)CMD_HRTBT_DELAY_SET_HELP);
}

static void hrtbt_delay_set_int(char *cmd)
{
    char * buff = console_get_buffer();
    unsigned long val = strtoul(cmd, 0L, 10);

    hrtbt_set_delay((unsigned int)val);
    hrtbt_delay_get();
}

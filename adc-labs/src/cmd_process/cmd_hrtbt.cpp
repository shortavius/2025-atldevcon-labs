#include "cmd_hrtbt.h"
#include "cmd_process.h"
#include "../console/console.h"
#include "../hrtbt/hrtbt.h"


#include <string.h>
#include <stdio.h>


#define CMD_HRTBT_MAIN_HELP                                                   \
"  hrtbt     - sends commands to the heartbeat module add an <?> after the"   \
"\r\n"                                                                        \
"              command to get more help on the hrtbt command (hrtbt ?)"
#define CMD_HRTBT_HELP                                                        \
"  delay - read or make changes to the heartbeat LED delay value. For \r\n"   \
"          more about the delay command (hrtbt delay ?)"


static bool hrtbt_x(char *cmd);
static void hrtbt_help(void);


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

    return rv;
}

static void hrtbt_help(void)
{
    console_display_str_nl((uint8_t *)"");
    console_display_str_nl((uint8_t *)CMD_HRTBT_HELP);
}

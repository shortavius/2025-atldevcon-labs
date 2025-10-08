#if !defined(CMD_PROCESS_H)
#define CMD_PROCESS_H


#include <stdint.h>


void cmd_process_cfg(void);
void cmd_process_load_cmd(
    const uint8_t * const in_cmd,
    uint8_t cmd_len);
void cmd_process_process_cmd(void);
uint8_t skip_spaces(char *idx);
char * console_get_buffer(void);
void console_clear_buffer(void);

#endif /* CMD_PROCESS_H */

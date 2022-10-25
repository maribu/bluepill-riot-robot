#include <stdio.h>
#include "msg.h"

#include "net/gcoap.h"
#include "shell.h"

#include "robot.h"

#define MAIN_QUEUE_SIZE (4)
static msg_t _main_msg_queue[MAIN_QUEUE_SIZE];

int main(void)
{
    msg_init_queue(_main_msg_queue, MAIN_QUEUE_SIZE);
    server_init();
    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(NULL, line_buf, SHELL_DEFAULT_BUFSIZE);
    return 0;
}

#include <stdio.h>
#include <string.h>

#include "shell.h"

int main(void)
{
    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(NULL, line_buf, SHELL_DEFAULT_BUFSIZE);

    return 0;
}

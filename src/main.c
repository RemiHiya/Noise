#include "include/render.h"
#include "include/utils.h"
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    struct winsize win;
    ioctl(0, TIOCGWINSZ, &win);

    int w = win.ws_col, h = win.ws_row;
    buffer *buffer = malloc(sizeof(*buffer));
    buffer->buffer = malloc(w * h * sizeof(float));

    return 0;
}

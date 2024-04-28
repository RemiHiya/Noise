#include "include/render.h"
#include "include/utils.h"
#include "include/noises.h"
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    struct winsize win;
    ioctl(0, TIOCGWINSZ, &win);

    buffer *buffer = malloc(sizeof(struct BUFFER_T));
    buffer->buffer = malloc(win.ws_col * win.ws_row * sizeof(float));
    buffer->w = win.ws_col;
    buffer->h = win.ws_row - 1;

    render(buffer, voronoi);
    draw_buffer(buffer);

    return 0;
}

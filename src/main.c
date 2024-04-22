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
    buffer->h = win.ws_row;

    printf("%d, %d\n", buffer->w, buffer->h);
    voronoi(buffer, 10);

    render(buffer);

    return 0;
}

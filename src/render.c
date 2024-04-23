#include "include/render.h"
#include "include/utils.h"
#include <stdio.h>
#include <string.h>


void draw_buffer(buffer *buffer) {
    //char intensity[] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'.";
    char intensity[] = " .:-=+*#%@";

    for (int y=0; y<buffer->h; ++y) {
        for (int x=0; x<buffer->w; ++x) {
            int index = (int) (buffer->buffer[y*buffer->w + x] * strlen(intensity));
            index = MIN(index, strlen(intensity) - 1);
            printf("%c", intensity[index]);
        }
        printf("\n");
    }
}

void render(buffer *buffer, float (*fn)(float2, float, int)) {
    for (int y=0; y<buffer->h; ++y) {
        for (int x=0; x<buffer->w; ++x) {
            float2 coord = { (float)x/buffer->w, (float)y/buffer->h};
            buffer->buffer[y*buffer->w + x] = fn(coord, 0.5* (float)buffer->w/buffer->h, 42);
        }
    }
}

#include "include/render.h"
#include "include/utils.h"
#include <stdio.h>
#include <string.h>


void render(buffer *buffer) {
    char intensity[] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

    for (int y=0; y<buffer->h; ++y) {
        for (int x=0; x<buffer->w; ++x) {
            int index = (int) (buffer->buffer[y*buffer->w + x] * strlen(intensity));
            index = MIN(index, strlen(intensity) - 1);
            printf("%c", intensity[index]);
        }
        printf("\n");
    }
}

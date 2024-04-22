#include "include/noises.h"
#include "include/utils.h"
#include <stdio.h>
#include <stdlib.h>

void voronoi(buffer *buffer, int cell_size) {
    srand(1);
    int num_x = 1 + buffer->w / cell_size, num_y = 1 + buffer->h/cell_size;

    coord *centers = malloc(num_x * num_y * sizeof(coord));
    for (int i=0; i<num_y; ++i) {
        for (int j=0; j<num_x; ++j) {
            centers[i*num_x + j] = (coord) {j*cell_size + cell_size/2, i*cell_size + cell_size/2};
            centers[i*num_x + j].x += rand()%(cell_size);
            centers[i*num_x + j].y += rand()%(cell_size);
        }
    }

    for (int i=0; i<buffer->h; ++i) {
        for (int j=0; j<buffer->w; ++j) {
            coord a = {j, i};
            float min = 99999;
            int min_index = -1;
            coord b;
            // recup le centre
            for (int k=0; k<(num_x*num_y); ++k) {
                float d = dist(a, centers[k]);
                if (d < min) {
                    min = d;
                    min_index = k;
                }
                b = centers[k];
                min = MIN(min, dist(a, b));
            }
            srand(min_index);
            buffer->buffer[i * buffer->w + j] = (float)rand()/(float)RAND_MAX;//min/cell_size;
        }
    }
}

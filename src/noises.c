#include "include/noises.h"
#include "include/utils.h"
#include <stdio.h>
#include <stdlib.h>


float voronoi(float2 uv, float ratio, int seed) {
    int num = 7;
    uv.x *= ratio;
    uv.x *= num; uv.y *= num;

    float2 id = { (int)uv.x, (int)uv.y };
    float2 grid_coord = { fract(uv.x) - 0.5, fract(uv.y) - 0.5 };

    float min_dist = 100;
    float tmp = 0;
    for (int i=-1; i<=1; ++i) {
        for (int j=-1; j<=1; ++j) {
            //srand(seed + 13*i + +64*j + 5*grid_id.x+32*grid_id.y);
            srand(id.x + id.y + i +j + seed);
            float2 a = {i + rand()/(float)RAND_MAX, j + rand()/(float)RAND_MAX};
            float2 b = {grid_coord.x - a.x, grid_coord.y - a.y};
            float dist = lenght(b);
            min_dist = MIN(dist, min_dist);
            tmp += smoothstep(0.95, 0.96, 1-dist);
        }
    }
    return smoothstep(0, 1, min_dist);
}
/*
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
}*/

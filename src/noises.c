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

    float min_dist = 1000;
    float tmp = 0;
    for (int i=-1; i<=1; ++i) {
        for (int j=-1; j<=1; ++j) {
            //srand(seed + 13*i + +64*j + 5*grid_id.x+32*grid_id.y);
            srand(150*(id.x + i) + 15*(id.y +j) + seed+1);
            float2 a = {i + rand()/(float)RAND_MAX, j + rand()/(float)RAND_MAX};
            float2 b = {grid_coord.x - a.x, grid_coord.y - a.y};
            float dist = lenght(b);
            if (dist < min_dist) {
                tmp = rand_float();
            }
            min_dist = MIN(dist, min_dist);
        }
    }
    return tmp;                         // Pour avoir juste le pattern
    return smoothstep(0, 1, min_dist);  // Pour avoir le gradient
}

float value(float2 uv, float ratio, int seed) {
    int num = 7;
    uv.x *= ratio;
    uv.x *= num; uv.y *= num;

    float2 i = floor2(uv);
    float2 f = fract2(uv);

    float2 u = {f.x*f.x*f.x*(f.x*(f.x*6-15)+10), f.y*f.y*f.y*(f.y*(f.y*6-15)+10)};

    return 0.5 + 0.5 * lerp(
        lerp(hash(i), hash((float2){i.x+1, i.y}), 1-u.x),
        lerp(hash((float2){i.x, i.y+1}), hash((float2){i.x+1, i.y+1}), 1-u.x),
        1-u.y
    );
}


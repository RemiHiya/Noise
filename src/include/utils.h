#ifndef UTILS_H_
#define UTILS_H_
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

typedef struct COORD_T {
    int x;
    int y;
} coord;

typedef struct BUFFER_T {
    float *buffer;
    int w, h;
} buffer;

float dist(coord a, coord b);
#endif // UTILS_H_

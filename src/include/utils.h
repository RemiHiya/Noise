#ifndef UTILS_H_
#define UTILS_H_
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

typedef struct COORD_T {
    float x;
    float y;
} coord;

typedef struct BUFFER_T {
    float *buffer;
    int w, h;
} buffer;
#endif // UTILS_H_

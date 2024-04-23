#ifndef UTILS_H_
#define UTILS_H_
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

typedef struct COORD_T {
    int x;
    int y;
} coord;

typedef struct FLOAT2_T {
    float x, y;
} float2;

typedef struct BUFFER_T {
    float *buffer;
    int w, h;
} buffer;

float dist(coord a, coord b);
double sqrt(double x);
float fract(float x);
#endif // UTILS_H_

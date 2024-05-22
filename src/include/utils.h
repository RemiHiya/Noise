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
float lenght(float2 a);
double sqrt(double x);
float2 floor2(float2 a);
float fract(float x);
float2 fract2(float2 a);
float smoothstep(float edge0, float edge1, float x);
float lerp(float a, float b, float alpha);
float hash(float2 a);
float rand_float();
#endif // UTILS_H_

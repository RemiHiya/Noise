#include "include/utils.h"
#include <stdlib.h>

float dist(coord a, coord b) {
    int x = b.x - a.x;
    int y = b.y - a.y;
    return sqrt(x*x + y*y);
}

float lenght(float2 a) {
  return sqrt(a.x*a.x + a.y*a.y);
}

double sqrt(double x) {
  if (x < 0) {
    return -1;
  }
  double left = 0, right = x + 1;
  for (int i = 0; i < 20; i++) {
    double middle = (left + right) / 2;
    if (middle * middle < x) {
      left = middle;
    } else {
      right = middle;
    }
  }

  return left;
}

float2 floor2(float2 a) {
    return (float2) {(int) a.x, (int) a.y};
}


float fract(float x) {
  return x - (int) x;
}

float2 fract2(float2 a) {
    return (float2) {fract(a.x), fract(a.y)};
}

float smoothstep(float edge0, float edge1, float x) {
    float t = (x - edge0) / (edge1 - edge0);
    t = (t < 0.0f) ? 0.0f : (t > 1.0f) ? 1.0f : t;
    return t * t * (3.0f - 2.0f * t);
}

float lerp(float a, float b, float alpha) {
    return alpha * a + (1-alpha) * b;
}

float hash(float2 a) {
    int n = a.x*3 + a.y*113;

    n = (n << 13) ^ n;
    n = n * (n * n * 15731 + 789221) + 1376312589;
    return -1.0+2.0 * (float)(n & 0x0fffffff)/(0x0fffffff);
}

float rand_float() {
    return rand() / (float) RAND_MAX;
}

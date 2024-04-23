#include "include/utils.h"

float dist(coord a, coord b) {
    int x = b.x - a.x;
    int y = b.y - a.y;
    return sqrt(x*x + y*y);
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

float fract(float x) {
  return x - (int) x;
}

#include "include/utils.h"
#include <math.h>

float dist(coord a, coord b) {
    int x = b.x - a.x;
    int y = b.y - a.y;
    return sqrtf(x*x + y*y);
}

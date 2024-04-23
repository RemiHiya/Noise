#ifndef RENDER_H_
#define RENDER_H_
#include "utils.h"

void draw_buffer(buffer *buffer);
void render(buffer *buffer, float (*fn)(float2, float));

#endif // RENDER_H_

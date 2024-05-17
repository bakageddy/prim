#ifndef PRIM_CIRCLE_H
#define PRIM_CIRCLE_H

#include "line.h"

typedef struct {
	Point c;
	int r;
} Circle;

void draw_circle_bresenham(Circle c);

#define PRIM_CIRCLE_IMPL
#ifdef PRIM_CIRCLE_IMPL
#include <assert.h>
void draw_circle_bresenham(Circle c) {
	assert(c.r > 0);
	int cx = c.c.x, cy = c.c.y;
	int x = 0, y = c.r;
	int d = 3 - (2 * c.r);
	while (y >= x) {
		x += 1;
		if (d > 0) {
			y -= 1;
			d = d + (4 * (x - y)) + 10;
		} else {
			d = d + (4 * x) + 6;
		}
		draw_point((Point) {.x = cx + x, .y = cy + y});
		draw_point((Point) {.x = cx - x, .y = cy + y});
		draw_point((Point) {.x = cx + x, .y = cy - y});
		draw_point((Point) {.x = cx - x, .y = cy - y});
		draw_point((Point) {.x = cx + y, .y = cy + x});
		draw_point((Point) {.x = cx - y, .y = cy + x});
		draw_point((Point) {.x = cx + y, .y = cy - x});
		draw_point((Point) {.x = cx - y, .y = cy - x});
	}
}

#endif // PRIM_IMPL

#endif // !PRIM_CIRCLE_H

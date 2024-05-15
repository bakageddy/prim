#ifndef PRIM_LINE_H
#define PRIM_LINE_H

#define FILL '.'

typedef struct {
	int x, y;
} Point;

typedef struct {
	Point a, b;
} Line;

void draw_point(Point p);
void draw_line_dda(Line l);

#ifdef PRIM_LINE_IMPL

#include <ncurses.h>
#include <stdlib.h>
#include <math.h>

void draw_point(Point p) {
	move(p.y, p.x);
	addch(FILL);
}

void draw_line_dda(Line l) {
	int dx = l.b.x - l.a.x;
	int dy = l.b.y - l.a.y;
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	float xinc = dx / (float) steps;
	float yinc = dy / (float) steps;
	float x = l.a.x;
	float y = l.a.y;
	for (int i = 0; i < steps; i++) {
		Point p = {
			.x = floor(x),
			.y = floor(y),
		};
		draw_point(p);
		x += xinc;
		y += yinc;
	}
}

// TODO: implement bresenham line drawing algorithm
void draw_line_bresenham(Line l) {
	return;
}

#endif // PRIM_LINE_IMPL

#endif // PRIM_LINE_H

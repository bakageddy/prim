#define PRIM_LINE_IMPL
#include "line.h"

#define PRIM_CIRCLE_IMPL
#include "circle.h"

#include <ncurses.h>

int main(void) {
	char msg[] = "Bresenham Circle Drawing Algorithm";
	size_t len = sizeof(msg);

	initscr();
	move(0, (COLS - len) / 2);
	addstr(msg);
	refresh();

	// Point a = {
	// 	.x = 0,
	// 	.y = 0,
	// };
	//
	// Point b = {
	// 	.x = COLS,
	// 	.y = LINES,
	// };
	// draw_line_dda((Line) {.a = a, .b = b});
	
	Point c = {
		.x = COLS / 2,
		.y = LINES / 2,
	};
	draw_circle_bresenham((Circle) {.c = c, .r = 10});

	refresh();

	getch();
	endwin();

	return 0;
}

#define PRIM_LINE_IMPL
#include "line.h"

#include <ncurses.h>

int main(void) {
	char msg[] = "DDA Line Drawing Algorithm";
	size_t len = sizeof(msg);

	initscr();
	move(0, (COLS - len) / 2);
	addstr(msg);
	refresh();

	Point a = {
		.x = 0,
		.y = 0,
	};

	Point b = {
		.x = COLS,
		.y = LINES,
	};
	draw_line_dda((Line) {.a = a, .b = b});

	refresh();

	getch();
	endwin();

	return 0;
}

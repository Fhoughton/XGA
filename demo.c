#include "xga.h"
#include <stdbool.h>

int main() {
	XGA_init();
	const XGA_color RED = {255, 0, 0};
	const XGA_color GREEN = {0, 255, 0};
	const XGA_color BLUE = {0, 0, 255};
	XGA_color line_color = RED;

	while (true) {
		// Update
		XGA_update();
		if (XGA_isAPressed()) {
			line_color = GREEN;
		}
		if (XGA_isBPressed()) {
			line_color = BLUE;
		}

		// Draw
		int i = 0; 
		for (i = 0; i < SCREEN_WIDTH; i++) {
			XGA_drawPixel(i, i, line_color); 
		}
		XGA_drawLine(10,0, 20, 60, GREEN);
		XGA_drawRect(41, 41, 5, 5, BLUE);
		XGA_drawRect(40, 40, 4, 4, GREEN);
		XGA_drawRectLines(40, 40, 5, 5, RED);
		XGA_drawScreen();
		XGA_wait(1/60);
	}
	XGA_exit();
	return 0;
}

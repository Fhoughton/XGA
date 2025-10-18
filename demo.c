#include "xga.h"
#include <stdbool.h>

int main() {
	XGA_init();
	XGA_color RED = {255, 0, 0};

	int i = 0; 
	for (i = 0; i < SCREEN_WIDTH; i++) {
		XGA_drawPixel(i, i, RED); 
	}

	XGA_drawScreen();
	XGA_exit();
	return 0;
}

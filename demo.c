#include "xga.h"
#include <stdbool.h>

int main() {
	XGA_init();
	XGA_color RED = {255, 0, 0};

	while (true) {
		XGA_update();
		int i = 0; 
		for (i = 0; i < SCREEN_WIDTH; i++) {
			XGA_drawPixel(i, i, RED); 
		}
		XGA_drawScreen();
		XGA_wait(1/60);
		RED.g += 1;
	}
	XGA_exit();
	return 0;
}

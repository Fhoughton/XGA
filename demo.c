#include "xga.h"

int main() {
	XGA_color RED = {255, 0, 0};
	XGA_drawPixel(0, 0, RED); 
	XGA_drawScreen();
	return 0;
}

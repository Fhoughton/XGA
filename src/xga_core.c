#include "xga.h"

/* Globals */
XGA_surface XGA_screen;

/* Functions */
void XGA_drawPixel(int x, int y, XGA_color color) {
	XGA_screen[x][y] = color;
}

int XGA_colorEqual(XGA_color a, XGA_color b) {
	return (a.r == b.r) && (a.g == b.g) && (a.b == b.b);
}

void XGA_drawSurface(XGA_surface* surface, XGA_color* mask) {
	if (mask != NULL) {
		int x, y;
		
		for (x = 0; x < SCREEN_WIDTH; x++) {
			for (y = 0; y < SCREEN_WIDTH; y++) {
				if (XGA_colorEqual((*surface)[x][y], *mask) == 0) {
					XGA_screen[x][y] = (*surface)[x][y];
				}
			}
		}
	} else {
		memcpy(XGA_screen, surface, sizeof(surface));
	}
}

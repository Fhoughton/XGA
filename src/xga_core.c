#include "xga.h"
#include <stdlib.h>

/* Globals */
XGA_sprite XGA_screen;

/* Functions */
void XGA_init() {
	XGA_screen.width = SCREEN_WIDTH;
	XGA_screen.height = SCREEN_HEIGHT;

	XGA_screen.data = malloc(SCREEN_WIDTH * sizeof(XGA_color *));
	XGA_screen.data[0] = calloc(SCREEN_WIDTH * SCREEN_HEIGHT, sizeof(XGA_color));
	for (int x = 1; x < SCREEN_WIDTH; ++x) {
	    XGA_screen.data[x] = XGA_screen.data[0] + x * SCREEN_WIDTH;
	}
	XGA_platform_init();
}

void XGA_drawPixel(int x, int y, XGA_color color) {
	XGA_screen.data[x][y] = color;
}

int XGA_colorEqual(XGA_color a, XGA_color b) {
	return (a.r == b.r) && (a.g == b.g) && (a.b == b.b);
}

void XGA_drawSprite(XGA_sprite* sprite, XGA_color* mask) {
	if (mask != NULL) {
		int x, y;
		
		for (x = 0; x < SCREEN_WIDTH; x++) {
			for (y = 0; y < SCREEN_WIDTH; y++) {
				if (XGA_colorEqual((*sprite).data[x][y], *mask) == 0) {
					XGA_screen.data[x][y] = (*sprite).data[x][y];
				}
			}
		}
	} else {
		// TODO: Confirm if the below memcpy is safe for the equivalent code
		// memcpy(XGA_screen.data, sprite, sizeof(sprite));
		int x, y;
		for (x = 0; x < sprite->width; x++) {
			for (y = 0; y < sprite->height; y++) {
				XGA_screen.data[x][y] = sprite->data[x][y];
			}
		}
	}
}

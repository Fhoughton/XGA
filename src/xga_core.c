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

void XGA_drawLineLow(int x1, int y1, int x2, int y2, XGA_color color) {
	int dx = x2 - x1;
	int dy = y2 - y1;
	
	int yi = 1;
	
	if (dy < 0) {
        yi = -1;
        dy = -dy;
	}
	
	int D = 2*dy - dx;
	int y = y1;
	
	
	
	for (int x = x1; x < x2; x++) {
		XGA_drawPixel(x,y,color);
		if (D > 0) {
			y += yi;
			D = D + (2 * (dy - dx));
		}
		else {
			D = D + 2*dy;
		}
	}
}

void XGA_drawLineHigh(int x1, int y1, int x2, int y2, XGA_color color) {
	int dx = x2 - x1;
    int dy = y2 - y1;
    int xi = 1;
    if (dx < 0) {
        xi = -1;
        dx = -dx;
	}
	
    int D = (2 * dx) - dy;
    int x = x1;

    for (int y = y1; y < y2; y++) {
        XGA_drawPixel(x,y,color);
        if (D > 0) {
            x = x + xi;
            D = D + (2 * (dx - dy));
		}
        else {
            D = D + 2*dx;
		}
	}
}

void XGA_drawLine(int x1, int y1, int x2, int y2, XGA_color color) {
	/*
	This function implements Bresenham's line algorithm
	See: https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
	*/
	if (abs(y2 - y1) < abs(x2 - x1)) {
		if (x1 > x2) {
            XGA_drawLineLow(x2, y2, x1, y1, color);
		}
        else {
            XGA_drawLineLow(x1, y1, x2, y2, color);
		}
	} else {
		if (y1 > y2) {
            XGA_drawLineHigh(x2, y2, x1, y1, color);
		}
        else {
            XGA_drawLineHigh(x1, y1, x2, y2, color);
		}
	}
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

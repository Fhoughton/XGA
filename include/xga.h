#pragma once

/* HEADERS */
#include <stddef.h>
#include <stdint.h>
#include <string.h>

/*
----------------------------------------------------------------------------------
INTERNAL DEFINITIONS 
----------------------------------------------------------------------------------
*/
/* Constants */
#ifndef SCREEN_WIDTH
	#define SCREEN_WIDTH 64
#endif

#ifndef SCREEN_HEIGHT
	#define SCREEN_HEIGHT 64
#endif

/* Structs */
typedef struct XGA_color {
	uint8_t r;
	uint8_t g;
	uint8_t b;
} XGA_color;

typedef XGA_color XGA_surface[SCREEN_WIDTH][SCREEN_HEIGHT];

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

/*
----------------------------------------------------------------------------------
PER-PLATFORM FORWARD DEFINITIONS
----------------------------------------------------------------------------------
*/
/* Input */
int XGA_isAPressed();
int XGA_isBPressed();
int XGA_isLeftPressed();
int XGA_isRightPressed();
int XGA_isUpPressed();
int XGA_isDownPressed();
int XGA_isStartPressed();
int XGA_isSelectPressed();

/* Rendering */
void XGA_drawScreen();

/* Audio */

#pragma once

#ifndef SCREEN_WIDTH
	#define SCREEN_WIDTH 64
#endif

#ifndef SCREEN_HEIGHT
	#define SCREEN_HEIGHT 64
#endif

#include <stdint.h>

typedef struct XGA_color {
	uint8_t r;
	uint8_t g;
	uint8_t b;
} XGA_color;

typedef struct XGA_screen {
	XGA_color screen[SCREEN_WIDTH][SCREEN_HEIGHT];
} XGA_screen;
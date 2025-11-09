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

typedef struct XGA_sprite
{
	XGA_color **data; // Dynamically allocate 2D array
	int width;
	int height;
} XGA_sprite;

/* Globals */
extern XGA_sprite XGA_screen;

/* Functions */
void XGA_init();
void XGA_clearScreen(XGA_color color);
void XGA_drawPixel(int x, int y, XGA_color color);
void XGA_drawLine(int x1, int y1, int x2, int y2, XGA_color color);
void XGA_drawRect(int x1, int y1, int width, int height, XGA_color color);
void XGA_drawRectLines(int x1, int y1, int width, int height, XGA_color color);
int XGA_colorEqual(XGA_color a, XGA_color b);
void XGA_drawSprite(XGA_sprite* surface, int x, int y, XGA_color mask);

/*
----------------------------------------------------------------------------------
PER-PLATFORM FORWARD DEFINITIONS
----------------------------------------------------------------------------------
*/
/* Internals */
void XGA_platform_init(); // Platform-specific, can be empty
void XGA_exit(); // Cleanup code
void XGA_wait(float seconds); // Seconds to wait for, supports floats
void XGA_update(); // Platform-specific updates like input handling, sound updates etc.

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

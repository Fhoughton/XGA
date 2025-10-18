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
extern XGA_surface XGA_screen;

/* Functions */
void XGA_drawPixel(int x, int y, XGA_color color);
int XGA_colorEqual(XGA_color a, XGA_color b);
void XGA_drawSurface(XGA_surface* surface, XGA_color* mask);

/*
----------------------------------------------------------------------------------
PER-PLATFORM FORWARD DEFINITIONS
----------------------------------------------------------------------------------
*/
/* Internals */
void XGA_init(); // Platform-specific, can be empty
void XGA_exit();

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

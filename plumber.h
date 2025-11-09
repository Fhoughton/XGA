#pragma once
#define PLUMBER_WIDTH 8
#define PLUMBER_HEIGHT 8

static XGA_color plumber_row0[PLUMBER_WIDTH] = {
	{0,255,0},
	{0,255,0},
	{0,255,0},
	{0,255,0},
	{0,255,0},
	{0,255,0},
	{0,255,0},
	{0,255,0},
};

static XGA_color plumber_row1[PLUMBER_WIDTH] = {
	{0,255,0},
	{0,255,0},
	{0,255,0},
	{0,255,0},
	{196,132,164},
	{196,132,164},
	{196,132,164},
	{196,132,164},
};

static XGA_color plumber_row2[PLUMBER_WIDTH] = {
	{196,132,164},
	{196,132,164},
	{153,130,118},
	{247,249,196},
	{196,132,164},
	{196,132,164},
	{196,132,164},
	{196,132,164},
};

static XGA_color plumber_row3[PLUMBER_WIDTH] = {
	{196,132,164},
	{196,132,164},
	{247,249,196},
	{247,249,196},
	{196,132,164},
	{196,132,164},
	{0,255,0},
	{0,255,0},
};

static XGA_color plumber_row4[PLUMBER_WIDTH] = {
	{196,132,164},
	{196,132,164},
	{162,242,189},
	{247,249,196},
	{196,132,164},
	{196,132,164},
	{196,132,164},
	{196,132,164},
};

static XGA_color plumber_row5[PLUMBER_WIDTH] = {
	{196,132,164},
	{196,132,164},
	{247,249,196},
	{247,249,196},
	{196,132,164},
	{196,132,164},
	{196,132,164},
	{196,132,164},
};

static XGA_color plumber_row6[PLUMBER_WIDTH] = {
	{0,255,0},
	{196,132,164},
	{0,255,0},
	{0,255,0},
	{0,255,0},
	{196,132,164},
	{0,255,0},
	{0,255,0},
};

static XGA_color plumber_row7[PLUMBER_WIDTH] = {
	{0,255,0},
	{196,132,164},
	{0,255,0},
	{0,255,0},
	{0,255,0},
	{196,132,164},
	{0,255,0},
	{0,255,0},
};

static XGA_color *plumber_sprite_rows[PLUMBER_HEIGHT] = {plumber_row0,plumber_row1,plumber_row2,plumber_row3,plumber_row4,plumber_row5,plumber_row6,plumber_row7};

static XGA_sprite plumber = {
	.data = plumber_sprite_rows,
	.width = PLUMBER_WIDTH,
	.height = PLUMBER_HEIGHT
};

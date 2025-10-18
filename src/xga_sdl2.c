#include "xga.h"

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

//The window we'll be rendering to
SDL_Window* window = NULL;
SDL_Renderer *renderer = NULL;

void XGA_init() {
	int success = 0;
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		SDL_Init(SDL_INIT_VIDEO);
		SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
	}
}

void XGA_exit() {
    SDL_DestroyWindow( window );
    SDL_Quit();
}

void XGA_drawScreen() {
	// Platforms should aim to clear the screenw white before drawing
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	// Then loop over and place each pixel from the XGA_surface array
	int x;
	int y;

	for (x = 0; x < SCREEN_WIDTH; x++) {
		for (y = 0; y < SCREEN_HEIGHT; y++) {
			XGA_color pixelColor = XGA_screen[x][y];
			SDL_SetRenderDrawColor(renderer, pixelColor.r, pixelColor.g, pixelColor.b, 255);
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}

	SDL_RenderPresent(renderer);
}

void XGA_update() {
	SDL_Event e;

	while( SDL_PollEvent( &e ) != 0 )
	{
		//User requests quit
		if( e.type == SDL_QUIT )
		{
			XGA_exit();
		}
	}
}

void XGA_wait(float seconds) {
	float ms = seconds * 1000;
	SDL_Delay((int)ms);
}

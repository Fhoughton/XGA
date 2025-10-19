#include "xga.h"

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

//The window we'll be rendering to
SDL_Window* window = NULL;
SDL_Renderer *renderer = NULL;

void XGA_platform_init() {
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
			XGA_color pixelColor = XGA_screen.data[x][y];
			SDL_SetRenderDrawColor(renderer, pixelColor.r, pixelColor.g, pixelColor.b, 255);
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}

	SDL_RenderPresent(renderer);
}


bool XGA_key_UP = false;
bool XGA_key_LEFT = false;
bool XGA_key_DOWN = false;
bool XGA_key_RIGHT = false;
bool XGA_key_A = false;
bool XGA_key_B = false;

void XGA_update() {
	SDL_Event e;

	while( SDL_PollEvent( &e ) != 0 )
	{
		//User requests quit
		if( e.type == SDL_QUIT )
		{
			XGA_exit();
		}
		// Map inputs to global to for other functions
		else if( e.type == SDL_KEYDOWN )
                {
			switch (e.key.keysym.sym)
			{
				case SDLK_w: XGA_key_UP = true; break;
				case SDLK_a: XGA_key_LEFT = true; break;
				case SDLK_s: XGA_key_DOWN = true; break;
				case SDLK_d: XGA_key_RIGHT = true; break;
				case SDLK_m: XGA_key_A = true; break;
				case SDLK_n: XGA_key_B = true; break;
				default: break;
			}
		}
		else if (e.type == SDL_KEYUP)
		{
			switch (e.key.keysym.sym)
			{
				case SDLK_w: XGA_key_UP = false; break;
				case SDLK_a: XGA_key_LEFT = false; break;
				case SDLK_s: XGA_key_DOWN = false; break;
				case SDLK_d: XGA_key_RIGHT = false; break;
				case SDLK_m: XGA_key_A = false; break;
				case SDLK_n: XGA_key_B = false; break;
				default: break;
			}
		}
	}
}

void XGA_wait(float seconds) {
	float ms = seconds * 1000;
	SDL_Delay((int)ms);
}

int XGA_isAPressed() {
	return XGA_key_A;
}

int XGA_isBPressed() {
	return XGA_key_B;
}

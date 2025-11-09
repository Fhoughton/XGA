#include "xga.h"
#include <stdbool.h>
#include <stdlib.h>

#include "plumber.h"

/* Global definitions */
const XGA_color RED = {255, 0, 0};
const XGA_color GREEN = {0, 255, 0};
const XGA_color BLUE = {0, 0, 255};
const XGA_color BLACK = {0, 0, 0};

/* Player code */
typedef struct Player {
	float x, y;
} Player;

Player* initPlayer(int x, int y) {
	Player* result = malloc(sizeof(Player));
	result->x = x;
	result->y = y;
	
	return result;
}

void handlePlayerInput(Player* p) {
	if (XGA_isUpPressed()) {
		(p->y) -= 0.1f;
	}
	if (XGA_isDownPressed()) {
		(p->y) += 0.1f;
	}
	if (XGA_isLeftPressed()) {
		(p->x) -= 0.1f;
	}
	if (XGA_isRightPressed()) {
		(p->x) += 0.1f;
	}
	
	// Bind movement to screen to stop crashes
	if ((p->x) < 0.0f) {
		(p->x) = 0.0f;
	}
	if ((p->x) > SCREEN_WIDTH-PLUMBER_WIDTH) {
		(p->x) = SCREEN_WIDTH-PLUMBER_WIDTH;
	}
	
	if ((p->y) > SCREEN_HEIGHT-PLUMBER_HEIGHT) {
		(p->y) = SCREEN_HEIGHT-PLUMBER_HEIGHT;
	}
	if ((p->y) < 0) {
		(p->y) = 0.0f;
	}
}

void drawPlayer(Player* p) {
	//XGA_drawRect((int)((p->x)+1), (int)((p->y)+1), 5, 5, BLUE);
	//XGA_drawRect((int)p->x, (int)p->y, 4, 4, GREEN);
	
	XGA_drawSprite(&plumber, (int)p->x, (int)p->y, GREEN);
}

Player* player;

/* Main game */
int main() {
	XGA_init();

	XGA_color line_color = RED;
	
	player = initPlayer(40.0f, 40.0f);

	while (true) {
		// Update
		XGA_update();
		
		// Basic character movement
		handlePlayerInput(player);
		if (XGA_isAPressed()) {
			line_color = GREEN;
		}
		if (XGA_isBPressed()) {
			line_color = BLUE;
		}

		// Draw
		int i = 0;
		XGA_clearScreen(BLACK);
		for (i = 0; i < SCREEN_WIDTH; i++) {
			XGA_drawPixel(i, i, line_color); 
		}
		XGA_drawLine(10,0, 20, 60, GREEN);
		drawPlayer(player);
		XGA_drawRectLines(40, 40, 5, 5, RED);
		
		XGA_drawScreen();
		XGA_wait(1/60);
	}
	XGA_exit();
	return 0;
}

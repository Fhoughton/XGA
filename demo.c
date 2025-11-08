#include "xga.h"
#include <stdbool.h>

int main() {
	XGA_init();
	const XGA_color RED = {255, 0, 0};
	const XGA_color GREEN = {0, 255, 0};
	const XGA_color BLUE = {0, 0, 255};
	const XGA_color BLACK = {0, 0, 0};
	XGA_color line_color = RED;
	
	float rectX = 40.0f;
	float rectY = 40.0f;

	while (true) {
		// Update
		XGA_update();
		
		// Basic character movement
		if (XGA_isAPressed()) {
			line_color = GREEN;
		}
		if (XGA_isBPressed()) {
			line_color = BLUE;
		}
		
		if (XGA_isUpPressed()) {
			rectY -= 0.1f;
		}
		if (XGA_isDownPressed()) {
			rectY += 0.1f;
		}
		if (XGA_isLeftPressed()) {
			rectX -= 0.1f;
		}
		if (XGA_isRightPressed()) {
			rectX += 0.1f;
		}
		
		// Bind movement to screen to stop crashes
		if (rectX < 0.0f) {
			rectX = 0.0f;
		}
		if (rectX > SCREEN_WIDTH-6) {
			rectX = SCREEN_WIDTH-6;
		}
		
		if (rectY > SCREEN_HEIGHT-6) {
			rectY = SCREEN_HEIGHT-6;
		}
		if (rectY < 0) {
			rectY = 0.0f;
		}
		
		

		// Draw
		int i = 0;
		XGA_clearScreen(BLACK);
		for (i = 0; i < SCREEN_WIDTH; i++) {
			XGA_drawPixel(i, i, line_color); 
		}
		XGA_drawLine(10,0, 20, 60, GREEN);
		XGA_drawRect((int)(rectX+1), (int)(rectY+1), 5, 5, BLUE);
		XGA_drawRect((int)rectX, (int)rectY, 4, 4, GREEN);
		XGA_drawRectLines(40, 40, 5, 5, RED);
		XGA_drawScreen();
		XGA_wait(1/60);
	}
	XGA_exit();
	return 0;
}

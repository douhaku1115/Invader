#pragma once
#include "Rect.h"
#include "Header.h"


struct Ground :Rect {
	unsigned char m_pixels[SCREEN_WIDTH];
	unsigned m_texture;

	int init();
	void draw();
	void erasePixel(int _x);
};
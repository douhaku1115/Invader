#pragma once
#include "Rect.h"
#define GROUND_WIDTH 256


struct Ground :Rect {
	unsigned char m_pixels[GROUND_WIDTH];
	unsigned m_texture;

	int init();
	void draw();
	void erasePixel(int _x);
};
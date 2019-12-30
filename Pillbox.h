#pragma once
#include "Rect.h"
#define PILLBOX_WIDTH 22
#define PILLBOX_HEIGHT 16
#define PILLBOX_MAX 4
#define PILLBOX_TOP (SCREEN_HEIGHT - 8*8)

struct Pillbox :Rect {
	unsigned char m_pixels[PILLBOX_HEIGHT][PILLBOX_WIDTH];
	unsigned int m_texture;
	int init();
	void draw();


};
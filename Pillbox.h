#pragma once
#include "Rect.h"
#define PILLBOX_WIDTH 22
#define PILLBOX_HEIGHT 16
#define PILLBOX_MAX 4
#define PILLBOX_TOP (SCREEN_HEIGHT - 8*8)

struct Pillbox :Rect {
	int init();
	void draw();


};
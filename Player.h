#pragma once
#include "Rect.h"
#define PLAYER_WIDTH       13
#define PLAYER_HIGHT       8
#define PLAYER_DEFAULT_X   (PLAYER_WIDTH) 
#define PLAYER_DEFAULT_Y   8*28


struct Player :Rect {
	unsigned int m_texture;

	int init();
	void update();
	void draw();
	void shoot();
};

#pragma once
#include "Rect.h"

#define PLAYER_BULLET_WIDTH   1
#define PLAYER_BULLET_HEIGHT  4
#define PLAYER_BULLET_SPEED   4


struct PlayerBullet :Rect {
	unsigned int m_texture;
	bool m_enable;


	int init();
	void update();
	void draw();


};
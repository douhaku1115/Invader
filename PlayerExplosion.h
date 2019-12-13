#pragma once
#include "Rect.h"

#define PLAYER_EXPLOSION_WIDTH 16
#define PLAYER_EXPLOSION_HEIGHT 8
#define PLAYER_EXPLOSION_ANIMATION_MAX 2


struct PlayerExplosion :Rect {
	unsigned int m_textures[PLAYER_EXPLOSION_ANIMATION_MAX];
	int m_countLeft;

	int init();
	void update();
	void draw();
	void start(vec2 const& _position);
};
#pragma once
#include "Rect.h"
#define INVADER_BULLET_MAX    2
#define INVADER_BULLET_WIDTH  3
#define INVADER_BULLET_HEIGHT 8
#define INVADER_BULLET_SPEED  1
#define INVADER_BULLET_ANIMATION_TYPE_MAX 3
#define INVADER_BULLET_ANIMATION_LENGTH 4

struct InvaderBullet :Rect {
	bool m_enable;
	int m_animationType;
	int m_animationFrame;
	int init();
	static int initAll();
	void update();
	static void updateAll();
	void draw();
	static void drawAll();
	void shoot(vec2 const& _position);
};

extern InvaderBullet g_invaderBullets[INVADER_BULLET_MAX];

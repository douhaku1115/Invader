#pragma once
#include "Rect.h"
#define INVADER_BULLET_MAX    2
#define INVADER_BULLET_WIDTH  3
#define INVADER_BULLET_HEIGHT 8
#define INVADER_BULLET_SPEED  1

struct InvaderBullet :Rect {
	bool m_enable;
	int init();
	static int initAll();
	void update();
	static void updateAll();
	void draw();
	static void drawAll();

};

extern InvaderBullet g_invaderBullets[INVADER_BULLET_MAX];

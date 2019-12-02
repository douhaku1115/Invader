#pragma once
#include "Invader.h"
#define INVADER_BULLET_MAX    2
#define INVADER_BULLET_WIDTH  3
#define INVADER_BULLET_HEIGHT 8
#define INVADER_BULLET_SPEED  2
#define INVADER_BULLET_ANIMATION_TYPE_MAX 3
#define INVADER_BULLET_ANIMATION_LENGTH 4
#define INVADER_BULLET_ANIMATION_WAIT_MAX 3

struct InvaderBullet :Rect {
	bool m_enable;
	int m_animationType;
	int m_animationFrame;
	int m_animationWait;
	Invader* m_pOwner;

	int init();
	static int initAll();
	void update();
	static void updateAll();
	void draw();
	static void drawAll();
	void shoot(vec2 const& _position, Invader *_pOwner);
	static int getShootingCount();
};

extern InvaderBullet g_invaderBullets[INVADER_BULLET_MAX];

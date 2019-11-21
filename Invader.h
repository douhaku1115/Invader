#pragma once
#include "Rect.h"
#define INVADER_ANIIMATON_MAX	2
#define INVADER_ROW_MAX			5
#define INVADER_COLUMN_MAX		11
#define INVADER_MAX    INVADER_ROW_MAX * INVADER_COLUMN_MAX	      
#define INVADER_SPEED           4
struct Invader :Rect {
	static vec2 m_speed;
	static vec2 m_nextSpeed;
	static int m_current;
	unsigned int m_textures[INVADER_ANIIMATON_MAX];
	int m_animation;

	int init(
		const char* _fileName0,
		const char* _fileName1,
		vec2 _size,
		vec2 _Position = vec2());
	static int initAll(
		);

	void update();
	static void updateAll();

	void draw();
	static void drawAll();

};
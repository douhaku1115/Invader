#pragma once
#include "Rect.h"
#define INVADER_ANIIMATON_MAX 2

struct Invader :Rect {
	static vec2 m_speed;
	unsigned int m_textures[INVADER_ANIIMATON_MAX];
	int m_animation;

	int init(
		const char* _fileName0,
		const char* _fileName1,
		vec2 _size,
		vec2 _Position = vec2());

	void update();
	void draw();


};
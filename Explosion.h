#pragma once
#include "Rect.h"
#define EXPLOTION_COUNT_MAX 30

struct Explosion :Rect {
	unsigned int m_texture;
	int m_countLeft;
	
	int init(const char* fileName, vec2 const& _size);

	void start(vec2 const& _position);
	void update();
	void draw();

};
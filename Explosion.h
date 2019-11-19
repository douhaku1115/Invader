#pragma once
#include "Rect.h"
#define EXPLOTION_COUNT_MAX 30

struct Explosion :Rect {
	unsigned int m_texture;
	unsigned char m_color[3];
	int m_countLeft;
	
	int init(const char* fileName, vec2 const& _size,
		unsigned char _red,
		unsigned char _green,
		unsigned char _blue);

	void start(vec2 const& _position);
	void update();
	void draw();

};
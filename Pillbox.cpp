#include "Pillbox.h"
#include "glut.h"
#include "Header.h"

int Pillbox::init() {
	m_size = vec2(PILLBOX_WIDTH, PILLBOX_HEIGHT);
	return 0;

}
void Pillbox::draw() {
	
	glDisable(GL_TEXTURE_2D);
	setColorWithPosition(m_position);
Rect::draw();
	glEnable(GL_TEXTURE_2D);
}
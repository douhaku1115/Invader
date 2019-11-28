#include "InvaderBullet.h"
#include "glut.h"
#include"Header.h"

InvaderBullet g_invaderBullets[INVADER_BULLET_MAX];

int InvaderBullet::init() {
	m_size=vec2(INVADER_BULLET_WIDTH, INVADER_BULLET_HEIGHT);
		return 0; 
}
int InvaderBullet::initAll() {
	for (int i = 0; i < INVADER_BULLET_MAX; i++)
		g_invaderBullets[i].init();
	return 0;
}
void InvaderBullet::update() {
	if (!m_enable)
		return;
	m_position.y += INVADER_BULLET_SPEED;
	if (m_position.y >= SCREEN_HEIGHT)
		m_enable = false;

}
void InvaderBullet::updateAll() {
	for (int i = 0; i < INVADER_BULLET_MAX; i++)
		g_invaderBullets[i].update();
}
void InvaderBullet::draw() {
	if (!m_enable)
		return;
	glDisable(GL_TEXTURE_2D);
	setColorWithPosition(m_position);
	Rect::draw();
	glEnable(GL_TEXTURE_2D);
}
void InvaderBullet::drawAll() {
	for (int i = 0; i < INVADER_BULLET_MAX; i++)
		g_invaderBullets[i].draw();
}
#include "PlayerBullet.h"
#include "tex.h"
#include "Header.h"
#include "glut.h"

int PlayerBullet::init() {
	m_size = vec2(PLAYER_BULLET_WIDTH, PLAYER_BULLET_HEIGHT);
	
	glGenTextures(
		1,          //GLsizei n, 
		&m_texture);//GLuint *textures);
	glBindTexture(
		GL_TEXTURE_2D, //GLenum target, 
		m_texture);       //GLuint texture)
	texFromBPM("textures\white.bmp");
	return 0;

}
void PlayerBullet::update() {
	if (!m_enable)
		return;
	m_position.y -= PLAYER_BULLET_SPEED;

	if (m_position.y < 8 * 3) {
		m_enable = false;
		g_playerBulletExplosion.start(m_position
			-g_playerBulletExplosion.m_size/2.f);

	}
}
void PlayerBullet::draw() {
	if (!m_enable)
		return;
	glBindTexture(
		GL_TEXTURE_2D, //GLenum target, 
		m_texture);       //GLuint texture)
	glColor3ub(0xff, 0xff, 0xff);
	Rect::draw();

}
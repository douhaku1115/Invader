
#include "Header.h"
#include "Player.h"
#include "tex.h"
#include "glut.h"

int Player::init() {
	m_size = vec2(PLAYER_WIDTH, PLAYER_HIGHT);
	m_position = vec2(PLAYER_DEFAULT_X, PLAYER_DEFAULT_Y);

	glGenTextures(
		1,          //GLsizei n, 
		&m_texture);//GLuint *textures);
	glBindTexture(
		GL_TEXTURE_2D, //GLenum target, 
		m_texture);       //GLuint texture)
	texFromBPM("textures\player.bmp",0x00,0xff,0x00);
	return 0;
}
void Player::update() {
	if (g_keys['a'])
		if(m_position.x>0)
		m_position.x--;
	if (g_keys['d'])
		if (m_position.x + m_size.x<SCREEN_WIDTH)
		m_position.x++;
}
void Player::draw() {
	glBindTexture(
		GL_TEXTURE_2D, //GLenum target, 
		m_texture);
	Rect::draw();
}
void Player::shoot() {
	if (g_playerBullet.m_enable)
		return;
	g_playerBullet.m_enable = true;
	g_playerBullet.m_position = vec2(
		m_position.x + PLAYER_WIDTH / 2,
		m_position.y - PLAYER_BULLET_HEIGHT);

}
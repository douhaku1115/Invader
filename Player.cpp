
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
	texFromBPM("player.bmp",0x00,0xff,0x00);
	return 0;
}
void Player::update() {
	if (keys['a'])
		if(m_position.x>0)
		m_position.x--;
	if (keys['d'])
		if (m_position.x + m_size.x<SCREEN_WIDTH)
		m_position.x++;
}
void Player::draw() {
	glBindTexture(
		GL_TEXTURE_2D, //GLenum target, 
		m_texture);
	Rect::draw();
}
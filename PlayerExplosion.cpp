#include <stdio.h>
#include "PlayerExplosion.h"
#include "tex.h"
#include "glut.h"
#include "Header.h"
int PlayerExplosion::init() {
	glGenTextures(
		PLAYER_EXPLOSION_ANIMATION_MAX,          //GLsizei n, 
		m_textures);//GLuint *textures);
	for (int i = 0; i < PLAYER_EXPLOSION_ANIMATION_MAX; i++) {
		glBindTexture(
			GL_TEXTURE_2D, //GLenum target, 
			m_textures[i]);
		char fileName[256];
		sprintf_s(fileName, sizeof fileName, "textures\\player_explosion%d.bmp", i);
		texFromBPM(fileName,0x00,0xff,0x00);
	}
	m_size = vec2(PLAYER_EXPLOSION_WIDTH, PLAYER_EXPLOSION_HEIGHT);
	return 0;

}
void PlayerExplosion::update() {


}
void PlayerExplosion::draw() {
	glBindTexture(
		GL_TEXTURE_2D, //GLenum target, 
		m_textures[0]);
	setColorWithPosition(m_position);

	Rect::draw();
	
}
void PlayerExplosion::start(vec2 const& _position) {
	m_position = _position;


}
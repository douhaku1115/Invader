#include "Invader.h"
#include "tex.h"
#include "glut.h"

vec2 Invader::m_speed = vec2(1, 0);

int Invader::init(
	const char* _fileName0,
	const char* _fileName1,
	vec2 _size,
	vec2 _position)  {

	glGenTextures(
		INVADER_ANIIMATON_MAX,          //GLsizei n, 
		m_textures);//GLuint *textures);
	glBindTexture(
		GL_TEXTURE_2D, //GLenum target, 
		m_textures[0]);       //GLuint texture)
	texFromBPM(_fileName0 , 0x00, 0xff, 0x00);
	
	glBindTexture(
		GL_TEXTURE_2D, //GLenum target, 
		m_textures[1]);       //GLuint texture)
	texFromBPM(_fileName1, 0x00, 0xff, 0x00);

	m_size = _size;
	m_position = _position;
	m_animation = 0;

	return 0;
}

void Invader::update() {
	++m_animation %= INVADER_ANIIMATON_MAX;
	m_position += Invader::m_speed;
}
void Invader::draw() {
	glBindTexture(
		GL_TEXTURE_2D, //GLenum target, 
		m_textures[m_animation]);
	glColor3ub(0xff, 0xff, 0xff);
	Rect::draw();

}
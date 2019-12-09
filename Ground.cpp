#include "Ground.h"
#include "Header.h"
#include "glut.h"


int Ground::init() {
	m_position = vec2(0, SCREEN_HEIGHT - 8 - 1);
	m_size = vec2(SCREEN_WIDTH, 1);

	for (int i = 0; i < SCREEN_WIDTH; i++)
		m_pixels[i] = 0xff;
	glGenTextures(
		1,          //GLsizei n, 
		&m_texture);//GLuint *textures);
	glBindTexture(
		GL_TEXTURE_2D, //GLenum target, 
		m_texture);       //GLuint texture)

	

	glTexParameteri(
		GL_TEXTURE_2D,//GLenum target, 
		GL_TEXTURE_MAG_FILTER,//GLenum pname, 
		GL_NEAREST);	//GLint param);
	glTexParameteri(
		GL_TEXTURE_2D,//GLenum target, 
		GL_TEXTURE_MIN_FILTER,//GLenum pname, 
		GL_NEAREST);	//GLint param);

	glTexParameteri(
		GL_TEXTURE_2D,//GLenum target, 
		GL_TEXTURE_WRAP_S,//GLenum pname, 
		GL_CLAMP);	//GLint param);

	glTexParameteri(
		GL_TEXTURE_2D,//GLenum target, 
		GL_TEXTURE_WRAP_T,//GLenum pname, 
		GL_CLAMP);
	return 0;

}
void Ground::draw() {
	glBindTexture(
		GL_TEXTURE_2D, //GLenum target, 
		m_texture);       //GLuint texture)

	glTexImage2D(
		GL_TEXTURE_2D,	//GLenum target,
		0,	//GLint level, 
		GL_ALPHA,	//GLint internalformat, 
		SCREEN_WIDTH,	//GLsizei width, 
		1,	//GLsizei height, 
		0,	//GLint border, 
		GL_ALPHA,	//GLenum format, 
		GL_UNSIGNED_BYTE,	//GLenum type, 
		m_pixels);//const GLvoid * pixels););
	setColorWithPosition(m_position);
	Rect::draw();

}
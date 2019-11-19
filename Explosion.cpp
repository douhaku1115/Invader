#include "Explosion.h"
#include "tex.h"
#include  "glut.h"

int Explosion::init(const char* _fileName, vec2 const& _size,
	unsigned char _red,
	unsigned char _green,
	unsigned char _blue) {

	glGenTextures(
		1,          //GLsizei n, 
		&m_texture);//GLuint *textures);
	glBindTexture(
		GL_TEXTURE_2D, //GLenum target, 
		m_texture);       //GLuint texture)

	//texFromBPM("textures\player_bullet_explosion.bmp", 0x00, 0xff, 0x00);
	texFromBPM(_fileName, 0x00, 0xff, 0x00);


	m_size = _size;
	m_color[0] = _red;
	m_color[1] = _green;
	m_color[2] = _blue;

	return 0;
		
}

void Explosion::start(vec2 const& _position) {
	m_position = _position;
	m_countLeft = EXPLOTION_COUNT_MAX;
}
void Explosion::update() {
	if (m_countLeft > 0)
		m_countLeft--;

}
void Explosion::draw() {
	if (m_countLeft <= 0)
		return;
	glBindTexture(
		GL_TEXTURE_2D, //GLenum target, 
		m_texture);
		glColor3ubv(m_color);//(const GLubyte *v)
	Rect::draw();

}
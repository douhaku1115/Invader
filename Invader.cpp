#include "Invader.h"
#include "tex.h"
#include "glut.h"
#include "Header.h"

vec2 Invader::m_speed = vec2(INVADER_SPEED, 0);
vec2 Invader::m_nextSpeed = Invader::m_speed;
int Invader::m_current ;

Invader g_invaders[INVADER_ROW_MAX][INVADER_COLUMN_MAX];

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
 int Invader::initAll() {
	 g_invaders[0][0].init(
		 "textures\\invader0-0.bmp",
		 "textures\\invader0-1.bmp",
		 vec2(12, 8));
	 for (int i = 0; i < 2; i++)
		 for (int j = 0; j < INVADER_COLUMN_MAX; j++)
			 g_invaders[i][j] = g_invaders[0][0];
	
	 g_invaders[2][0].init(
		 "textures\\invader1-0.bmp",
		 "textures\\invader1-1.bmp",
		 vec2(11, 8));
	 for (int i = 2; i < 4; i++)
		 for (int j = 0; j < INVADER_COLUMN_MAX; j++)
			 g_invaders[i][j] = g_invaders[2][0];

	 g_invaders[4][0].init(
		 "textures\\invader2-0.bmp",
		 "textures\\invader2-1.bmp",
		 vec2(8, 8));
	 for (int j = 0; j < INVADER_COLUMN_MAX; j++)
	 g_invaders[4][j] = g_invaders[4][0];


	 for (int i=0;i<INVADER_ROW_MAX;i++)
		 for (int j = 0; j < INVADER_COLUMN_MAX; j++) {
			  g_invaders[i][j].m_position = vec2(
				 j * 8 * 2-(g_invaders[i][j].m_size.x-8)/2,
				 8*12-8*i*2
			 );
		 }
	return 0;

}
void Invader::update() {
	++m_animation %= INVADER_ANIIMATON_MAX;
	m_position += Invader::m_speed;

	if ((m_position.x >= SCREEN_WIDTH - m_size.x - INVADER_SPEED) &&
		(m_speed.x > 0)) {
		m_nextSpeed = vec2(-INVADER_SPEED, 8);
	}
	if ((m_position.x < INVADER_SPEED) && (m_speed.x < 0))

		m_nextSpeed = vec2(INVADER_SPEED, 8);
}
void Invader::updateAll() {
	while (
		(m_current >= INVADER_MAX)
		|| g_invaders[m_current / INVADER_COLUMN_MAX][m_current % INVADER_COLUMN_MAX].m_dead)
	{
		if (m_current >= INVADER_MAX) {
			m_current = 0;
			m_speed = m_nextSpeed;
			m_nextSpeed.y = 0;
		}
		else
			m_current++;
		
	}
	g_invaders[m_current / INVADER_COLUMN_MAX][m_current % INVADER_COLUMN_MAX].update();
	
	
	m_current++;
};
void Invader::draw() {
	if (m_dead)
		return;         //Ž€‚ñ‚Å‚¢‚½‚ç•`‰æ‚µ‚È‚¢
	glBindTexture(
		GL_TEXTURE_2D, //GLenum target, 
		m_textures[m_animation]);
	glColor3ub(0xff, 0xff, 0xff);
	Rect::draw();

}
 void Invader::drawAll() {
	 for (int i = 0; i < INVADER_ROW_MAX; i++)
		 for (int j = 0; j < INVADER_COLUMN_MAX; j++)
			 g_invaders[i][j].draw();

}
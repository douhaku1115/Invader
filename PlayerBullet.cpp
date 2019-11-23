#include "PlayerBullet.h"
#include "tex.h"
#include "Header.h"
#include "glut.h"
#include "audio.h"

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

	for (int i=0;i<INVADER_ROW_MAX;i++)
		for (int j=0;j<INVADER_COLUMN_MAX;j++)
			if ((!g_invaders[i][j].m_dead)
				&& (g_invaders[i][j].intersect(m_position))) {

				audioStop(AUDIO_CHANNEL_PULSE0);
				audioWaveform(AUDIO_CHANNEL_PULSE0, AUDIO_WAVEFORM_PULSE_50);
				audioFreq(AUDIO_CHANNEL_PULSE0, 440*1.5 );
				audioDecay(AUDIO_CHANNEL_PULSE0, .8f);
				audioSweep(AUDIO_CHANNEL_PULSE0, .9f, 440/2);
				audioPlay(AUDIO_CHANNEL_PULSE0);

				g_invaders[i][j].m_dead = true;
				m_enable = false;
				g_invaderExplosion.start(
					g_invaders[i][j].m_position-(g_invaderExplosion.m_size-g_invaders[i][j].m_size)/2.f
				);
			}
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
#include <stdio.h>
#include "PlayerExplosion.h"
#include "tex.h"
#include "glut.h"
#include "Header.h"
#include  "audio.h"

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
	if (m_countLeft <= 0)
		return;
	m_countLeft--;
}
void PlayerExplosion::draw() {
	if (m_countLeft <= 0)
		return;

	glBindTexture(
		GL_TEXTURE_2D, //GLenum target, 
		m_textures[m_countLeft/8%PLAYER_EXPLOSION_ANIMATION_MAX]);
	setColorWithPosition(m_position);

	Rect::draw();
	
}
void PlayerExplosion::start(vec2 const& _position) {
	audioStop(AUDIO_CHANNEL_NOISE);
	audioFreq(AUDIO_CHANNEL_NOISE, audioIndexToFreq(13));
	//audioSweep(AUDIO_CHANNEL_NOISE, .9f, audioIndexToFreq(15));
	audioDecay(AUDIO_CHANNEL_NOISE, .975f);
	audioPlay(AUDIO_CHANNEL_NOISE);

	
	m_position = _position;
	m_countLeft = PLAYER_EXPLOSION_COUNT_MAX;


}
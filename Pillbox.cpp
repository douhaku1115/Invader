#include <Windows.h>
#include "Pillbox.h"
#include "glut.h"
#include "Header.h"

int alphaTexFromBmp(unsigned char *_buffer,const char* _fileName) {
	FILE* pFile;
	fopen_s(&pFile, _fileName, "rb");
	if (pFile == nullptr) {
		printf("%s open failed!\n", _fileName);
		return 1;
	}
	printf("%s open \n", _fileName);
	BITMAPFILEHEADER bf;
	fread(&bf, sizeof(BITMAPFILEHEADER), 1, pFile);
	printf("bfSize :%d\n", bf.bfSize);
	BITMAPINFOHEADER bi;
	fread(&bi, sizeof(BITMAPINFOHEADER), 1, pFile);
	printf("biWidth: %d biHeight : %d\n", bi.biWidth, bi.biHeight);
	printf("biCount: %d ", bi.biBitCount);

	int padding = 4 - bi.biWidth * (bi.biBitCount / 8) % 4 % 4;

	for (int i = 0; i < bi.biHeight; i++) {
		for (int j = 0; j < bi.biWidth; j++) {
			fread(&_buffer[i*bi.biWidth+j], 1, 1, pFile);
			fseek(pFile, 2, SEEK_CUR);
		}
		fseek(pFile, 2, SEEK_CUR);
	}
	return 0;


}
int Pillbox::init() {
	m_size = vec2(PILLBOX_WIDTH, PILLBOX_HEIGHT);
	
	glGenTextures(
		1,          //GLsizei n, 
		&m_texture);//GLuint *textures);
	glBindTexture(
		GL_TEXTURE_2D, //GLenum target, 
		m_texture);       //GLuint texture)
	alphaTexFromBmp(*m_pixels, "textures\\pillbox.bmp");
	return 0;

}
void Pillbox::draw() {
	
	glDisable(GL_TEXTURE_2D);
	setColorWithPosition(m_position);
Rect::draw();
	glEnable(GL_TEXTURE_2D);
}
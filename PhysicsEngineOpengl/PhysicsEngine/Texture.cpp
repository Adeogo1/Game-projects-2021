
#include "Texture.h"
//#include <SOIL2.h>


Texture::Texture()
{
	m_Height = m_Width = m_TextureID = 0;
}

bool Texture::Load(const string& _filename)
{
	int channel = 0;

	unsigned char* image = SOIL_load_image(
		_filename.c_str(), // name of file
		&m_Width, //Stores width
		&m_Height,//Stores height
		&channel, SOIL_LOAD_AUTO //type of image file or auto for any
	);
	if (image == nullptr)
	{
		SDL_Log("Image not loaded: %s", SOIL_last_result());
		return false;
	}

	int format = GL_RGB;
	if (channel == 4)
	{
		format = GL_RGBA;
	}

	glGenTextures(1, &m_TextureID);
	glBindTexture(GL_TEXTURE_2D, m_TextureID);
	glTexImage2D(
		GL_TEXTURE_2D, //Texture Target
		0, // Level of detail (for now, assume 0)
		format, //color format Opengl should use
		m_Width, //width of texture
		m_Height,//height of texture
		0,// border - this value must be 0
		format,// colour format of input data
		GL_UNSIGNED_BYTE,// bit depth of input data
		image
	);

	SOIL_free_image_data(image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;
	
}

void Texture::Unload()
{
	glDeleteTextures(1, &m_TextureID);
}

void Texture::SetActive()
{
	glBindTexture(GL_TEXTURE_2D, m_TextureID);
}

Texture::~Texture()
{
}
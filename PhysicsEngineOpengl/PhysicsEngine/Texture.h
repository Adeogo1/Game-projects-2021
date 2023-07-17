#pragma once
#include "SOIL2/SOIL2.h"
#include "RepeatedIncludes.h"



class Texture
{
public:
	Texture();

	bool Load(const string& _filename);
	void Unload();

	void SetActive();

	int GetWidth()const { return m_Width; }
	int GetHeight()const { return m_Height; }


	~Texture();

private:
	//Opengl ID of this texture
	unsigned int m_TextureID;

	//width/height of the text
	int m_Width;
	int m_Height;

};




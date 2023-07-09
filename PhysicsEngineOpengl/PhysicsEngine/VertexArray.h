#pragma once
#include <glew.h>
#include "RepeatedIncludes.h"



class VertexArray
{
public:
	VertexArray(const float * _verts, unsigned int numVertices, const unsigned int* _indices, unsigned int numIndices);
	~VertexArray();

	//Activate this vertex array(so we can draw it)
	void SetActive();

	unsigned int GetNumIndices() const { return m_NumIndices; }
	unsigned int GetNumVerts() const { return m_NumVerts; }


private:

	//How many vertices in the vertex buffer?
	unsigned int  m_NumVerts;

	//how many indices in the index buffer
	unsigned int m_NumIndices;

	//opengl ID of the vertex buffer
	unsigned int m_VertexBuffer;

	//opengl ID of the index buffer
	unsigned int m_IndexBuffer;

	//opengl ID of the vertex array object
	unsigned int m_VertexArray;
};



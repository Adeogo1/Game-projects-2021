#include "VertexArray.h"


VertexArray::VertexArray(const float* _verts, unsigned int numVertices, const unsigned int* _indices, unsigned int numIndices)
{
	glGenVertexArrays(1, &m_VertexArray);
	glBindVertexArray(m_VertexArray);
	glGenBuffers(1, &m_VertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);

	glBufferData(
		GL_ARRAY_BUFFER, // The active buffer type to write to
		numVertices * 3 * sizeof(float), //Number of bytes to copy
		_verts,// Source to copy from (pointer)
		GL_STATIC_DRAW // How will we use this data?
		);
}

VertexArray::~VertexArray()
{
}


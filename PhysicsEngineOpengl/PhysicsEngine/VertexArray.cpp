#include "VertexArray.h"


VertexArray::VertexArray(const float* _verts, unsigned int numVertices, const unsigned int* _indices, unsigned int numIndices) : m_NumVerts(numVertices), m_NumIndices(numIndices)
{
	//glGenVertexArrays(1, &m_VertexArray);
	//glBindVertexArray(m_VertexArray);
	//glGenBuffers(1, &m_VertexBuffer);
	//glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);

	//glBufferData(
	//	GL_ARRAY_BUFFER, // The active buffer type to write to
	//	numVertices * 3 * sizeof(float), //Number of bytes to copy
	//	_verts,// Source to copy from (pointer)
	//	GL_STATIC_DRAW // How will we use this data?
	//	);

	////INDEX BUFFER
	//glGenBuffers(1, &m_IndexBuffer);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);
	//glBufferData(
	//	GL_ELEMENT_ARRAY_BUFFER, // Index buffer
	//	m_NumIndices * sizeof(unsigned int), // Size of data
	//	_indices,
	//	GL_STATIC_DRAW
	//	);
	//glEnableVertexAttribArray(0);

	//glVertexAttribPointer(
	//	0, // Attribute index (0 for first one)
	//	3,// Number of components (3 in this case)
	//	GL_FLOAT, // Type of the components
	//	GL_FALSE, // (Only used for integral types)
	//	sizeof(float) * 3, // Stride (usually size of each vertex)
	//	0// Offset from start of vertex to this attribute
	//);

	glGenVertexArrays(1, &m_VertexArray);
	glBindVertexArray(m_VertexArray);

	// Create vertex buffer
	glGenBuffers(1, &m_VertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, numVertices * 5 * sizeof(float), _verts, GL_STATIC_DRAW);

	// Create index buffer
	glGenBuffers(1, &m_IndexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(unsigned int), _indices, GL_STATIC_DRAW);

	// Specify the vertex attributes
	// (For now, assume one vertex format)
	// Position is 3 floats starting at offset 0
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, 0);

}

VertexArray::~VertexArray()
{
	glDeleteBuffers(1, &m_VertexBuffer);
	glDeleteBuffers(1, &m_IndexBuffer);
	glDeleteVertexArrays(1, &m_VertexArray);

}

void VertexArray::SetActive()
{
	glBindVertexArray(m_VertexArray);
}


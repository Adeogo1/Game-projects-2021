#pragma once
#include "RepeatedIncludes.h"



class Shader
{
public:
	Shader();
	~Shader();

	/// Load the vertex/fragment shaders with the given names
	bool Load(const string& _vertName, const string& _fragName);

	//Set this as the active shader program
	void SetActive();

	void Unload();



private:
	//Tries to compile the specified shader
	bool CompileShader(const string& _fileName, GLenum _shaderType, GLuint& outShader);

	//Tests whether shader compiled successfully
	bool IsCompiled(GLuint _shader);

	//tests whether vertex/fragment programs link
	bool IsValidProgram();

	//store the shader object IDs

	GLuint m_VertexShader;
	GLuint m_FragShader;
	GLuint m_ShaderProgram;

};



#include "Shader.h"



Shader::Shader()
{
	m_ShaderProgram =
		m_VertexShader = m_FragShader = 0;
}

Shader::~Shader()
{
}

bool Shader::Load(const string& _vertName, const string& _fragName)
{
	// Compile vertex and pixel shaders
	if (!CompileShader(_vertName,
		GL_VERTEX_SHADER,
		m_VertexShader) ||
		!CompileShader(_fragName,
			GL_FRAGMENT_SHADER,
			m_FragShader))
	{
		return false;
	}

	// Now create a shader program that
	// links together the vertex/frag shaders
	m_ShaderProgram = glCreateProgram();
	glAttachShader(m_ShaderProgram, m_VertexShader);
	glAttachShader(m_ShaderProgram, m_FragShader);
	glLinkProgram(m_ShaderProgram);

	// Verify that the program linked successfully
	if (!IsValidProgram())
	{
		return false;
	}

	return true;
}

void Shader::SetMatrixUniform(const char* _name, const Matrix4& matrix)
{
	//find the uniform by this name
	GLuint loc = glGetUniformLocation(m_ShaderProgram, _name);

	//send the matrix dat to the uniform
	glUniformMatrix4fv(loc, 1, GL_TRUE, matrix.GetAsFloatPtr());
}

void Shader::SetActive()
{
	glUseProgram(m_ShaderProgram);
}

void Shader::Unload()
{
	glDeleteProgram(m_ShaderProgram);
	glDeleteShader(m_VertexShader);
	glDeleteShader(m_FragShader);
}

bool Shader::CompileShader(const string& _fileName, GLenum _shaderType, GLuint& outShader)
{
	// Open file
	std::ifstream shaderFile(_fileName);
	if (shaderFile.is_open())
	{
		// Read all the text into a string
		std::stringstream sstream;
		sstream << shaderFile.rdbuf();
		std::string contents = sstream.str();
		const char* contentsChar = contents.c_str();

		// Create a shader of the specified type
		outShader = glCreateShader(_shaderType);
		// Set the source characters and try to compile
		glShaderSource(outShader, 1, &(contentsChar), nullptr);
		glCompileShader(outShader);

		if (!IsCompiled(outShader))
		{
			SDL_Log("Failed to compile shader %s", _fileName.c_str());
			return false;
		}
	}
	else
	{
		SDL_Log("Shader file not found: %s", _fileName.c_str());
		return false;
	}

	return true;
}

bool Shader::IsCompiled(GLuint _shader)
{
	GLint status;

	//Query the compile status
	glGetShaderiv(_shader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{
		char buffer[512];
		memset(buffer, 0, 512);

		glGetShaderInfoLog(_shader, 511, nullptr, buffer);

		SDL_Log("GLSL Compile Failed: \n%s", buffer);

		return false;
	}
	return true;
}

bool Shader::IsValidProgram()
{
	GLint status;
	glGetProgramiv(m_ShaderProgram, GL_LINK_STATUS, &status);
	if (status != GL_TRUE)
	{
		char buffer[512];
		memset(buffer, 0, 512);

		glGetProgramInfoLog(m_ShaderProgram, 511, nullptr, buffer);

		SDL_Log("Program is not Valid: \n%s", buffer);

		return false;
	}
	return true;
}

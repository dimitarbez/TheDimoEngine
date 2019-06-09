#pragma once

#include <string>
#include <GL/glew.h>

class Shader
{
public:
	Shader(const std::string& fileName);

	void Bind();

	~Shader();

private:
	static const unsigned int NUM_SHADERS = 2;
	unsigned int m_program = 0;
	unsigned int m_shaders[NUM_SHADERS];
};


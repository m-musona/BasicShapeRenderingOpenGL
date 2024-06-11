#pragma once
#include <glm.hpp>
#include <string>

class Shader
{
public:
	Shader(const char* vertexShaderSource, const char* fragmentShaderSource);
	~Shader();
	void Compile();
	void Link();
	void UseProgram();
	void DeleteProgram();
	unsigned int GetShaderProgram() const { return mShaderProgram; }

	// Uniforms
	void SetUniformFloat4(std::string name, glm::vec4 value);
	void SetUniformFloat3(std::string name, glm::vec3 value);
	void SetUniformFloat(std::string name, float value);
	void SetUniformInt(std::string name, int value);
private:
	unsigned int mVertexShader, mFragmentShader;
	unsigned int mShaderProgram;

};
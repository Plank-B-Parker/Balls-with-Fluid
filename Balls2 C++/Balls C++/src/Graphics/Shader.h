#pragma once
#define SHADER_H
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>

struct vec2f;

class Shader
{
private:
	unsigned int programID;
	unsigned int vertexID;
	unsigned int fragID;

	const char* vertexShader;
	const char* fragShader;

	void ParseShader(const char* vertexPath, const char* fragPath);
public:
	Shader(const char* vertexPath, const char* fragmentPath);
	void use() const;
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setVec2f(const std::string& name, vec2f value) const;
};

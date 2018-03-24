#pragma once
#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#define GLEW_STATIC
#include "GL\glew.h" //����glew����ȡ���еı���OpenGLͷ�ļ�

class Shader
{
public:
	// ����ID
	GLuint Program;
	// ��������ȡ��������ɫ��
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	~Shader();
	// ʹ�ó���
	void Use();
};

#endif

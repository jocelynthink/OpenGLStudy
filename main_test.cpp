///*
//* ����������
//*/
//
//// GLEW
//#define GLEW_STATIC
//#include "GL\glew.h"
//// GLFW
//#include "GLFW\glfw3.h"
//#include <iostream>
//
//const GLuint  WIDTH = 800, HEIGHT = 600;
//void key_callback(GLFWwindow * window, int key, int scancode, int action, int mode) {
//	//�û�����ESC������������window���ڵ�WindowShouldClose����Ϊtrue
//	//�ر�Ӧ�ó���
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
//		glfwSetWindowShouldClose(window, GL_TRUE);
//	}
//}
//
//const GLchar* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 position;\n"
//"layout (location = 1) in vec3 color;\n"
//"out vec3 vertexColor;\n"
//"void main()\n"
//"{\n"
//"	gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
//"	vertexColor = color;\n"
//"}";
//
//const GLchar* fragementShaderSource = "#version 330 core\n"
//"in vec3 vertexColor;\n"
//"out vec4 color;\n"
////"uniform vec4 ourColor;"
//"void main()\n"
//"{\n"
//"	color = vec4(vertexColor,1.0f);\n"
//"}";
//int main_test() {
//	std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;
//	glfwInit();
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
//	if (window == nullptr) {
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	glewExperimental = GL_TRUE;
//	if (glewInit() != GLEW_OK) {
//		std::cout << "failed to initialize GLEW" << std::endl;
//		return -1;
//	}
//	int width, height;
//	glfwGetFramebufferSize(window, &width, &height);
//	glfwSetKeyCallback(window, key_callback);
//	glViewport(0, 0, width, height);
//
//	// Build and complite shader program
//	// ������ɫ��
//	GLuint vertexShader;
//	vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//	// ����Ƿ����ɹ�
//	GLint success;
//	GLchar infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	// Ƭ����ɫ��
//	GLuint fragmentShader;
//	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragementShaderSource, NULL);
//	glCompileShader(fragmentShader);
//	// �����ɫ���Ƿ����ɹ�
//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//	// ���Ӷ����ɫ��
//	GLuint shaderProgram;
//	shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//	}
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//
//	//GLfloat vertices[] = {
//	//	// ��һ��������
//	//	0.5f, 0.5f, -0.0f, //���Ͻ�
//	//	0.5f, -0.5f, 0.0f, //���½�
//	//	-0.5f, -0.5f, 0.0f, //���Ͻ�
//	//	-1.0f, -0.5f, 0.0f, //���½�
//	//	-1.0f, 0.5f, 0.0f
//	//};
//	GLfloat vertices[] = {
//		//λ��               //��ɫ
//		 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, //����
//		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, //����
//		 0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f  //����
//	};
//
//	GLuint indices[] = {
//		0, 1, 2, //��һ��������
//		2, 3, 4 // �ڶ���������
//	};
//
//	// �������㻺�����VBO
//	GLuint VBO;
//	glGenBuffers(1, &VBO);
//	// ���������������VAO
//	GLuint VAO;
//	glGenVertexArrays(1, &VAO);
//
//	// ���������������EBO
//	GLuint EBO;
//	glGenBuffers(1, &EBO);
//
//	// ��VAO, // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
//	glBindVertexArray(VAO);
//	// 0. ���ƶ������鵽�����й�OpenGLʹ��
//	// ��VBO
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	// ��EBO
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	// 1. ���ö���ָ��
//	// λ������
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	// ��ɫ����
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//	// Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	// Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)
//	glBindVertexArray(0);
//
//	GLint nrAttributes;
//	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
//	std::cout << "maximum nr of vertex attributes supported:" << nrAttributes << std::endl;
//	
//	while (!glfwWindowShouldClose(window)) {
//		// ����¼�
//		glfwPollEvents();
//		// ��Ⱦָ��
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);//��һ��״̬���ú���
//		glClear(GL_COLOR_BUFFER_BIT);//��һ��״̬Ӧ�õĺ���
//
//		// 2. ��Ⱦһ������ʱ��Ҫ�õ���ɫ������
//		// ������ɫ������
//		glUseProgram(shaderProgram);
//		//����uniform��ɫ
//		//GLfloat timeValue = glfwGetTime();
//		//GLfloat greenValue = (sin(timeValue) / 2) + 0.5;
//		//GLint vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
//		//glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
//		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//		// 3. ��������
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//		glBindVertexArray(0);
//
//		// ��������		
//		glfwSwapBuffers(window);
//	}
//
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &EBO);
//	glfwTerminate();
//	return 0;
//}

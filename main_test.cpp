///*
//* 绘制三角形
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
//	//用户按下ESC键，我们设置window窗口的WindowShouldClose属性为true
//	//关闭应用程序
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
//	// 顶点着色器
//	GLuint vertexShader;
//	vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//	// 检测是否编译成功
//	GLint success;
//	GLchar infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	// 片段着色器
//	GLuint fragmentShader;
//	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragementShaderSource, NULL);
//	glCompileShader(fragmentShader);
//	// 检测着色器是否编译成功
//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//	// 链接多个着色器
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
//	//	// 第一个三角形
//	//	0.5f, 0.5f, -0.0f, //右上角
//	//	0.5f, -0.5f, 0.0f, //右下角
//	//	-0.5f, -0.5f, 0.0f, //左上角
//	//	-1.0f, -0.5f, 0.0f, //左下角
//	//	-1.0f, 0.5f, 0.0f
//	//};
//	GLfloat vertices[] = {
//		//位置               //颜色
//		 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, //右下
//		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, //左下
//		 0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f  //顶部
//	};
//
//	GLuint indices[] = {
//		0, 1, 2, //第一个三角形
//		2, 3, 4 // 第二个三角形
//	};
//
//	// 创建顶点缓存对象VBO
//	GLuint VBO;
//	glGenBuffers(1, &VBO);
//	// 创建顶点数组对象VAO
//	GLuint VAO;
//	glGenVertexArrays(1, &VAO);
//
//	// 创建索引缓存对象EBO
//	GLuint EBO;
//	glGenBuffers(1, &EBO);
//
//	// 绑定VAO, // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
//	glBindVertexArray(VAO);
//	// 0. 复制顶点数组到缓冲中供OpenGL使用
//	// 绑定VBO
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	// 绑定EBO
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	// 1. 设置顶点指针
//	// 位置属性
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	// 颜色属性
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
//		// 检查事件
//		glfwPollEvents();
//		// 渲染指令
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);//是一个状态设置函数
//		glClear(GL_COLOR_BUFFER_BIT);//是一个状态应用的函数
//
//		// 2. 渲染一个物体时，要用的着色器程序
//		// 激活着色器对象
//		glUseProgram(shaderProgram);
//		//更新uniform颜色
//		//GLfloat timeValue = glfwGetTime();
//		//GLfloat greenValue = (sin(timeValue) / 2) + 0.5;
//		//GLint vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
//		//glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
//		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//		// 3. 绘制物体
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//		glBindVertexArray(0);
//
//		// 交换缓冲		
//		glfwSwapBuffers(window);
//	}
//
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &EBO);
//	glfwTerminate();
//	return 0;
//}

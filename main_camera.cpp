//#include "Shader.h"
//#include "GLFW\glfw3.h"
//#include "soil\SOIL.h"
//#include <iostream>
//
//#include "glm\glm.hpp"
//#include "glm\gtc\matrix_transform.hpp"
//#include "glm\gtc\type_ptr.hpp"
//
//// functin prototypes
//void do_movement();
//void key_callback(GLFWwindow * window, int key, int scancode, int action, int mode);
//void mouse_callback(GLFWwindow *window, double xpos, double ypos);
//void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);
//
//const GLuint  WIDTH = 800, HEIGHT = 600;
//
//glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
//glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
//glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//
//GLfloat mixValue = 0.2f;
//
//// deltatime
//GLfloat deltaTime = 0.0f;
//GLfloat lastFrame = 0.0f;
//// camera
//GLfloat yaw = -90.0f;
//GLfloat pitch = 0.0f;
//GLfloat lastX = 400, lastY = 300;
//bool keys[1024];
//bool firstMouse = true;
//GLfloat aspect = 45.0f;
//
//int main() {
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
//	glfwSetCursorPosCallback(window, mouse_callback);
//	glfwSetScrollCallback(window, scroll_callback);
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//	glViewport(0, 0, width, height);
//
//	Shader ourShader("./shader.vs", "./shader.frag");
//
//	// 顶点位置坐标+颜色坐标
//	//GLfloat vertices[] = {
//	//	//位置               //颜色            //纹理坐标
//	//	 0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  1.0f, 1.0f, //右上
//	//	 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  1.0f, 0.0f, //右下
//	//	-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,  0.0f, 0.0f, //左下
//	//	-0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f,  0.0f, 1.0f, //左上
//	//};
//
//	GLfloat vertices[] = {
//		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//		0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//	};
//	
//	GLuint indices[] = {
//		0, 1, 3, //第一个三角形
//		1, 2, 3, // 第二个三角形
//	};
//
//	GLuint VBO, VAO, EBO;
//	glGenBuffers(1, &VBO);// 创建顶点缓存对象VBO
//	glGenVertexArrays(1, &VAO);// 创建顶点数组对象VAO
//	glGenBuffers(1, &EBO);// 创建索引缓存对象EBO
//	
//	// 绑定VAO, // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
//	glBindVertexArray(VAO);
//	// 0. 复制顶点数组到缓冲中供OpenGL使用
//	// 绑定VBO
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	// 绑定EBO
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//	
//	// 设置顶点指针
//	// 位置属性
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	// 颜色属性
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//	// 纹理属性
//	//glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
//	//glEnableVertexAttribArray(2);
//
//	// Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	// Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)
//	glBindVertexArray(0);
//
//	// 创建纹理1
//	GLuint texture1;
//	glGenTextures(1, &texture1);
//	// 绑定纹理
//	glBindTexture(GL_TEXTURE_2D, texture1);
//	// 为当前绑定的纹理对象设置环绕、过滤方式
//	// 设置纹理的环绕方式
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	//float borderColor[] = { 1.0f, 0.0f, 0.0f, 1.0f };
//	//glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
//	// 设置纹理的过滤方式
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	// 加载并生成纹理
//	int texWidth, texHeight;
//	unsigned char* image = SOIL_load_image("container.jpg", &texWidth, &texHeight, 0, SOIL_LOAD_RGB);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
//	glGenerateMipmap(GL_TEXTURE_2D);
//	SOIL_free_image_data(image);
//	glBindTexture(GL_TEXTURE_2D, 0);
//
//	// 创建纹理2
//	GLuint texture2;
//	glGenTextures(1, &texture2);
//	// 绑定纹理
//	glBindTexture(GL_TEXTURE_2D, texture2);
//	// 为当前绑定的纹理对象设置环绕、过滤方式
//	// 设置纹理的环绕方式
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	// 设置纹理的过滤方式
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	// 加载并生成纹理
//	image = SOIL_load_image("awesomeface.png", &texWidth, &texHeight, 0, SOIL_LOAD_RGB);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
//	glGenerateMipmap(GL_TEXTURE_2D);
//	SOIL_free_image_data(image);
//	glBindTexture(GL_TEXTURE_2D, 0);
//
//	glEnable(GL_DEPTH_TEST);
//
//	glm::vec3 cubePositions[] = {
//		glm::vec3(0.0f, 0.0f, 0.0f),
//		glm::vec3(2.0f,  5.0f, -15.0f),
//		glm::vec3(-1.5f, -2.2f, -2.5f),
//		glm::vec3(-3.8f, -2.0f, -12.3f),
//		glm::vec3(2.4f, -0.4f, -3.5f),
//		glm::vec3(-1.7f,  3.0f, -7.5f),
//		glm::vec3(1.3f, -2.0f, -2.5f),
//		glm::vec3(1.5f,  2.0f, -2.5f),
//		glm::vec3(1.5f,  0.2f, -1.5f),
//		glm::vec3(-1.3f,  1.0f, -1.5f)
//	};
//
//	while (!glfwWindowShouldClose(window)) {
//		// 检查事件
//		glfwPollEvents();
//		GLfloat currentFrame = glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		do_movement();
//		// 渲染指令
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);//是一个状态设置函数
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//是一个状态应用的函数
//			
//		//glUniform1f(glGetUniformLocation(ourShader.Program, "xOffset"), 0.5f);
//		//更新uniform颜色
//		//GLfloat timeValue = glfwGetTime();
//		//GLfloat greenValue = (sin(timeValue) / 2) + 0.5;
//		//GLint vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
//		//glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
//		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//
//		// 使用纹理单元绑定纹理
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture1);
//		glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture1"), 0);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture2);
//		glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture2"), 1);
//
//		ourShader.Use();
//
//		// 3.  绘制物体
//		glm::mat4 trans;
//		//trans = glm::rotate(trans, (GLfloat)glfwGetTime() * 50.0f, glm::vec3(0.0f, 0.0f, 1.0f));
//		//trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
//		//glBindTexture(GL_TEXTURE_2D, texture1);
//		
//		// model maxtrix
//		
//		glm::mat4 view;
//		glm::mat4 projection;
//		//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -6.0f));
//		//GLfloat radius = 10.0f;
//		//GLfloat camX = sin(glfwGetTime()) * radius;
//		//GLfloat camZ = cos(glfwGetTime()) * radius;
//
//		//GLfloat radius = 10.0f;
//		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
//		projection = glm::perspective(aspect, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
//		GLint transformLoc = glGetUniformLocation(ourShader.Program, "view");
//		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(view));
//		transformLoc = glGetUniformLocation(ourShader.Program, "projection");
//		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(projection));
//		
//		glUniform1f(glGetUniformLocation(ourShader.Program, "mixValue"), mixValue);
//		glBindVertexArray(VAO);
//		for (GLuint i = 0; i < 10; i++) {
//			glm::mat4 model;
//			model = glm::translate(model, cubePositions[i]);
//			GLfloat angle = 20.0f * i;
//			//if (i % 4 == 0) {
//			//	angle = glfwGetTime() * 25.0f;
//			//}
//			model = glm::rotate(model, angle, glm::vec3(1.0f, 0.3f, 0.5f));
//			GLint transformLoc = glGetUniformLocation(ourShader.Program, "model");
//			glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(model));
//			
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
//		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//		//trans = glm::mat4();
//		//trans = glm::translate(trans, glm::vec3(-0.5f, 0.5f, 0.0f));
//		//GLfloat scaleAmount = sin(glfwGetTime());
//		//trans = glm::scale(trans, glm::vec3(scaleAmount, scaleAmount, scaleAmount));
//		//glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
//		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//		glBindVertexArray(0);
//
//		// 交换缓冲		
//		glfwSwapBuffers(window);
//	}
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &EBO);
//	glfwTerminate();
//	return 0;
//}
//
//void key_callback(GLFWwindow * window, int key, int scancode, int action, int mode) {
//	//用户按下ESC键，我们设置window窗口的WindowShouldClose属性为true
//	//关闭应用程序
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
//		glfwSetWindowShouldClose(window, GL_TRUE);
//	}
//	if (key == GLFW_KEY_UP && action == GLFW_PRESS) {
//		mixValue += 0.1f;
//		if (mixValue >= 1.0f) {
//			mixValue = 1.0f;
//		}
//	}
//	if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {
//		mixValue -= 0.1f;
//		if (mixValue <= 0.0f) {
//			mixValue = 0.0f;
//		}
//	}
//
//	if (action == GLFW_PRESS) {
//		keys[key] = true;
//	}
//	else if (action == GLFW_RELEASE) {
//		keys[key] = false;
//	}
//}
//
//void do_movement() {
//	GLfloat cameraSpeed = 5.0f * deltaTime;
//	if (keys[GLFW_KEY_W]) {
//		cameraPos += cameraSpeed * cameraFront;
//	}
//	if (keys[GLFW_KEY_S]) {
//		cameraPos -= cameraSpeed * cameraFront;
//	}
//	if (keys[GLFW_KEY_A]) {
//		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//	}
//	if (keys[GLFW_KEY_D]) {
//		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//	}
//}
//
//void mouse_callback(GLFWwindow *window, double xpos, double ypos) {
//	if (firstMouse) {
//		lastX = xpos;
//		lastY = ypos;
//		firstMouse = false;
//	}
//
//	GLfloat xoffset = xpos - lastX;
//	GLfloat yoffset = lastY - ypos;
//	lastX = xpos;
//	lastY = ypos;
//
//	GLfloat sensitivity = 0.05;
//	xoffset *= sensitivity;
//	yoffset *= sensitivity;
//
//	yaw += xoffset;
//	pitch += yoffset;
//
//	if (pitch > 89.0f) {
//		pitch = 89.0f;
//	}
//	if (pitch < -89.0f) {
//		pitch = -89.0f;
//	}
//	glm::vec3 front;
//	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
//	front.y = sin(glm::radians(pitch));
//	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
//	cameraFront = glm::normalize(front);
//}
//
//void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
//	if (aspect >= 1.0f && aspect <= 45.0f) {
//		aspect -= yoffset;
//	}
//	if (aspect <= 1.0f) {
//		aspect = 1.0f;
//	}
//	if (aspect >= 45.0f) {
//		aspect = 45.0f;
//	}
//}
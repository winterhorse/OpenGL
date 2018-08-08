//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//
//// set up vertex data
//float vertices[] = {
//	-0.5f, -0.5f, 0.0f,
//	0.5f, -0.5f, 0.0f,
//	0.0f, 0.5f, 0.0f
//};
//
//const char* vertexShaderSource =
//"#version 330 core                                    \n	"
//"layout(location = 2) in vec3 aPos;                  \n		"
//"void main(){\n												"
//"		gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);}\n\0	";
//
//const char* fragmentShaderSource =
//"#version 330 core                                \n "
//"out vec4 FragColor;                              \n "
//"uniform vec4 mColor;\n"
//"void main(){\n										 "
//"		FragColor = mColor;}\n ";
//
//// process the esc key evnet
//void processInput(GLFWwindow *window){
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
//		glfwSetWindowShouldClose(window, true);
//	}
//}
//
//// glfw: whenever the window size changed (by OS or user resize) this callback function executes
//// ---------------------------------------------------------------------------------------------
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	// make sure the viewport matches the new window dimensions; note that width and 
//	// height will be significantly larger than specified on retina displays.
//	glViewport(0, 0, width, height);
//}
//
//int main(){
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	// open GLFW window
//	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	// init GLEW 
//	glewExperimental = true;
//	if (glewInit() != GLEW_OK){
//		std::cout << "Failed";
//		glfwTerminate();
//		return -1;
//	}
//
//	/***********************************************************************************************
//	* creat and complie shader
//	***********************************************************************************************/
//	// Vertex shader
//	unsigned int vertexShader;
//	vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//
//	// check for vertex shader complie errors
//	int  success;
//	char infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	// fragment shader
//	unsigned int fragmentShader;
//	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//	glCompileShader(fragmentShader);
//
//	// check for fragment shader errors
//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::FRAGMET::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	// link shader
//	unsigned int shaderProgram;
//	shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//
//	// check for link errors
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//	}
//
//	// delete shader
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//
//	// configure vertex attributes
//
//	unsigned int VAO;
//	unsigned int VBO;
//
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//
//	// bin VAO(Vertex Array Object) first, then bind and set VBO(Vertex Buffer Object)
//	// and then configure vertex attributes
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//
//	// copy vertex data into the buffer's memory
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(2);
//
//	// render loop
//	while (!glfwWindowShouldClose(window))
//	{
//		// input
//		processInput(window);
//
//		// rendering commands here
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		// draw our first triangle	
//		double timeValve = glfwGetTime();
//		double greenColor = sin(timeValve / 2.0f) + 0.5f;
//		int vertexColorLocation = glGetUniformLocation(shaderProgram, "mColor");
//		glUseProgram(shaderProgram);
//		glUniform4f(vertexColorLocation, 0.5f, greenColor, 0.5f, 1.0f);
//
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		// check and call events and swap the buffers		 
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	// delete buffers
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//
//	glfwTerminate();
//
//	return 0;
//}

#include <GL/glew.h>
#include "Display.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "Transform.h"
#include "Camera.h"

#define SCR_WIDTH  800
#define SCR_HEIGHT 600

int main(int argc, char** argv){

	Display display(800, 600, "OpenGLTutorial");
	Vertex vertices[] = {
		Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec2(0.0, 0.0)),
		Vertex(glm::vec3( 0.0f,  0.5f, 0.0f), glm::vec2(0.5, 1.0)),
		Vertex(glm::vec3( 0.5f, -0.5f, 0.0f), glm::vec2(1.0, 0.0))
	};

	GLuint indices[] = {0, 1, 2};

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));

	//Mesh mesh2("cube.obj"); 
	Mesh mesh2("monkey3.obj");
	//Mesh mesh2("plane3.obj"); 

	Shader shader("basicShader");
	Texture texture("bricks.jpg");

	Transform transform;

	Camera camera(glm::vec3(0.0, 0.0, -3.0), glm::radians(50.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.01f, 1000.0f);

	float counter = 0.0f;

	while (!display.IsClosed()){
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		float sinCounter = sinf(counter);

		//transform.GetPos()->x = sinCounter;
		//transform.GetPos()->z = sinCounter;

		transform.SetPos(glm::vec3(sinCounter, sinCounter, sinCounter));

		transform.SetRot(glm::vec3(sinCounter, sinCounter, sinCounter));

		//transform.SetScale(glm::vec3(sinCounter, sinCounter, sinCounter));
		//transform.GetScale()->y = sinCounter;
		//transform.GetScale()->z = sinCounter;

		//transform.GetRot()->x = sinCounter * 5;
		//transform.GetRot()->y = sinCounter * 5;

		shader.Bind();		
		texture.Bind();

		shader.Update(transform, camera);

		mesh2.Draw();	

		display.Update();

		counter += 0.0005f;
	}

	return 0;
}
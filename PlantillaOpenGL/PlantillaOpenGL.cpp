// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>

using namespace std;

float xTriangulo = 0.0f;
float yTriangulo = 0.0f;
float velocidad = 0.0f;

void dibujar();
void dibujarTriangulo();
void actualizar();
void teclado_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main()
{
	// Creamos una ventana
	GLFWwindow *window;

	// Si no se puede inicializar glfw, finalizamos la ejecucion
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	// Si se pudo iniciar GLFW, entonces inicializamos la ventana
	window = glfwCreateWindow(1024, 768, "Ventana", NULL, NULL);
	
	// Si no podemos iniciar la ventana, terminamos ejecucion
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//Establecemos el contexto
	glfwMakeContextCurrent(window);

	// Una vez establecido el contexto, activamos funciones modernas
	glewExperimental = true;
	GLenum errorGlew = glewInit();
	if (errorGlew != GLEW_OK) {
		cout << glewGetErrorString(errorGlew);
	}

	const GLubyte *versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL << std::endl;

	glfwSetKeyCallback(window, teclado_callback);

	//Ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		
		//Establecer region de dibujo
		glViewport(0, 0, 1024, 768);

		//Establece el color de borrado
		glClearColor(.23, 0.3, 0.3, 1);

		//Borramos
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		dibujar();
		dibujarTriangulo();

		//Cambiar los buffers
		glfwSwapBuffers(window);

		//Reconocer si hay entradas
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;
}

void dibujar()
{

}

void actualizar()
{

}

void dibujarTriangulo()
{
	glPushMatrix();

		//Transformaciones
		glTranslatef(xTriangulo, yTriangulo, 0);

		/*glRotatef(0, 0, 0, 0);
		glScalef(0,0,0);*/

		glBegin(GL_TRIANGLES);
			glColor3f(1.0f, 1.0f, 1.0f);
			glVertex3f(0.0f, 0.2f, 0.0f);
			glVertex3f(0.2f, -0.2f, 0.0f);
			glVertex3f(-0.2f, -0.2f, 0.0f);
		glEnd();
	glPopMatrix();
}

void teclado_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_RIGHT && action == GLFW_REPEAT)
	{
		velocidad += .05;
		xTriangulo = velocidad;
	}
	else if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
	{
		xTriangulo = .05;
	}

	if (key == GLFW_KEY_LEFT && action == GLFW_REPEAT)
	{
		velocidad -= .05;
		xTriangulo = velocidad;
	}
	else if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
	{
		xTriangulo = .05;
	}


	if (key == GLFW_KEY_UP && action == GLFW_REPEAT)
	{
		velocidad += .05; 
		yTriangulo = velocidad;
	}
	else if (key == GLFW_KEY_UP && action == GLFW_PRESS)
	{
		yTriangulo -= .05;
	}


	if (key == GLFW_KEY_DOWN && action == GLFW_REPEAT)
	{
		velocidad -= .05; 
		yTriangulo = velocidad;
	}
	else if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
	{

		yTriangulo = .05;
	}

}
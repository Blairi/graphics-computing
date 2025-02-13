#include <stdio.h>
#include <glew.h>
#include <glfw3.h>
//Dimensiones de la ventana
const int WIDTH = 800, HEIGHT = 600;

int main()
{
	//Inicialización de GLFW
	if (!glfwInit())
	{
		printf("Falló inicializar GLFW");
		glfwTerminate();
		return 1;
	}
	//Asignando variables de GLFW y propiedades de ventana
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//para solo usar el core profile de OpenGL y no tener retrocompatibilidad
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//CREAR VENTANA
	// diferente de nulo, quiero que sea en full-screen o si se usa mas de un monitor
	GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Practica 1: Introduccion a OpenGL", NULL, NULL);

	if (!mainWindow)
	{
		printf("Fallo en crearse la ventana con GLFW");
		glfwTerminate();
		return 1;
	}

	//Obtener tamaño de Buffer
	int BufferWidth, BufferHeight; // tamanio de memoria que se esta almacenando
	// modelo de color 24 bits, almacenando en memoria de 800 * 600 * 24 bits
	// si se redimensiona la venta, podemos leer el frame buffer
	glfwGetFramebufferSize(mainWindow, &BufferWidth, &BufferHeight);

	//asignar el contexto
	// el teclado y mouse se asignan a esa ventana
	glfwMakeContextCurrent(mainWindow);

	//permitir nuevas extensiones
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("Falló inicialización de GLEW");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	// Asignar valores de la ventana y coordenadas
	//Asignar Viewport

	// primer linea de codigo de OpenGL, posicionarse en el origen y las unidades de
	// medida que usamos, las adaptamos a los pixeles que se obtienen de buffer
	glViewport(0, 0, BufferWidth, BufferHeight);
	printf("Version de Opengl: %s \n",glGetString(GL_VERSION));
	printf("Marca: %s \n", glGetString(GL_VENDOR));
	printf("Renderer: %s \n", glGetString(GL_RENDERER));
	printf("Shaders: %s \n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	//Loop mientras no se cierra la ventana
	while (!glfwWindowShouldClose(mainWindow)) // se entra cada ciclo de reloj
	{
		//Recibir eventos del usuario
		glfwPollEvents();

		//Limpiar la ventana
		glClearColor(0.0f,1.0f,0.0f,1.0f); // RGBA
		glClear(GL_COLOR_BUFFER_BIT);

		// siempre es la ultima linea, ya que no veremos cambios
		glfwSwapBuffers(mainWindow);

	}


	return 0;
}
#include <iostream>
#include <GLFW/glfw3.h>
#include "Game.h"
using namespace std;

#pragma region glfw



//#pragma region ErrorCallback
//GLFWerrorfun glfwSetErrorCallback(GLFWerrorfun _cbfun);
//typedef void(*GLFWerrorfun)(int, const char*);
//
//void error_callback(int _error, const char* _description) {
//    fprintf(stderr, "Error: %s\n", _description);
//}
//#pragma endregion
//
//#pragma region InputCallback
////GLFWkeyfun glfwSetKeyCallback(GLFWwindow* _window, GLFWkeyfun _cbfun);
//typedef void(*GLFWkeyfun)(GLFWwindow*, int, int, int, int);
//void key_callback(GLFWwindow* _window, int _key, int _scancode, int _action, int _mods) {
//
//}
//
//#pragma endregion
//
//
//int main(void)
//{
//
//    glfwSetErrorCallback(error_callback);
//    //glfwSetKeyCallback(key_callback);
//
//    GLFWwindow* window;
//    
//
//    /* Initialize the library */
//    if (!glfwInit())
//        return -1;
//
//    /* Create a windowed mode window and its OpenGL context */
//    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
//    if (!window)
//    {
//        glfwTerminate();
//        return -1;
//    }
//
//    /* Make the window's context current */
//    glfwMakeContextCurrent(window);
//
//    /* Loop until the user closes the window */
//    while (!glfwWindowShouldClose(window))
//    {
//
//        //UpdateInput
//
//        //Update
//
//        //Draw
//
//        //Clear
//
//        //Draw
//
//        //emd Draw
//
//
//        /* Render here */
//        glClear(GL_COLOR_BUFFER_BIT);
//
//
//        glBegin(GL_TRIANGLES);
//        glVertex2f(-0.5f,-0.5f);
//        glVertex2f(0.0f,0.5f);
//        glVertex2f(0.5f,-0.5f);
//        glEnd();
//
//        /* Swap front and back buffers */
//        glfwSwapBuffers(window);
//
//        /* Poll for and process events */
//        glfwPollEvents();
//    }
//
//    glfwTerminate();
//    return 0;
//}
#pragma endregion


int main(int argc, char* argv[]) {

	//SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "hello world", "Successful", NULL);
	
	Game game;
	bool success = game.Initialize();
	if (success)
	{
		game.RunLoop();
	}

	game.Shutdown();
	
	
	
	return 0;
}

#include <GLFW/glfw3.h>
#include <CL/cl.hpp>

int main(void)
{
	cl::Platform platform;

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(1920, 1080, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/*wait for scene finished*/
		/*calculate frametime*/

		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		/*Begin processing new scene*/
		/*start frametime timer*/

		/*get and reset mouse if not in menu state*/
	}

	glfwTerminate();
	return 0;
}

/*physics thread with shared memory*/

//FOR MANAGING INPUT WITH GLFW
//class Window
//{
//public:
//	using Callback = std::function<void()>;
//
//	void addBinding(int key, const Callback& callback)
//	{
//		m_Callbacks[key].push_back(callback);
//	}
//
//	void onKeyPress(int key)
//	{
//		for (Callback& callback : m_Callbacks[key])
//		{
//			callback();
//		}
//	}
//private:
//	std::map<int, std::vector<Callback>> m_Callbacks;
//};

///* Alien screen coordinates */
//int alien_x = 0, alien_y = 0;
//int alien_xvel = 0, alien_yvel = 0;
//.
//.
///* Initialise SDL and video modes and all that */
//.
///* Main game loop */
///* Check for events */
//while (SDL_PollEvent(&event)) {
//	switch (event.type) {
//		/* Look for a keypress */
//	case SDL_KEYDOWN:
//		/* Check the SDLKey values and move change the coords */
//		switch (event.key.keysym.sym) {
//		case SDLK_LEFT:
//			alien_xvel = -1;
//			break;
//		case SDLK_RIGHT:
//			alien_xvel = 1;
//			break;
//		case SDLK_UP:
//			alien_yvel = -1;
//			break;
//		case SDLK_DOWN:
//			alien_yvel = 1;
//			break;
//		default:
//			break;
//		}
//		break;
//		/* We must also use the SDL_KEYUP events to zero the x */
//		/* and y velocity variables. But we must also be       */
//		/* careful not to zero the velocities when we shouldn't*/
//	case SDL_KEYUP:
//		switch (event.key.keysym.sym) {
//		case SDLK_LEFT:
//			/* We check to make sure the alien is moving */
//			/* to the left. If it is then we zero the    */
//			/* velocity. If the alien is moving to the   */
//			/* right then the right key is still press   */
//			/* so we don't tocuh the velocity            */
//			if (alien_xvel < 0)
//				alien_xvel = 0;
//			break;
//		case SDLK_RIGHT:
//			if (alien_xvel > 0)
//				alien_xvel = 0;
//			break;
//		case SDLK_UP:
//			if (alien_yvel < 0)
//				alien_yvel = 0;
//			break;
//		case SDLK_DOWN:
//			if (alien_yvel > 0)
//				alien_yvel = 0;
//			break;
//		default:
//			break;
//		}
//		break;
//
//	default:
//		break;
//	}
//}
//.
//.
///* Update the alien position */
//alien_x += alien_xvel;
//alien_y += alien_yvel;

//void DrawImage(void) {
//
//	glMatrixMode(GL_PROJECTION);
//	glPushMatrix();
//	glLoadIdentity();
//	glOrtho(0.0, glutGet(GLUT_WINDOW_WIDTH), 0.0, glutGet(GLUT_WINDOW_HEIGHT), -1.0, 1.0);
//	glMatrixMode(GL_MODELVIEW);
//	glPushMatrix();
//
//
//	glLoadIdentity();
//	glDisable(GL_LIGHTING);
//
//
//	glColor3f(1, 1, 1);
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, mark_textures[0].id);
//
//
//	// Draw a textured quad
//	glBegin(GL_QUADS);
//	glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
//	glTexCoord2f(0, 1); glVertex3f(0, 100, 0);
//	glTexCoord2f(1, 1); glVertex3f(100, 100, 0);
//	glTexCoord2f(1, 0); glVertex3f(100, 0, 0);
//	glEnd();
//
//
//	glDisable(GL_TEXTURE_2D);
//	glPopMatrix();
//
//
//	glMatrixMode(GL_PROJECTION);
//	glPopMatrix();
//
//	glMatrixMode(GL_MODELVIEW);
//
//}
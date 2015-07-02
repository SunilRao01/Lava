#include "Display.h"

// Using SDL just for windowing
Display::Display(int width, int height, const std::string &title)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	// 32-bits of color data
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

	// Allocate space for a second buffer
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// Create the window
	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);

	// Create the opengl context
	m_glContext = SDL_GL_CreateContext(m_window);

	// Initialize GLEW
	GLenum status = glewInit();
	if (status != GLEW_OK)
	{
		std::cerr << "Glew failed to initialize!";
	}

	m_isClosed = false;
}

Display::~Display()
{
	SDL_GL_DeleteContext(m_glContext);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Display::Clear(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}

bool Display::IsClosed()
{
	return m_isClosed;
}

void Display::Update()
{
	SwapBuffers();

	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		// Keyboard input example
		switch (e.type)
		{
		case SDL_KEYDOWN:
			std::cout << "Key press detected!" << std::endl;
			break;
		case SDL_KEYUP:
			std::cout << "Key release detected!" << std::endl;
		default:
			break;
		}

		if (e.type == SDL_QUIT)
		{
			m_isClosed = true;
		}
	}
}

void Display::SwapBuffers()
{
	SDL_GL_SwapWindow(m_window);
}
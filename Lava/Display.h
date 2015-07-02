#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <SDL2\SDL.h>
#include <iostream>
#include <GL\glew.h>

class Display
{
public:
	Display(int width, int height, const std::string &title);

	void Clear(float r, float g, float b, float a);
	void SwapBuffers();
	void Update();
	bool IsClosed();

	virtual ~Display();
protected:
private:
	Display(const Display &other) {}
	Display &operator=(const Display &other) {}

	SDL_Window *m_window;
	SDL_GLContext m_glContext;
	bool m_isClosed;
};

#endif
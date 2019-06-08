#pragma once

#include "SDL2/SDL.h"
#include <string>

class Display
{
public:
	Display(int width, int height, const std::string& title);
	~Display();

	void Update();
	bool IsClosed();

private:
	SDL_Window* m_window = nullptr;
	SDL_GLContext m_glContext;
	bool m_isClosed;
};


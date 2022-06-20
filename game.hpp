#pragma once
#include "Window.hpp"
#include "Sorting.hpp"

class Game
{
public:
	Game();
	Game(const sf::Vector2u& l_size, const std::string& l_name);
	~Game();

	bool HandleInput();
	void Update();
	void Render();

	Window* getWindow();
	
	void RestartClock();

	Sorting* getSorting();

private:
	Window m_window;
	Visualizer m_visualizer;
	Sorting m_sorting;

	sf::Clock m_clock;
	sf::Time m_elapsed;
};


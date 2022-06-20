#include "game.hpp"

Game::Game() : m_visualizer(m_window.getSize()), m_sorting(&m_visualizer, m_window.getWindow())
{
}

Game::Game(const sf::Vector2u& l_size, const std::string& l_name) : m_window(l_size, l_name), m_visualizer(m_window.getSize()), m_sorting(&m_visualizer, m_window.getWindow())
{
}

Game::~Game()
{
}

bool Game::HandleInput()
{
	if (m_visualizer.HandleInput()) {
		return true;
	}
	else {
		return false;
	}
}

void Game::Update()
{
	m_window.Update();
}

void Game::Render()
{
	m_window.BeginDraw(sf::Color::Black);
	m_visualizer.draw(m_window.getWindow());
	m_window.EndDraw();
}

Window* Game::getWindow()
{
	return &m_window;
}

void Game::RestartClock()
{
	m_elapsed = m_clock.restart();
}

Sorting* Game::getSorting()
{
	return &m_sorting;
}

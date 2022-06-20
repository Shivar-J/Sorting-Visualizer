#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class Window
{
public:
	Window();
	Window(const sf::Vector2u& l_size, const std::string& l_name);
	~Window();

	void BeginDraw(sf::Color l_color);
	void EndDraw();

	void Draw(sf::Drawable& l_drawable);

	void Update();

	sf::Vector2u getSize();
	sf::RenderWindow* getWindow();

	bool IsDone();

private:
	sf::RenderWindow m_window;
	bool bIsDone;
	
	void Setup(const sf::Vector2u& l_size, const std::string& l_name);
	void Destroy();
};


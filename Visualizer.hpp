#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

struct colourHandle {
	colourHandle() : col(sf::Quads, 4), colour(sf::Color::White) {
	
	}
	void changeColour(sf::Color l_colour) {
		for (int i = 0; i < 4; i++) {
			this->col[i].color = l_colour;
		}
	}
	sf::VertexArray col;
	sf::Color colour;
};

class Visualizer
{
public:
	Visualizer(sf::Vector2u l_size);
	~Visualizer();

	bool HandleInput();
	void draw(sf::RenderWindow* l_window);

	void setColumnWidth(int l_width);
	void setHeightMultiplier(int l_heightMultiplier);

	void reDraw();

	int* getArray();
	colourHandle* getColourHandle();
	int getColNum();

private:
	int* m_array;
	colourHandle* m_colourHandle;

	int m_nColourHandleWidth;
	int m_nHeightMultiplier;
	int m_nColNum;

	sf::Vector2u m_winSize;

	void Setup();
	void ShuffleArray();
};


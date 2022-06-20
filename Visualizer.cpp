#include "Visualizer.hpp"

Visualizer::Visualizer(sf::Vector2u l_size) : m_colourHandle(nullptr), m_array(nullptr)
{
	m_winSize = l_size;
	m_nColourHandleWidth = 4;
	m_nHeightMultiplier = 2;
	
	Setup();
}

Visualizer::~Visualizer()
{
	delete[] m_colourHandle;
	delete[] m_array;
}

bool Visualizer::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		return true;
	}
	else {
		return false;
	}
}

void Visualizer::draw(sf::RenderWindow* l_window)
{
	for (int i = 0; i < m_nColNum; i++) {
		l_window->draw(m_colourHandle[i].col);
	}
}

void Visualizer::setColumnWidth(int l_width)
{
	m_nColourHandleWidth = l_width;
	Setup();
}

void Visualizer::setHeightMultiplier(int l_heightMultiplier)
{
	m_nHeightMultiplier = l_heightMultiplier;
}

void Visualizer::reDraw()
{
	delete[] m_colourHandle;
	m_colourHandle = nullptr;

	m_colourHandle = new colourHandle[m_nColNum];

	for (int i = 0; i < m_nColNum; i++) {
		const int x = i * m_nColourHandleWidth;

		int height = (int)m_winSize.y - m_array[i] * m_nHeightMultiplier;

		colourHandle temp;
		temp.col[0] = sf::Vector2f(x, m_winSize.y);
		temp.col[1] = sf::Vector2f(x + m_nColourHandleWidth, m_winSize.y);
		temp.col[2] = sf::Vector2f(x + m_nColourHandleWidth, height);
		temp.col[3] = sf::Vector2f(x, height);

		m_colourHandle[i] = temp;
	}
}

int* Visualizer::getArray()
{
	return m_array;
}

colourHandle* Visualizer::getColourHandle()
{
	return m_colourHandle;
}

int Visualizer::getColNum()
{
	return m_nColNum;
}

void Visualizer::Setup()
{
	delete[] m_colourHandle;
	m_colourHandle = nullptr;

	m_nColNum = (int)m_winSize.x / m_nColourHandleWidth;

	m_array = new int[m_nColNum];

	for (int i = 0; i < m_nColNum; i++) {
		m_array[i] = i + 1;
	}

	ShuffleArray();

	m_colourHandle = new colourHandle[m_nColNum];

	for (int i = 0; i < m_nColNum; i++) {
		const int x = i * m_nColourHandleWidth;
		int height = (int)m_winSize.y - m_array[i] * m_nHeightMultiplier;

		colourHandle temp;
		temp.col[0] = sf::Vector2f(x, m_winSize.y);
		temp.col[1] = sf::Vector2f(x + m_nColourHandleWidth, m_winSize.y);
		temp.col[2] = sf::Vector2f(x + m_nColourHandleWidth, height);
		temp.col[3] = sf::Vector2f(x, height);
		
		m_colourHandle[i] = temp;
	}
}

void Visualizer::ShuffleArray()
{
	if (m_array != nullptr) {
		std::random_shuffle(m_array, m_array + m_nColNum);
	}
	else {
		printf("empty");
	}
}

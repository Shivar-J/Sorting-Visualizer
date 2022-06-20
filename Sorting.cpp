#include "Sorting.hpp"

Sorting::Sorting(Visualizer* l_visualizer_obj, sf::RenderWindow* l_window) {
	m_visualizer = l_visualizer_obj;
	window = l_window;
}

void Sorting::BubbleSort()
{
	for (int i = 0; i < m_visualizer->getColNum() - 1; i++) {
		for (int j = 0; j < m_visualizer->getColNum() - 1 - i; j++) {
			if (m_visualizer->getArray()[j] > m_visualizer->getArray()[j + 1]) {
				BubbleSwap(m_visualizer->getArray()[j], m_visualizer->getArray()[j + 1]);

				m_visualizer->getColourHandle()[j].changeColour(sf::Color::Green);

				UpdateScreen();
			}
		}
	}
}

void Sorting::SelectionSort()
{
	int min;

	for (int i = 0; i < m_visualizer->getColNum() - 1; i++) {
		min = i;
		for (int j = i + 1; j < m_visualizer->getColNum(); j++) {
			if (m_visualizer->getArray()[j] < m_visualizer->getArray()[min]) {
				min = j;
				m_visualizer->getColourHandle()[i].changeColour(sf::Color::Green);
				m_visualizer->getColourHandle()[min].changeColour(sf::Color::Red);
			}
			swap(m_visualizer->getArray()[min], m_visualizer->getArray()[i]);
		}
	}
}

void Sorting::InsertionSort()
{
	int key, j;
	for (int i = 1; i < m_visualizer->getColNum(); i++) {
		key = m_visualizer->getArray()[i];
		j = i - 1;
		while (j >= 0 && m_visualizer->getArray()[j] > key) {
			m_visualizer->getArray()[j + 1] = m_visualizer->getArray()[j];
			j = j - 1;
			m_visualizer->getColourHandle()[i].changeColour(sf::Color::Green);
			m_visualizer->getColourHandle()[key].changeColour(sf::Color::Red);
		}
		m_visualizer->getArray()[j + 1] = key;
		UpdateScreen();
	}
}

void Sorting::swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;

	UpdateScreen();
}

void Sorting::BubbleSwap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Sorting::UpdateScreen()
{
	window->clear(sf::Color::Black);

	m_visualizer->draw(window);
	m_visualizer->reDraw();

	window->display();
}

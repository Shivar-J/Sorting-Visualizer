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
	EndAnim();
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
	EndAnim();
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
	EndAnim();
}

void Sorting::CocktailSort()
{
	bool swapped = true;
	int start = 0;
	int end = m_visualizer->getColNum() - 1;

	while (swapped) {
		swapped = false;

		for (int i = start; i < end; ++i) {
			m_visualizer->getColourHandle()[i].changeColour(sf::Color::Green);
			m_visualizer->getColourHandle()[i + 1].changeColour(sf::Color::Red);
			if (m_visualizer->getArray()[i] > m_visualizer->getArray()[i + 1]) {
				swap(m_visualizer->getArray()[i], m_visualizer->getArray()[i + 1]);
				swapped = true;
			}
		}

		if (!swapped)
			break;

		swapped = false;

		--end;

		for (int i = end - 1; i >= start; --i) {
			m_visualizer->getColourHandle()[i].changeColour(sf::Color::Green);
			m_visualizer->getColourHandle()[i + 1].changeColour(sf::Color::Red);
			if (m_visualizer->getArray()[i] > m_visualizer->getArray()[i + 1]) {
				swap(m_visualizer->getArray()[i], m_visualizer->getArray()[i + 1]);
				swapped = true;
			}
		}

		++start;
	}
	EndAnim();
}

void Sorting::CycleSort()
{
	int writes = 0;

	for (int cycle_start = 0; cycle_start <= m_visualizer->getColNum() - 2; cycle_start++) {
		int item = m_visualizer->getArray()[cycle_start];

		int pos = cycle_start;

		for (int i = cycle_start + 1; i < m_visualizer->getColNum(); i++) {
			m_visualizer->getColourHandle()[i].changeColour(sf::Color::Yellow);
			if (m_visualizer->getArray()[i] < item)
				pos++;
		}

		if (pos == cycle_start)
			continue;

		while (item == m_visualizer->getArray()[pos])
			m_visualizer->getColourHandle()[pos].changeColour(sf::Color::Blue);
			pos += 1;

		if (pos != cycle_start) {
			swap(item, m_visualizer->getArray()[pos]);
			writes++;
		}

		while (pos != cycle_start) {
			pos = cycle_start;
			for (int i = cycle_start + 1; i < m_visualizer->getColNum(); i++) {
				if (m_visualizer->getArray()[i] < item)
					pos += 1;
			}

			while (item == m_visualizer->getArray()[pos])
				pos += 1;

			if (item != m_visualizer->getArray()[pos]) {
				m_visualizer->getColourHandle()[pos].changeColour(sf::Color::Red);
				swap(item, m_visualizer->getArray()[pos]);
				writes++;
			}
		}
	}
	EndAnim();
}

void Sorting::EndAnim()
{
	for(int i = 0; i < m_visualizer->getColNum(); i++) {
		int t = m_visualizer->getArray()[i];
		m_visualizer->getColourHandle()[i].changeColour(sf::Color::Green);
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

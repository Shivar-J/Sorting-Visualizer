#pragma once
#include "Visualizer.hpp"
#include <chrono>
#include <thread>

class Sorting
{
public:
	Sorting(Visualizer* l_visualizer_obj, sf::RenderWindow* l_window);

	//Sorting Algorithms
	void BubbleSort();
	void SelectionSort();
	void InsertionSort();
	void CocktailSort();

	void EndAnim();
private:
	void swap(int& a, int& b);
	void BubbleSwap(int& a, int& b);

	void UpdateScreen();

	Visualizer* m_visualizer;
	sf::RenderWindow* window;
};


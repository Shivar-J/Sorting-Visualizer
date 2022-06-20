#include "game.hpp"

char input() {
	int sort;
	printf("SPACE = start\n\nChoose Sorting Algorithm\n1: Bubble Sort\n2: Selection Sort\n3: Insertion Sort\n4: Cocktail Sort\n");
	scanf_s("%d", &sort);

	return sort;
}

int main() {
	int sort = input();

	Game game(sf::Vector2u(1280, 720), "Sorting Visualizer");

	while (!game.getWindow()->IsDone()) {
		if (game.HandleInput()) {
			switch (sort) {
			case 1: game.getSorting()->BubbleSort();
				break;
			case 2: game.getSorting()->SelectionSort();
				break;
			case 3: game.getSorting()->InsertionSort();
				break;
			case 4: game.getSorting()->CocktailSort();
				break;
			}
		}
		game.Update();
		game.Render();
		game.RestartClock();
	}
	return 0;
}
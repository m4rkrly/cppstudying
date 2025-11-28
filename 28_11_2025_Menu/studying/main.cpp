#include <clocale>
#include <cstdlib>
#include <iostream>

#include "menu.hpp"
#include "menu_functions.hpp"

int main() {
	std::setlocale(LC_ALL, "");

	tkr::MenuItem study = {"1 - Продолжить", tkr::study};
	tkr::MenuItem exit = {"0 - Выйти", tkr::exit};

	tkr::MenuItem* menuElements[] = { &exit, &study};
	const int menuSize = sizeof(menuElements)/sizeof(menuElements[0]);
	
	int userInput;
	do {
		std::cout << "Привет! Это тестовая программа" << std::endl;

		for (int i = 1; i < menuSize; i++) {
			std::cout << menuElements[i]->text << std::endl;
		}
		std::cout << menuElements[0]->text << std::endl;
		std::cout << "Тест > ";

		std::cin >> userInput;
		menuElements[userInput]->func();

		std::cout << std::endl;
	} while (true);

	return 0; 
}

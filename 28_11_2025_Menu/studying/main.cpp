#include <clocale>
#include <cstdlib>
#include <iostream>

int main() {
	std::setlocale(LC_ALL, "");

	int user_input;

	do {
		std::cout << "Это тестовая программа" << std::endl;
		std::cout << "1 - Продолжить" << std::endl;
		std::cout << "0 - Выйти из программы" << std::endl;
		std::cout << "Тест > "; 
		
		std::cin >> user_input;

		if (user_input == 1) {
			// WIP
		} 
		else if (user_input == 0) {
			exit(0);
		}

		std::cout << std::endl;
	} while (true);

	return 0; 
}

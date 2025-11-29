#include <cstdlib>
#include <iostream>

#include "menuFunctions.hpp"
#include "menuStructures.hpp"

const tkr::MenuItem* tkr::showMenu(const tkr::MenuItem* current) {
	std::cout << "Добро пожаловать в тестовую программу!" << std::endl;
	for (int i = 1; i < current->childrenSize; i++) {
			std::cout << current->children[i]->text << std::endl;
	}

	std::cout << current->children[0]->text << std::endl;
	std::cout << "Меню > ";

	int userInput;
	std::cin >> userInput;
	std::cout << std::endl;
	
	return current->children[userInput]; 
}

const tkr::MenuItem* tkr::exit(const MenuItem* current) {
	std::exit(0);
}


const tkr::MenuItem* tkr::studySum(const MenuItem* current) {
	std::cout << current-> text << std::endl << std::endl;
	return current->parent;
}

const tkr::MenuItem* tkr::studySubt(const MenuItem* current) {
	std::cout << current-> text << std::endl << std::endl;
	return current->parent;
}

const tkr::MenuItem* tkr::studyMult(const MenuItem* current) {
	std::cout << current-> text << std::endl << std::endl;
	return current->parent;
}

const tkr::MenuItem* tkr::studyDiv(const MenuItem* current) {
	std::cout << current-> text << std::endl << std::endl;
	return current->parent;
}

const tkr::MenuItem* tkr::studyGoBack(const MenuItem* current) {
	std::cout << current-> text << std::endl << std::endl;
	return current->parent->parent;
}


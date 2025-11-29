#include <cstdlib>
#include <iostream>

#include "menuFunctions.hpp"
#include "menuStructures.hpp"

namespace {
	const tkr::MenuItem* showMenu(const tkr::MenuItem* current) {
		for (int i = 1; i < current->childrenSize; i++) {
			std::cout << current->children[i]->text << std::endl;
		}
		std::cout << current->children[0]->text << std::endl;
		std::cout << "Университеты > ";

		int userInput;
		std::cin >> userInput;
		std::cout << std::endl;

		return current->children[userInput];
	}
}

const tkr::MenuItem* tkr::showMenu1(const tkr::MenuItem* current) {
	std::cout << "Главное меню" << std::endl;
	return showMenu(current); 
}

const tkr::MenuItem* tkr::showMenu2(const tkr::MenuItem* current) {
	std::cout << "Второй уровень меню" << std::endl;
	return showMenu(current); 
} 

const tkr::MenuItem* tkr::showMenu3(const tkr::MenuItem* current) {
	std::cout << "Третий уровень меню" << std::endl;
	return showMenu(current); 
} 

const tkr::MenuItem* tkr::exit(const tkr::MenuItem* current) {
	std::exit(0);
}
const tkr::MenuItem* tkr::goBack(const tkr::MenuItem* current) {
	std::cout << current->text << std::endl << std::endl;
	return current->parent->parent;
}

// SPBU
const tkr::MenuItem* tkr::spbuPMPU(const tkr::MenuItem* current) {
	std::cout << current->text << std::endl << std::endl;
	return current->parent;
}
const tkr::MenuItem* tkr::spbuMatMech(const tkr::MenuItem* current) {
	std::cout << current->text << std::endl << std::endl;
	return current->parent;
}
const tkr::MenuItem* tkr::spbuLing(const tkr::MenuItem* current) {
	std::cout << current->text << std::endl << std::endl;
	return current->parent;
}

// UNIS
const tkr::MenuItem* tkr::unisITMO(const tkr::MenuItem* current) {
	std::cout << current->text << std::endl << std::endl;
	return current->parent;
}

const tkr::MenuItem* tkr::unisPoly(const tkr::MenuItem* current) {
	std::cout << current->text << std::endl << std::endl;
	return current->parent;
}

const tkr::MenuItem* tkr::unisLETI(const tkr::MenuItem* current) {
	std::cout << current->text << std::endl << std::endl;
	return current->parent;
}

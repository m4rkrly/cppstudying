#include "menuFunctions.hpp"
#include "menuInit.hpp"
#include "menuStructures.hpp"

// SPBU
const tkr::MenuItem tkr::SPBU_PMPU = {
	"1 - Факультет ПМ-ПУ", &tkr::spbuPMPU, &tkr::UNIS_SPBU,
}; 

const tkr::MenuItem tkr::SPBU_MATMECH = {
	"2 - Факультет МатМех", &tkr::spbuMatMech, &tkr::UNIS_SPBU,
}; 

const tkr::MenuItem tkr::SPBU_LING = {
	"3 - Лингвистический факультет", &tkr::spbuLing, &tkr::UNIS_SPBU,
}; 

const tkr::MenuItem tkr::SPBU_GO_BACK = {
	"0 - Выйти в предыдущее меню", &tkr::goBack, &tkr::UNIS_SPBU,
}; 

namespace {
	const tkr::MenuItem* const spbuChildren[] = {
		&tkr::SPBU_GO_BACK,
		&tkr::SPBU_PMPU,
		&tkr::SPBU_MATMECH,
		&tkr::SPBU_LING,
	};
	const int spbuSize = sizeof(spbuChildren) / sizeof(spbuChildren[0]);
}

// UNIS
const tkr::MenuItem tkr::UNIS_SPBU = {
	"1 - СПбГУ", &tkr::showMenu3, &tkr::MAIN_UNIS, spbuChildren, spbuSize
}; 

const tkr::MenuItem tkr::UNIS_ITMO = {
	"2 - ИТМО", &tkr::unisITMO, &tkr::MAIN_UNIS,
}; 

const tkr::MenuItem tkr::UNIS_POLY = {
	"3 - Политех", &tkr::unisPoly, &tkr::MAIN_UNIS,
}; 

const tkr::MenuItem tkr::UNIS_LETI = {
	"4 - ЛЭТИ", &tkr::unisLETI, &tkr::MAIN_UNIS,
};

const tkr::MenuItem tkr::UNIS_GO_BACK = {
	"0 - Выйти в главное меню", &tkr::goBack, &tkr::MAIN_UNIS,
};

namespace {
	const tkr::MenuItem* const unisChildren[] = {
		&tkr::UNIS_GO_BACK,
		&tkr::UNIS_SPBU,
		&tkr::UNIS_ITMO,
		&tkr::UNIS_POLY,
		&tkr::UNIS_LETI,
	};
	const int unisSize = sizeof(unisChildren) / sizeof(unisChildren[0]);
}

// MAIN

const tkr::MenuItem tkr::MAIN_UNIS = {
	"1 - Посмотреть университеты Санкт-Петербурга", &tkr::showMenu2, &tkr::MAIN, unisChildren, unisSize 
};

const tkr::MenuItem tkr::MAIN_EXIT = {
	"0 - Я уже студент", &tkr::exit, &tkr::MAIN
};

namespace {
	const tkr::MenuItem* const mainChildren[] = {
		&tkr::MAIN_EXIT,
		&tkr::MAIN_UNIS,
	};
	const int mainSize = sizeof(mainChildren) / sizeof(mainChildren[0]); 
}

const tkr::MenuItem tkr::MAIN = {
	"", &tkr::showMenu1, nullptr, mainChildren, mainSize
};


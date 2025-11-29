#include <cstddef>

#include "menuInit.hpp"
#include "menuFunctions.hpp"
#include "menuStructures.hpp"
	
const tkr::MenuItem tkr::STUDY_SUM = {
	"1 - Сложение", tkr::studySum, &tkr::STUDY
};
const tkr::MenuItem tkr::STUDY_SUBT = {
	"2 - Вычитание", tkr::studySubt, &tkr::STUDY
};
const tkr::MenuItem tkr::STUDY_MULT = {
	"3 - Умножение", tkr::studyMult, &tkr::STUDY
};
const tkr::MenuItem tkr::STUDY_DIV = {
	"4 - Деление", tkr::studyDiv, &tkr::STUDY
};
const tkr::MenuItem tkr::STUDY_GO_BACK = {
	"0 - Выйти в главное меню", tkr::studyGoBack, &tkr::STUDY
};

namespace {
	const tkr::MenuItem* const studyChildren[] = {
		&tkr::STUDY_GO_BACK,	
		&tkr::STUDY_SUM,	
		&tkr::STUDY_SUBT,	
		&tkr::STUDY_MULT,	
		&tkr::STUDY_DIV,	
	};
	const int studySize = sizeof(studyChildren) / sizeof(studyChildren[0]);
}

const tkr::MenuItem tkr::STUDY = {
	"1 - Хочу учиться", tkr::showMenu, &tkr::MAIN, studyChildren, studySize
};
const tkr::MenuItem tkr::EXIT = {
	"0 - Не, не хочу чёта", tkr::exit, &tkr::MAIN 
};

namespace {
	const tkr::MenuItem* const mainChildren[] = {
		&tkr::EXIT,
		&tkr::STUDY,
	};
	const int mainSize = sizeof(mainChildren) / sizeof(mainChildren[0]);
}

const tkr::MenuItem tkr::MAIN = {
	nullptr, tkr::showMenu, nullptr, mainChildren, mainSize
};

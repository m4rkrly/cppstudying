#pragma once

#include "menuStructures.hpp"

namespace tkr {
	const MenuItem* showMenu(const MenuItem* current);
	
	const MenuItem* exit(const MenuItem* current);

	const MenuItem* studySum(const MenuItem* current);
	const MenuItem* studySubt(const MenuItem* current);
	const MenuItem* studyMult(const MenuItem* current);
	const MenuItem* studyDiv(const MenuItem* current);
	const MenuItem* studyGoBack(const MenuItem* current);

}

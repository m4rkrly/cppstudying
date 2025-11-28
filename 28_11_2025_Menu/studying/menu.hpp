#pragma once

namespace tkr {
	struct MenuItem {
		const char* const text;
		void(*func)(); //указатель на функцию: указывает на саму функцию, принимает параметры 
	};
}

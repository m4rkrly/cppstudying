#include "keyboard_data.hpp"

using biv::KeyData;
using biv::KeyBoardData;

const std::vector<KeyData> KeyBoardData::KEYS = {
	{1025, "Ё"}, {49, "1"}, {50, "2"}, {51, "3"}, {52, "4"}, {53, "5"}, {54, "6"},
		{55, "7"}, {56, "8"}, {57, "9"}, {48, "0"}, {45, "-"}, {61, "="},
	{1049, "Й"}, {1062, "Ц"}, {1059, "У"}, {1050, "К"}, {1045, "Е"}, {1053, "Н"}, {1043, "Г"},
		{1064, "Ш"}, {1065, "Щ"}, {1047, "З"}, {1061, "Х"}, {1066, "Ъ"}, {92, "\\"},
	{1060, "Ф"}, {1067, "Ы"}, {1042, "В"}, {1040, "А"}, {1055, "П"}, {1056, "Р"}, {1054, "О"},
		{1051, "Л"}, {1044, "Д"}, {1046, "Ж"}, {1069, "Э"},
	{1071, "Я"}, {1063, "Ч"}, {1057, "С"}, {1052, "М"}, {1048, "И"}, {1058, "Т"}, {1068, "Ь"},
		{1041, "Б"}, {1070, "Ю"}, {46, "."}
};

std::vector<KeyData> KeyBoardData::get_line1() const {
	return {KEYS.begin(), KEYS.begin() + 13};
}

std::vector<KeyData> KeyBoardData::get_line2() const {
	return {KEYS.begin() + 13, KEYS.begin() + 26};
}

std::vector<KeyData> KeyBoardData::get_line3() const {
	return {KEYS.begin() + 26, KEYS.begin() + 37};
}

std::vector<KeyData> KeyBoardData::get_line4() const {
	return {KEYS.begin() + 37, KEYS.begin() + 47};
}

bool KeyBoardData::is_key_allowed(const int code) const noexcept {
	if ((code > 47) and (code < 58) or (code == 45) or (code == 46) or (code == 61)) {
		return true;
	}

	if ((code > 1039) and (code < 1072) or (code == 1025)) {
		return true;
	}

	if ((code == Qt::Key_Space) or (code == 16777220) or (code == Qt::Key_Backspace)){
		return true;
	}

	return false;
}

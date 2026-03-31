#include <gtest/gtest.h>

#include "vector.hpp"

using tkr::Vector;

// КОНСТРУКТОР И ДЕСТРУКТОР

TEST(ConstructorAndDestructor, Default) {
	tkr::Vector<int> a;
	ASSERT_EQ(a.get_size(), 0)
		<< "Некорректный размер вектора"
		<< a.get_size();
}

// ВСТАВКА, ДОБАВЛЕНИЕ



// УДАЛЕНИЕ

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

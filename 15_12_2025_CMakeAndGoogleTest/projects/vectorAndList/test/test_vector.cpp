#include <gtest/gtest.h>

#include "vector.hpp"

using tkr::Vector;

// КОНСТРУКТОР И ДЕСТРУКТОР

TEST(ConstructorAndDestructor, Default) {
	tkr::Vector<int> a;
	ASSERT_EQ(a.get_size(), 0)
		<< "Некорректный размер вектора "
		<< a.get_size();
}

// ДОБАВЛЕНИЕ

TEST(Addition, SingleAddition) {
	tkr::Vector<int> v1;
	v1.push_back(1);
	ASSERT_EQ(v1.get_size(), 1)
		<< "Некорректный размер вектора "
		<< v1.get_size();
	ASSERT_TRUE(v1.has_item(1))
		<< "Отсутствует или неправильно вставлен добавленный элемент";
}

TEST(Addition, MultipleAddition) {
	tkr::Vector<int> v1;
	
	for (int i = 1; i < 5; i++) {
		v1.push_back(i);
	}
	ASSERT_EQ(v1.get_size(), 4)
		<< "Некорректный размер вектора "
		<< v1.get_size();
	
	for (int i = 1; i < 5; i++) {
		ASSERT_TRUE(v1.has_item(i))
			<< "Отсутствует или неправильно вставлен добавленный элемент";
	}
}

// УДАЛЕНИЕ

TEST(Deletion, SingleDeletion) {
	tkr::Vector<int> v1;
	
	for (int i = 1; i < 6; i++) {
		v1.push_back(i);
	}
	v1.remove_first(1);
	
	ASSERT_EQ(v1.get_size(), 4)
		<< "Элемент не был удалён или был удалён неправильно";
	
	for (int i = 2; i < 6; i++) {
		ASSERT_TRUE(v1.has_item(i));
	}
}

TEST(Deletion, MultipleDeletion) {
	tkr::Vector<int> v1;
	
	for (int i = 1; i < 6; i++) {
		v1.push_back(i);
	}
	v1.remove_first(2);
	v1.remove_first(4);

	ASSERT_EQ(v1.get_size(), 3)
		<< "Элемент не был удалён или был удалён неправильно";

	for (int i = 1; i < 6; i += 2) {
		ASSERT_TRUE(v1.has_item(i))
			<< "Был удалён или вовсе не добавлен не стоящий в очереди на удаление элемент";
	}
}

// ВСТАВКА

TEST(Insertion, SingleInsertion) {
	tkr::Vector<int> v1;

	for (int i = 1; i < 9; i += 2) {
		v1.push_back(i);
	}

	v1.insert(0, 1);
	bool del1 = v1.remove_first(1);
	bool del2 = v1.remove_first(1);

	ASSERT_TRUE(del1 and del2)
		<< "Не был вставлен указанный элемент";
	
	ASSERT_EQ(v1.get_size(), 3)
		<< "Размер массива после вставки и удаления некорректен";

	for (int i = 3; i < 9; i += 2) {
		v1.has_item(i);
	}
}

TEST(Insertion, MultipleInsertion) {
	tkr::Vector<int> v1;

	for (int i = 1; i < 9; i++) {
		v1.push_back(i);
	}

	v1.insert(0, 1);
	v1.insert(8, 8);
	v1.insert(4, 3);
	bool del1 = v1.remove_first(1);
	bool del2 = v1.remove_first(8);
	bool del3 = v1.remove_first(4);

	ASSERT_TRUE(del1 and del2 and del3)
		<< "Не был вставлен указанный элемент";
	
	ASSERT_EQ(v1.get_size(), 8)
		<< "Размер массива после вставки и удаления не совпадает";

	for (int i = 1; i < 8; i++) {
		v1.has_item(i);
	}
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

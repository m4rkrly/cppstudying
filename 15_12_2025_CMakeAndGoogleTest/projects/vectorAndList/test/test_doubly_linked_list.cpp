#include <gtest/gtest.h>

#include "doubly_linked_list.hpp"

using tkr::DoublyLinkedList;

// КОНСТРУКТОР
TEST(ConstructAndDestruct, Default) {
	tkr::DoublyLinkedList<int> l1;
		
	ASSERT_EQ(l1.get_size(), 0)
		<< "Неверный размер списка!"
		<< l1.get_size();
}

// ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ
TEST(Addition, SingleAddition) {
	tkr::DoublyLinkedList<int> l1;

	l1.push_back(1);

	ASSERT_EQ(l1.get_size(), 1)
		<< "Элемент не был добавлен в список";

	ASSERT_TRUE(l1.has_item(1))
		<< "Элемент не был добавлен или был добавлен некорректно!";
}


TEST(Addition, MultipleAddition) {
	tkr::DoublyLinkedList<int> l1;
	
	for (int i = 0; i < 6; i++) {
		l1.push_back(i);
	}

	ASSERT_EQ(l1.get_size(), 6)
		<< "Размер списка некорректен!";

	for (int i = 0; i < 6; i++) {
		ASSERT_TRUE(l1.has_item(i))
			<< "Элемент не был добавлен или был добавлен некорректно!";
	}
}


// УДАЛЕНИЕ
TEST(Deletion, SingleDeletion) {
	tkr::DoublyLinkedList<int> l1;
	
	for (int i = 0; i < 5; i++) {
		l1.push_back(i);
	}
	
	l1.remove_first(0);
	l1.remove_first(7);

	ASSERT_EQ(l1.get_size(), 4)
		<< "Размер списка некорректен!";

	for (int i = 1; i < 5; i++) {
		ASSERT_TRUE(l1.has_item(i))
			<< "Элемент не был удалён или был удалён некорректно!";
	}
}

TEST(Deletion, MultipleDeletion) {
	tkr::DoublyLinkedList<int> l1;
	
	for (int i = 0; i < 7; i++) {
		l1.push_back(i);
	}
	
	l1.remove_first(0);
	l1.remove_first(2);
	l1.remove_first(4);
	l1.remove_first(6);

	ASSERT_EQ(l1.get_size(), 3)
		<< "Размер списка некорректен!";

	for (int i = 1; i < 7; i += 2) {
		ASSERT_TRUE(l1.has_item(i))
			<< "Элемент не был удалён или был удалён некорректно!";
	}
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

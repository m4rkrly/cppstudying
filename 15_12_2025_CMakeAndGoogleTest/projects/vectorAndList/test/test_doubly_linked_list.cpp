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

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

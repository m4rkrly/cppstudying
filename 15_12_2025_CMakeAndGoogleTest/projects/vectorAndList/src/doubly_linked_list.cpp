#include "doubly_linked_list.hpp"

#include <iostream>

using tkr::DoublyLinkedList;

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	if (end != nullptr) {
		Node* cur = end;
		while (cur->prev != nullptr) {
			cur = cur->prev;
			delete cur->next;
		}
		delete cur;
	}
	this->begin = nullptr;
	this->end = nullptr;
}

template<typename T>
std::size_t DoublyLinkedList<T>::get_size() const noexcept {
	std::size_t counter = 0;
	if (begin != nullptr) {
		Node* cur = begin;
		while (cur != nullptr) {
			counter++;
			cur = cur->next;
		}
	}
	return counter;
}

template<typename T>
bool DoublyLinkedList<T>::has_item(const T& value) const noexcept {
	if (begin != nullptr) {
		Node* cur = begin;
		while (cur != nullptr) {
			if (cur->value == value) 
				return true;
			cur = cur->next;
		}
	}
	return false;
}

template<typename T>
void DoublyLinkedList<T>::print() const noexcept {
	if (begin != nullptr) {
		Node* cur = begin;
		std::cout << "[ ";
		while (cur != nullptr) {
			std::cout << cur->value << ' ';
			cur = cur->next;
		}
		std::cout << " ]";
	}
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
	// TODO
}

template<typename T>
bool DoublyLinkedList<T>::remove_first(const T& value) noexcept {
	// TODO
}

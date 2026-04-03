#include "doubly_linked_list.hpp"

#include <iostream>

using tkr::DoublyLinkedList;

// Деструктор
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

// Получить размер
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

// Проверить есть ли элемент в списке
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

// Вывести содержимое списка
template<typename T>
void DoublyLinkedList<T>::print() const noexcept {
	if (begin != nullptr) {
		Node* cur = begin;
		std::cout << "[ ";
		while (cur != nullptr) {
			std::cout << cur->value << ' ';
			cur = cur->next;
		}
		std::cout << "]" << std::endl;
	}
}

// Добавить элемент в конец списка
template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
	Node* newNode = new Node(value);
	if (end != nullptr) {
		end->next = newNode;
		newNode->prev = end;
		end = newNode;
	} else {
		begin = newNode;
		end = newNode;
	}
}

// Удалить первое вхождение элемента
template<typename T>
bool DoublyLinkedList<T>::remove_first(const T& value) noexcept {
	if (begin != nullptr) {
		Node* cur = begin;
		while (cur != nullptr) {
			if (cur->value == value) {
				if (cur->next != nullptr) {
					cur->next->prev = cur->prev;
				} else {
					this->end = cur->prev;
				}
				if (cur->prev != nullptr) {
					cur->prev->next = cur->next;
				} else {
					this->begin = cur->next;
				}
				
				delete cur;
				return true;
			}
			cur = cur->next;
			std::cout << "1" << std::endl;
		}
	}
	return false;
}

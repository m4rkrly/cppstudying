#include "vector.hpp"

#include <iostream>

using tkr::Vector;

// Конструктор
template<typename T>
Vector<T>::Vector() {
	arr = new T[capacity]; 
}

// Деструктор
template<typename T>
Vector<T>::~Vector() {
	delete[] arr;
	arr = nullptr;
}

// Получение количества элементов
template<typename T>
std::size_t Vector<T>::get_size() const noexcept {
	return this->size;
}

// Проверить наличие элемента
template<typename T>
bool Vector<T>::has_item(const T& value) const noexcept {
	for (int i = 0; i < size; i++) {
		if (arr[i] == value) 
			return true;
	}
	return false;
}

template<typename T>
bool Vector<T>::insert(const std::size_t position, const T& value) {
	// TODO
}

template<typename T>
void Vector<T>::print() const noexcept {
	// TODO
}

template<typename T>
void Vector<T>::push_back(const T& value) {
	// TODO
}

template<typename T>
bool Vector<T>::remove_first(const T& value) {
	// TODO
}

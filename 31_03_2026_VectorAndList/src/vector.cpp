#include "vector.hpp"

#include <iostream>

using tkr::Vector;

// Проверка текущего Capacity и его уменьшение/расширение
void checkCapacity() {
	// TODO
}

// Копирование массива для расширения capacity или insert
// Возможно следует перегрузить для копирования с индекса
template<typename T>
T* copy() {
	// TODO
}

// Конструктор
template<typename T>
Vector<T>::Vector() {
	arr = new T[capacity]; 
}

template<typename T>
Vector<T>::~Vector() {
	delete arr[];
	arr = nullptr;
}

template<typename T>
std::size_t Vector<T>::get_size() const noexcept {
	return this->size;
}

template<typename T>
bool Vector<T>::has_item(const T& value) const noexcept {
	for (int i = 0; i < size; i++) {
		if (arr[i] == value) 
			return True
	}
	return False
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

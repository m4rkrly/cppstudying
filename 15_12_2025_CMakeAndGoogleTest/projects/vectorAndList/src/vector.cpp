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
	this->arr = nullptr;
	this->capacity = 1;
	this->size = 0;
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

// Вставить элемент по индексу
template<typename T>
bool Vector<T>::insert(const std::size_t position, const T& value) {
	if (position < size) {
		T* tempArr = arr;
		if (capacity - size == 0) {
			tempArr = new T[2 * capacity];
		} else if (capacity / 4 >= size) {
			tempArr = new T[(size + size/2 >= 1) ? size + size/2 : 1];
		}

		for (int i = size; i != position; i--) {
			tempArr[i] = arr[i - 1];
		}
		arr = tempArr;
		this->size++;
		
		arr[position] = value;
		return true;
	} else {
	return false;
	}
}

// Вывести значения
template<typename T>
void Vector<T>::print() const noexcept {
	std::cout << "Contains: ";
	for (int i = 0; i < size; i++) {
		std::cout << this->arr[i] << ' ';
	}
	std::cout << std::endl;
	std::cout << "Size: " << this->size << std::endl;
	std::cout << "Capacity: " << this->capacity << std::endl;
}

// Добавить элемент в конец (справа)
template<typename T>
void Vector<T>::push_back(const T& value) {
	checkCapacity();
	this->arr[size] = value;
	this->size++;
}

// Удалить первое включение элемента
template<typename T>
bool Vector<T>::remove_first(const T& value) {
	for (int i = 0; i < size; i++) {
		if (this->arr[i] == value) {
			for (int j = i; j < size - 1; j++) {
				arr[j] = arr[j + 1];
			}
			this->size--;
			checkCapacity();	
			return true;
		}
	}
	return false;
}


// +---------------------------------------------------------------------------+
// | PRIVATE                                                                   |
// +---------------------------------------------------------------------------+

//Проверка свободного места
template<typename T>
void Vector<T>::checkCapacity() {
	if (capacity - size == 0) {
		capacity = 2 * capacity;
	} else if (capacity / 4 >= size) {
		capacity = (size + size/2 >= 1) ? size + size/2 : 1;
	} else {
		return;
	}
		T* newArr = new T[capacity];
		for(int i = 0; i < size; i++) {
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;	
		newArr = nullptr;	
}

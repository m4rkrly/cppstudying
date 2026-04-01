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

// Сравнение с другим вектором (равно/не равно)
template<typename T>
bool Vector<T>::equal(const Vector& v2) const noexcept {
	if (this->size != v2.size) 
		return false;
	
	for (int i = 0; i < this->size; i++) {
		if (this->arr[i] != v2.arr[i])
			return false;
	}
	return true;
} 

// Копирование старого массива в новый
template<typename T>
void Vector<T>::copy(const T* oldArr, T* newArr, const std::size_t oldSize) {
	for(int i = 0; i < oldSize; i++) {
		newArr[i] = oldArr[i];
	}
}

// Проверка свободного места
template<typename T>
void Vector<T>::checkCapacity() {
	if (capacity - size == 0) {
		this->capacity = 2 * capacity;
	} else if (capacity / 2 == size && capacity > 1) {
		this->capacity = capacity / 2;
	} else {
		return;
	}
		T* newArr = new T[capacity];
		copy(this->arr, newArr, this->size);
		delete[] arr;
		this->arr = newArr;	
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

// Добавить элемент в конец (справа)
template<typename T>
void Vector<T>::push_back(const T& value) {
	checkCapacity();
	this->arr[size] = value;
	this->size++;
}

// Закрыть разрыв в массиве
template<typename T>
void Vector<T>::connect(const std::size_t gapIndex) {
	for (int i = gapIndex; i < size - 1; i++) {
		arr[i] = arr[i + 1];
	}
	this->size--;
	checkCapacity();
}

// Удалить первое включение элемента
template<typename T>
bool Vector<T>::remove_first(const T& value) {
	for (int i = 0; i < size; i++) {
		if (this->arr[i] == value) {
			connect(i);	
			return true;
		}
	}
	return false;
}

// Создать одну свободную ячейку по индексу
template<typename T>
void Vector<T>::spread(const std::size_t gapIndex) {
	checkCapacity();
	for (int i = size; i != gapIndex; i--) {
		arr[i] = arr[i - 1];
	}
	this->size++;
}

// Вставить элемент по индексу
template<typename T>
bool Vector<T>::insert(const std::size_t position, const T& value) {
	if (position >= 0 && position < size) {
		spread(position);
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


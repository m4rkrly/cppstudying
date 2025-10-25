#include "aio.hpp"
#include "sorts.hpp"
#include <iostream> 

int main() 
{
        std::cout << "Введите размер массива для сортировки: " << std::endl;
        int size; std::cin >> size;

        int* arr = new int[size];
        int temp;
        
        std::cout << "Введите через пробел элементы массива: " << std::endl;
        for (int i = 0; i < size; i++) 
        {
            std::cin >> temp;
            arr[i] = temp;
        }
        
        ktr::sorts::shellSort(arr, size);
        
        std::cout << "Отсортированный массив: " << std::endl;
        ktr::coutArray(arr, size);
}

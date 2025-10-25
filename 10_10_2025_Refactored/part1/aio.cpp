#include "aio.hpp"

#include <iostream>

void ktr::coutArray(int* arr, const int size) 
{
        for (int i = 0; i < size; i++) 
        { 
            std::cout << arr[i] << ' ';
        }
        std::cout << "\n";
}


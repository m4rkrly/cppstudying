#include "aio.hpp"
#include <iostream>

void personal::coutArray(int* array, const int size) 
{
        for (int i = 0; i < size; i++) 
        { 
            std::cout << array[i] << ' ';
        }
        std::cout << "\n";
}


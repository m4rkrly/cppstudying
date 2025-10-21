#include "sorts.hpp"

void personal::sorts::shellSort(int* array, const int size) {
    int temp;
    for (int step = size/2; step > 0; step /= 2) 
    {
        for (int j = 0; j + step < size; j++) 
        {
            for (int i = j + step; i-step >= 0; i -= step) 
            {
                if (array[i] < array[i-step])
                {
                    temp = array[i];
                    array[i] = array[i-step];
                    array[i-step] = temp;
                }
            }
        }
    }
}

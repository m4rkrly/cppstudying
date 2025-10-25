#include "sorts.hpp"

void ktr::sorts::shellSort(int* arr, const int size) {
    int temp;
    for (int step = size / 2; step > 0; step /= 2) 
    {
        for (int j = 0; j + step < size; j++) 
        {
            for (int i = j + step; i - step >= 0; i -= step) 
            {
                if (arr[i] < arr[i - step])
                {
                    temp = arr[i];
                    arr[i] = arr[i - step];
                    arr[i - step] = temp;
                }
            }
        }
    }
}

#include <cmath>
#include <iostream>

void arithMean(const int number, int* array, const int size, int sum); 

int main()
{
    const int size = 10;
    int array[size];
    int sum = 0;
   
    for (int i = 1; i < 4; i++)
    {
        arithMean(i, array, size, sum);
    }

    return 0;
}

void arithMean(const int number, int* array, const int size, int sum)  
{
    std::cout << number << " последовательность" << std::endl;
    for (int i = 0; i < size; i++)
    {
        array[i] = std::rand() % size;
        std::cout << array[i] << ' ';
        sum += array[i];
    }
    std::cout << std::endl;
    std::cout << "среднее " << number << " последовательности=" << sum/10 << std::endl;
}



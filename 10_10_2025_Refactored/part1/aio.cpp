#include "aio.hpp"
#include <iostream>

using namespace std;

void personal::outV(int* a, int n) {
        for (int i = 0; i < n; i++)
                cout << a[i] << ' ';
        cout << "\n";
}


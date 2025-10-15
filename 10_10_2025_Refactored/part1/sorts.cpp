#include "sorts.hpp"

using namespace std;

void personal::sorts::shell_sort(int* a, int n) {
    int temp;
    for (int step = n/2; step > 0; step /= 2) {
        for (int j = 0; j + step < n; j++) {
            for (int i = j + step; i-step >= 0; i -= step) {
                if (a[i] < a[i-step]) {
                   temp = a[i];
                   a[i] = a[i-step];
                   a[i-step] = temp;
                   }
            }
        }
    }
}

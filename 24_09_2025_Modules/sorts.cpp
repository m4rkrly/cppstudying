#include "sorts.hpp"
#include <vector>

using namespace std;

void personal::sorts::shell_sort(vector<int> &a) {
    int n = size(a);
    for (int step = n/2; step > 0; step /= 2) {
        for (int j = 0; j + step < n; j++) {
            for (int i = j + step; i-step >= 0; i -= step) {
                if (a[i] < a[i-step])
                    swap(a[i], a[i-step]);
            }
        }
    }
}

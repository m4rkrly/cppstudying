#include "aio.hpp"
#include "sorts.hpp"
#include <iostream> 

using namespace std;

int main() {
        int n; cin >> n;
        int* a = new int[n];
        int temp;
        
        for (int i = 0; i < n; i++) {
            cin >> temp;
            a[i] = temp;
        }

        personal::outV(a, n);
        personal::sorts::shell_sort(a, n);
        personal::outV(a, n);
}

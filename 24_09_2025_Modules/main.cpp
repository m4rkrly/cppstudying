#include "aio.hpp"
#include "sorts.hpp"
#include <vector>

using namespace std;

int main() {
        vector<int> a = {4, 3, 0, 1, 2};
        
        personal::outV("До сортировки:", a);
        personal::sorts::shell_sort(a);
        personal::outV("После сортировки:", a);
}

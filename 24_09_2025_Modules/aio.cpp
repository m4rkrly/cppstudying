#include "aio.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void personal::outV(string comment, vector<int> &a) {
        cout << comment << " ";
        for (int i : a)
                cout << i << ' ';
        cout << "\n";
}


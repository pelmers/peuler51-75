#include "euler.hpp"

using std::floor;

int main(void);

int main(void) {
    int c = 0;
    vector<int> t;
    for (int i = 2; i <= 10000; ++i) {
        t = find_repeated_sqrt(i);
        if ((t.size()-1) % 2 != 0)
            ++c;
    }
    cout << c << " odd period sqrts up to 10000\n";
}


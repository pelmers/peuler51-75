#include "euler.hpp"

int main(void);

int main(void) {
    int c = 0;
    for (int i = 2; i <= 10000; ++i)
        if ((find_repeated_sqrt(i).size()-1) % 2 != 0)
            ++c;
    cout << c << " odd period sqrts up to 10000\n";
}


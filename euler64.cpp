#include "euler.hpp"

using std::floor;

int sqrt_period_length(int);
int main(void);

int sqrt_period_length(int n) {
    int len = 0;
    int s = sqrt(n);
    if (s*s == n)
        return 0;
    int d = 1;
    int m = 0;
    int a = s;
    while (a != 2*s) {
        m = d * a - m;
        d = (n - m * m) / d;
        a = (s + m) / d;
        ++len;
    }
    return len;
}

int main(void) {
    int c = 0;
    for (int i = 2; i <= 10000; ++i)
        if ((sqrt_period_length(i) % 2) != 0)
            ++c;
    cout << c << " odd period sqrts up to 10000\n";
}


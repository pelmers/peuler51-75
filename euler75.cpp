#include "euler.hpp"

int main(void) {
    // a^2 + b^2 = c^2
    // let a = 2mn
    // let b = m^2 - n^2
    // (2mn)^2 + (m^2 - n^2)^2 = c^2
    // c^2 = 4(mn)^2 + m^4 - 2(mn)^2 + n^4
    // c^2 = m^4 + 2(mn)^2 + n^4
    // c = m^2 + n^2
    // l = 2m(n + m)
    // This will generate all primitive pythagorean triples (plus some not)
    long counter;
    vector<int> l_values(1500000 + 1);
    for (long m = 1; m < 1500000; ++m) {
        for (long l, n = m+1; n < 1500000; ++n) {
            l = n*(n+m) << 1;
            if (l > 1500000)
                break;
            if (are_coprime(2*m*n, n*n-m*m) && (counter = 1))
                do { ++l_values[l*counter++]; } while (counter*l <= 1500000);
        }
    }
    counter = 0;
    for (int i = 1; i < 1500000 + 1; ++i)
        if (l_values[i] == 1)
            ++counter;
    cout << counter << " values of L found <= 1500000\n";
    return 0;
}

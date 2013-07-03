#include "euler.hpp"

int main(void);

int main(void) {
    vector<long> totients = totient_sieve(1000000 + 1);
    double max = 1.0;
    int maxn = 0;
    for (double term, n = 1; n <= 1000000; ++n) {
        term = (double) n / (double) totients[n];
        if (term > max) {
            max = term;
            maxn = n;
        }
    }
    cout << maxn << " / " << totients[maxn] << " = " << max << endl;
    return 0;
}

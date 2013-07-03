#include "euler.hpp"

int main(void) {
    long sum = 0;
    vector<long> totients_million = totient_sieve(1000000 + 1);
    for (int i = 2; i < totients_million.size(); ++i)
        sum += totients_million[i];
    cout << sum << endl;
}


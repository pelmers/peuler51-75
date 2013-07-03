#include "euler.hpp"

static const long factorial_table[] = {
    1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

long factorial_dsum(long n) {
    long s;
    for (s = 0; n > 0; n /= 10)
        s += factorial_table[n % 10];
    return s;
}

int main(void) {
    int total = 0;
    long sumf;
    std::unordered_set<long> repeats;
    for (int clength, i = 2; i < 1000000; ++i) {
        clength = 2;
        repeats.clear();
        sumf = factorial_dsum(i);
        repeats.insert(sumf);
        while (clength < 60) {
            sumf = factorial_dsum(sumf);
            if (repeats.find(sumf) != repeats.end())
                break;
            repeats.insert(sumf);
            ++clength;
        }
        if (clength == 60)
            ++total;
    }
    cout << "Total: " << total << endl;
    return 0;
}


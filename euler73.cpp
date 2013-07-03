#include "euler.hpp"

int main(void) {
    long total = 3;
    for (int start, end, denom = 9; denom <= 12000; ++denom)
        for (int numer = denom / 3; numer < denom / 2; ++numer)
            if (are_coprime(numer, denom))
                ++total;
    cout << "Answer: " << total << endl;
}

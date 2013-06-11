#include "euler.hpp"

int main(int, char**);

int main(int argc, char** argv) {
    // primes up to 1 billion
    vector<unsigned int> primes = prime_sieve(1000000000);
    int num_primes = 8;
    int diagonals = 13;
    int topright = 31;
    int topleft = 37;
    int botleft = 43;
    int common_diff = 6;
    int next_diff = 18;
    while (((double)num_primes / (double)diagonals) >= 0.1) {
        next_diff += 8;
        common_diff += 2;
        topright += next_diff;
        topleft = topright + common_diff;
        botleft = topleft + common_diff;
        if (std::binary_search(primes.begin(), primes.end(), topright))
            ++num_primes;
        if (std::binary_search(primes.begin(), primes.end(), topleft))
            ++num_primes;
        if (std::binary_search(primes.begin(), primes.end(), botleft))
            ++num_primes;
        diagonals += 2;
    }
    cout << "Side length: " << (diagonals - 1)/2 << '\n';
    cout << "Ratio is " << (double)num_primes/diagonals << '\n';
    return 0;
}

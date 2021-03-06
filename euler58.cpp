#include "euler.hpp"

int main(int, char**);

int main(int argc, char** argv) {
    // primes up to 1 billion
    int num_primes = 8;
    int sides = 6;
    int topright;
    int topleft;
    int botleft;
    while ((double)num_primes / ((double)(sides*2 + 1)) >= 0.1) {
        sides += 2;
        botleft = (sides+1)*(sides+1) - sides;
        topleft  = botleft - sides;
        topright = topleft - sides;
        if (is_prime(topright))
            ++num_primes;
        if (is_prime(topleft))
            ++num_primes;
        if (is_prime(botleft))
            ++num_primes;
    }
    cout << "Side length: " << sides+1 << '\n';
    cout << "Ratio is " << (double)num_primes/(sides*2+1) << '\n';
    cout << num_primes << " / " << sides*2 + 1 << '\n';
    return 0;
}

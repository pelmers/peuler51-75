#include "euler.hpp"

inline int term(int);
std::pair<mpz_class, mpz_class> e_fraction(int);
int main(void);

int term(int n) {
    return (n == 0) ? 2 : (n % 3 == 2) ? (2*(n+1)/3) : 1;
}

std::pair<mpz_class, mpz_class> e_fraction(int k) {
    std::pair<mpz_class, mpz_class> p(term(k),1);
    // go up the fraction and multiply/add
    while (k --> 0) {
        p.second += term(k)*p.first;
        std::swap(p.first, p.second); // get the reciprocal
    }
    return p;
}

int main(void) {
    std::pair<mpz_class, mpz_class> p = e_fraction(100 - 1);
    cout << "Sum of digits in 100th fraction for e: " << 
        digit_sum(p.first) << '\n';
    cout << p.first << " / " << p.second << endl;
    return 0;
}

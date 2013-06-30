#include "euler.hpp"

inline int term(int);
int main(void);

int term(int n) {
    return (n == 0) ? 2 : (n % 3 == 2) ? (2*(n+1)/3) : 1;
}

int main(void) {
    std::pair<mpz_class, mpz_class> p = repeated_convergent(100 - 1, *term);
    cout << "Sum of digits in 100th fraction for e: " << 
        digit_sum(p.first) << '\n';
    cout << p.first << " / " << p.second << endl;
    return 0;
}

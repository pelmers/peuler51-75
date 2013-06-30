#include "euler.hpp"

inline bool is_square(int);
mpz_class diophantine_66(int);
int main(void);

bool is_square(int n) {
    return (std::fmod(sqrt(n), 1) == 0);
}

std::pair<mpz_class, mpz_class> pell_equation(int d) {
    /* Return the pair (x,y) that is a solution to Pell's equation,
     * x^2 - dy^2 = 1
     * where d is given and the returned x is minimized
     * If d is a square, return (0,0)
     */
    std::pair<mpz_class, mpz_class> p(0,0);
    vector<int> t = find_repeated_sqrt(d);
    if (is_square(d))
        return p;
    // Pell's equation is closely related to the continued fraction of sqrt(d)
    // --> x^2 - dy^2 = 1
    //           dy^2 = x^2 - 1
    //              d = (x^2 - 1) / (y^2)
    //       sqrt(d) ~= sqrt(x^2 / y^2) **one becomes insignificant
    //       sqrt(d) ~= x / y
    // Therefore x^2/y^2 is a fractional approximation of sqrt(d), given by
    // one of its convergent fractions
    for (int i = 0; i < INT_MAX-1 ; ++i) {
        p = repeated_convergent(i, t);
        if ((p.first*p.first - d*p.second*p.second) == 1)
            return p;
    }
    // no solution found? shouldn't happen
    return p;
}

int main(void) {
    std::pair<mpz_class, mpz_class> p;
    mpz_class max(0);
    int maxn;
    for (int d = 2; d <= 1000; ++d) {
        p = pell_equation(d);
        if (p.first > max) {
            max = p.first;
            maxn = d;
        }
    }
    cout << "Largest x: " << max << endl;
    cout << "Given by d = " << maxn << endl;
    return 0;
}

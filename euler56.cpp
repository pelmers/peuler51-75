#include "euler.hpp"

int main(int, char**);

int main(int argc, char** argv) {
    int sum, maxsum = 0;
    mpz_class bignum;
    for (int a = 1; a < 100; ++a) {
        for (int b = 1; b < 100; ++b) {
            mpz_ui_pow_ui(bignum.get_mpz_t(), a, b);
            sum = digit_sum(bignum);
            if (sum > maxsum)
                maxsum = sum;
        }
    }
    cout << maxsum << '\n';
    return 0;
}

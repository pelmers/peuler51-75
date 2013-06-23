#include "euler.hpp"

int main(void);

int main(void) {
    int count = 0;
    mpz_class power;
    for (int exp, i = 1; i < 10; ++i) {
        exp = 1;
        power = i;
        while (count_digits(power) == exp)
            mpz_ui_pow_ui(power.get_mpz_t(), i, ++exp);
        count += exp - 1;
    }
    cout << count << " found" << '\n';
    return 0;
}

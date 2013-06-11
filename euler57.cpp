#include "euler.hpp"

static const double magic = 2.414213562373;

int main(int, char**);

int main(int argc, char** argv) {
    mpf_class numer_dec(1393.0);
    mpf_class denom_dec(985.0);
    int iters = 8;
    int c = 1; // counter variable
    while (iters < 1000) {
        numer_dec = numer_dec*magic + 0.8;
        denom_dec = denom_dec*magic + 0.8;
        mpz_class numer(numer_dec);
        mpz_class denom(denom_dec);
        if (count_digits(numer) > count_digits(denom))
            ++c;
        //cout << numer << '/' << denom << '\n';
        ++iters;
    }
    cout << c << " found.\n";
    return 0;
}

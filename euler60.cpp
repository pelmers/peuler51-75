#include "euler.hpp"

int main(void);

int main(void) {
    vector<unsigned int> primes = prime_sieve(10000);
    int end = primes.size();
    // start at primes[1] since 2 can't concat any primes
    for (int i = 1; i < end; ++i) {
        for (int j = i+1; j < end; ++j) {
            if (!(is_prime(concat_nums(primes[i], primes[j]),primes) &&
                    is_prime(concat_nums(primes[j], primes[i]),primes)))
                continue;
            for (int k = j+1; k < end; ++k) {
                if (!(is_prime(concat_nums(primes[i],primes[k]),primes) &&
                        is_prime(concat_nums(primes[k],primes[i]),primes) &&
                        is_prime(concat_nums(primes[j],primes[k]),primes) &&
                        is_prime(concat_nums(primes[k],primes[j]),primes)))
                    continue;
                for (int l = k+1; l < end; ++l) {
                    if (!(is_prime(concat_nums(primes[i],primes[l]),primes) &&
                            is_prime(concat_nums(primes[l],primes[i]),primes) &&
                            is_prime(concat_nums(primes[j],primes[l]),primes) &&
                            is_prime(concat_nums(primes[l],primes[j]),primes) &&
                            is_prime(concat_nums(primes[k],primes[l]),primes) &&
                            is_prime(concat_nums(primes[l],primes[k]),primes)))
                        continue;
                    for (int m = l+1; m < end; ++m) {
                        if (!(is_prime(concat_nums(primes[i],primes[m]),primes) &&
                                    is_prime(concat_nums(primes[m],primes[i]),primes) &&
                                    is_prime(concat_nums(primes[j],primes[m]),primes) &&
                                    is_prime(concat_nums(primes[m],primes[j]),primes) &&
                                    is_prime(concat_nums(primes[k],primes[m]),primes) &&
                                    is_prime(concat_nums(primes[m],primes[k]),primes) &&
                                    is_prime(concat_nums(primes[l],primes[m]),primes) &&
                                    is_prime(concat_nums(primes[m],primes[l]),primes)))
                            continue;
                        cout << primes[i] << " + " << primes[j] << " + " <<
                            primes[k] << " + " << primes[l] << " + " << primes[m] << " = " <<
                            primes[i]+primes[j]+primes[k]+primes[l]+primes[m] << endl;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}


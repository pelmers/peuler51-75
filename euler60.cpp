#include "euler.hpp"

int main(void);

int main(void) {
    vector<long> primes = prime_sieve(10000);
    int end = primes.size();
    // start at primes[1] since 2 can't concat any primes
    for (int i = 1; i < end; ++i) {
        for (int j = i+1; j < end; ++j) {
            if (!(is_prime(concat_nums(primes[i], primes[j])) &&
                    is_prime(concat_nums(primes[j], primes[i]))))
                continue;
            for (int k = j+1; k < end; ++k) {
                if (!(is_prime(concat_nums(primes[i],primes[k])) &&
                        is_prime(concat_nums(primes[k],primes[i])) &&
                        is_prime(concat_nums(primes[j],primes[k])) &&
                        is_prime(concat_nums(primes[k],primes[j]))))
                    continue;
                for (int l = k+1; l < end; ++l) {
                    if (!(is_prime(concat_nums(primes[i],primes[l])) &&
                            is_prime(concat_nums(primes[l],primes[i])) &&
                            is_prime(concat_nums(primes[j],primes[l])) &&
                            is_prime(concat_nums(primes[l],primes[j])) &&
                            is_prime(concat_nums(primes[k],primes[l])) &&
                            is_prime(concat_nums(primes[l],primes[k]))))
                        continue;
                    for (int m = l+1; m < end; ++m) {
                        if (!(is_prime(concat_nums(primes[i],primes[m])) &&
                                    is_prime(concat_nums(primes[m],primes[i])) &&
                                    is_prime(concat_nums(primes[j],primes[m])) &&
                                    is_prime(concat_nums(primes[m],primes[j])) &&
                                    is_prime(concat_nums(primes[k],primes[m])) &&
                                    is_prime(concat_nums(primes[m],primes[k])) &&
                                    is_prime(concat_nums(primes[l],primes[m])) &&
                                    is_prime(concat_nums(primes[m],primes[l]))))
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


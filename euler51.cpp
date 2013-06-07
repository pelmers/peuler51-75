#include "euler.hpp"

int replace_spots(int, vector<unsigned int>&, bool show=false);
int main(int, char**);

int replace_spots(int num, vector<unsigned int>& primes, bool show) {
    /**
     * Return the number of primes generated by replacing all of the
     * equal digits in num with 0-9
     * If show is true, print each prime generated
     */
    int n = 0;
    vector<int> s = split_number(num);
    vector<int> to_replace;
    for (int i = 0; i < (int)s.size() - 1; ++i) {
        for (int j = i + 1; j < (int)s.size() - 1; ++j) {
            if (s[i] == s[j]) {
                // we must replace digits that are the same
                to_replace.push_back(j);
                to_replace.push_back(i);
            }
        }
    }
    // a multiple of three digits must be replaced
    // if not, at least 3 of the 10 replacements will be divisible by 3
    if (to_replace.size() < 3)
        return 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < (int)to_replace.size(); ++j)
            // replace each digit labelled in to_replace with 0-9
            s[to_replace[j]] = i;
        if (s[0] == 0)
            // first digit is 0, won't work
            continue;
        if (std::binary_search(primes.begin(), primes.end(),
                join_number(s))) {
            // the number s is prime
            ++n;
            if (show)
                // print if we want to show
                cout << join_number(s) << '\n';
        }
    }
    return n;
}

int main(int argc, char** argv) {
    vector<unsigned int> primes = prime_sieve(1000000);
    int max = 0;
    int r, maxn = 0;
    for (auto it = primes.begin(); it != primes.end(); ++it) {
        // visit each prime and see how many it generates
        if (*it < 10000)
            // we know it must be greater than 10000
            continue;
        r = replace_spots(*it, primes);
        if (r > max) {
            max = r;
            maxn = *it;
        }
    }
    cout << maxn << " makes " << max << " primes" << '\n';
    replace_spots(maxn, primes, true);
    return 0;
}

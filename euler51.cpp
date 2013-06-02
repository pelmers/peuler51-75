#include "euler.hpp"

int replace_spots(int num, vector<unsigned int>& primes, bool show=false);
int main(int argc, char** argv);

int replace_spots(int num, vector<unsigned int>& primes, bool show) {
    int n = 0;
    vector<int> s = split_number(num);
    vector<int> to_replace;
    for (int i = 0; i < (int)s.size() - 1; ++i) {
        for (int j = i + 1; j < (int)s.size() - 1; ++j) {
            if (s[i] == s[j]) {
                to_replace.push_back(j);
                to_replace.push_back(i);
            }
        }
    }
    if (to_replace.size() < 3) // for condition that sum of digits % 3 != 0
        return 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < (int)to_replace.size(); ++j)
            s[to_replace[j]] = i;
        if (s[0] == 0)
            continue;
        if (std::binary_search(primes.begin(), primes.end(),
                join_number(s))) {
        ++n;
        if (show)
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
        if (*it < 10000)
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

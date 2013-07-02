#include "euler.hpp"

int main(void);

int main(void) {
    vector<int> totients = totient_sieve(10000000);
    int min_n = 9;
    for (int i = 2; i < 10000000; ++i)
        // Let the O(1) operation go first
        if (i / double(totients[i]) < min_n / double(totients[min_n]))
            // This one is O(n)
            if (contain_same_digits(totients[i], i))
                min_n = i;
    cout << "Answer: " << min_n << endl;
    return 0;
}

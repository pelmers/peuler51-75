#include "euler.hpp"

int main(int, char**);

int main(int argc, char** argv) {
    // keep track of how many we find
    int count = 0;
    // Very straightforward
    for (int n = 23; n <= 100; ++n)
        for (int k = 1; k < n; ++k)
            if (combinations(n,k) > 1000000)
                ++count;
    cout << "Answer " << count << '\n';
    return 0;
}

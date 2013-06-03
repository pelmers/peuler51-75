#include "euler.hpp"

int main(int argc, char** argv);

int main(int argc, char** argv) {
    int count = 0;
    for (int n = 23; n <= 100; ++n)
        for (int k = 1; k < n; ++k)
            if (combinations(n,k) > 1000000)
                ++count;
    cout << "Answer " << count << '\n';
    return 0;
}

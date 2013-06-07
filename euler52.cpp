#include "euler.hpp"

int main(int, char**);

int main(int argc, char** argv) {
    int x = 100; // answer will be greater than 100
    // go until we find the answer
    while (1) {
        // Fairly straight forward: just make sure they all have same digits
        if (contain_same_digits(x, 2*x) &&
                contain_same_digits(x, 3*x) &&
                contain_same_digits(x, 4*x) &&
                contain_same_digits(x, 5*x) &&
                contain_same_digits(x, 6*x)) {
            cout << "Answer: " << x << '\n';
            break;
        }
        ++x;
    }
    return 0;
}

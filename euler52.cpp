#include "euler.hpp"

int main(int argc, char** argv);

int main(int argc, char** argv) {
    int x = 100;
    while (1) {
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

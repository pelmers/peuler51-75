#include "euler.hpp"

bool is_lychrel(int);
int main(int, char**);

bool is_lychrel(int num) {
    /**Determine whether num is Lychrel
     * Lychrel number: a whose continued addition of reverses is never
     * a palindrome.
     * @return true if num is lychrel, else false
     */
    
    mpz_class lnum(num);
    for (int iters = 0; iters < 50; ++iters) {
        lnum += reverse_number(lnum);
        string num_str(lnum.get_str());
        if (is_palindrome(num_str.begin(), num_str.end())) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    int c = 0;
    for (int i = 1; i <= 10000; ++i)
        if (is_lychrel(i))
            ++c;
    cout << c << " Lychrel numbers found below 10000\n";
    //is_lychrel(10677);
    return 0;
}

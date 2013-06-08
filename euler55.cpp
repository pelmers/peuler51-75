#include "euler.hpp"

mpz_class reverse_number55(mpz_class num);
vector<int> split_number(mpz_class num);
bool is_lychrel(int);
int main(int, char**);

mpz_class reverse_number55(mpz_class num) {
    vector<int> split_n = split_number(num);
    while (split_n[0] == 0)
        split_n.erase(split_n.begin());
    vector<char> split_c;
    for (int i = 0; i < (int)split_n.size(); ++i)
        split_c.push_back(split_n[i]+48);
    string split_s(split_c.begin(), split_c.end());
    //cout << split_s << '\n';
    return mpz_class(split_s);
}

vector<int> split_number(mpz_class num) {
    /**
     * Split the digits of a long number into a vector
     */
    vector<int> split;
    for (; num > 0; num /= 10)
        split.push_back(mpz_get_ui(num.get_mpz_t()) % 10);
    return split;
}


bool is_lychrel(int num) {
    /**Determine whether num is Lychrel
     * Lychrel number: a whose continued addition of reverses is never
     * a palindrome.
     * @return true if num is lychrel, else false
     */
    
    mpz_class lnum(num);
    for (int iters = 0; iters < 50; ++iters) {
        lnum = lnum + reverse_number55(lnum);
        vector<int> num_split = split_number(lnum);
        if (is_palindrome(num_split.begin(), num_split.end())) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    int c = 0;
    for (int i = 1; i <= 10000; ++i) {
        if (is_lychrel(i))
            ++c;
        //cout << i << '\n';
    }
    cout << c << " Lychrel numbers found below 10000\n";
    //is_lychrel(10677);
    return 0;
}

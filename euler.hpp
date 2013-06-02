#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

using std::endl;        using std::cout;
using std::cin;         using std::vector;
using std::sqrt;

inline int count_digits(int num);

int count_digits(int num) {
    /* Return the number of digits in num
     */
    int c;
    for (c = 0; num > 0; num /= 10, ++c);
    return c;
}

vector<int> split_number(int num) {
    /* Split the digits of a number into a vector
     */
    vector<int> split;
    for (; num > 0; num /= 10)
        split.push_back(num % 10);
    std::reverse(split.begin(), split.end());
    return split;
}

int join_number(vector<int> split) {
    /* Join together the digits of a split number in a vector
     */
    int n = 0;
    for (int i = 0, e = split.size(); i < e; ++i)
        n += split[i] * std::pow(10, (e - i - 1));
    return n;
}

template <class T>
void swap(T &x, T &y) {
    T z(x);
    x = y;
    y = z;
}

template <class InputIterator>
void print_sequence(const InputIterator& start, const InputIterator& end) {
    cout << "[";
    for (auto it = start; it != end; ++it)
        cout << *it << ", ";
    cout << "]\n";
}

bool is_prime(int n, const vector<unsigned int>& primes) {
    // Determine primacy of number n given vector primes,
    // containing all primes less than the square root of n
    int r = sqrt(n) + 1;
    auto end = primes.end();
    for (auto it = primes.begin(); it != end && (*it) < r; ++it) {
        if (!(n % (*it)))
            return false;
    }
    return true;
}

vector<unsigned int> find_primes(unsigned int number) {
    /* Return a vector of number primes, where number >= 2
     */
    vector<unsigned int> primes = {2, 3};
    primes.reserve(number);
    unsigned int p = 1;
    while (primes.size() < number) {
        // skip multiples of 2 and 3
        p += 4;
        if (is_prime(p, primes))
            primes.push_back(p);
        if (p == number)
            return primes;
        p += 2;
        if (is_prime(p, primes))
            primes.push_back(p);
    }
    return primes;
}

vector<unsigned int> prime_sieve(unsigned int upper_limit) {
    /* Return a vector of all primes <= upper_limit
     */
    ++upper_limit;
    vector<bool> sieve(upper_limit, true);
    vector<unsigned int> primes;
    for (unsigned int i = 2; i < upper_limit; ++i) {
        if (sieve[i]) {
            for (unsigned int j = 2*i; j < upper_limit; j += i)
                sieve[j] = false;
            primes.push_back(i);
        }
    }
    return primes;
}

template <class BidirectionalIterator>
bool is_palindrome(BidirectionalIterator start, BidirectionalIterator end) {
    /* True if palindrome, else false
     */
    if (start == end - 1)
        return true;
    --end;
    while (start <= end) {
        if (*start == *end)
        {
            ++start;
            --end;
        }
        else
            return false;
    }
    return true;
}


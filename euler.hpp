#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <gmpxx.h>

using std::endl;        using std::cout;
using std::cin;         using std::vector;
using std::sqrt;        using std::string;
using std::size_t;

// non-template forward declares
mpz_class combinations(int, int);
inline int count_digits(int);
vector<int> split_number(int);
int join_number(vector<int>);
bool contain_same_digits(int, int);
bool is_prime(int, const vector<unsigned int>&);
vector<unsigned int> find_primes(unsigned int);
vector<unsigned int> prime_sieve(unsigned int);

// template forward declares
template <class T> void swap(T&, T&);

template <class InputIterator>
void print_sequence(const InputIterator&, const InputIterator&);

template <class BidirectionalIterator>
bool is_palindrome(BidirectionalIterator, BidirectionalIterator);

template <class InputIterator, class T>
int count_num_equal(InputIterator, InputIterator, const T&);

/* ~ END OF FORWARD DECLARATIONS ~ */

mpz_class combinations(int n, int r) {
    /**
     * Return the number of combinations of r elements from n
     * Formula: n!/(n!(n-r)!)
     */
    if (n <= r)
        return 1;
    mpz_class num = 1;
    for (int i = r + 1; i <= n; ++i)
        num *= i;
    mpz_class denom = 1;
    for (int i = 2; i <= (n-r); ++i)
        denom *= i;
    return num / denom;
}

int count_digits(int num) {
    /**
     * Return the number of digits in num
     */
    int c;
    for (c = 0; num > 0; num /= 10, ++c);
    return c;
}

vector<int> split_number(int num) {
    /**
     * Split the digits of a number into a vector
     */
    vector<int> split;
    for (; num > 0; num /= 10)
        split.push_back(num % 10);
    // Reverse the digits
    std::reverse(split.begin(), split.end());
    return split;
}

int join_number(vector<int> split) {
    /**
     * Join together the digits of a split number in a vector
     */
    int n = 0;
    for (int i = 0, e = split.size(); i < e; ++i)
        n += split[i] * std::pow(10, (e - i - 1));
    return n;
}

bool contain_same_digits(int num1, int num2) {
    /**
     * Return true if num1 and num2 contain the same digits
     */
    // make a table of the frequency of each digit in each num
    int nums1[10];
    int nums2[10];
    std::memset(nums1, 0, sizeof(int)*10);
    std::memset(nums2, 0, sizeof(int)*10);
    // mark the number of times each digit is used in each num
    for (; num1 > 0; num1 /= 10)
        ++nums1[num1 % 10];
    for (; num2 > 0; num2 /= 10)
        ++nums2[num2 % 10];
    for (int i = 0; i < 10; ++i)
        // make sure all digit frequencies are equal
        if (nums1[i] != nums2[i])
            return false;
    return true;
}

bool is_prime(int n, const vector<unsigned int>& primes) {
    /**
     * Determine primacy of number n given vector primes,
     * containing all primes less than the square root of n
     */
    unsigned int r = sqrt(n) + 1;
    auto end = primes.end();
    for (auto it = primes.begin(); it != end && (*it) < r; ++it) {
        if (!(n % (*it)))
            return false;
    }
    return true;
}

vector<unsigned int> find_primes(unsigned int number) {
    /**
     * Return a vector of number primes, where number >= 2
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
    /**
     * Return a vector of all primes <= upper_limit
     * Implements sieve of Eratosthenes
     */
    ++upper_limit;
    vector<bool> sieve(upper_limit, true);
    vector<unsigned int> primes;
    for (unsigned int i = 2; i < upper_limit; ++i) {
        if (sieve[i]) {
            for (unsigned int j = i*i; j < upper_limit; j += i)
                sieve[j] = false;
            primes.push_back(i);
        }
    }
    return primes;
}

template <class T>
void swap(T &x, T &y) {
    /**
     * Swap elements x and y
     */
    T z(x);
    x = y;
    y = z;
}

template <class InputIterator>
void print_sequence(const InputIterator& start, const InputIterator& end) {
    /**
     * Print a sequence to standard out, comma-separated
     * Example: [1, 2, 3, 4, ]
     */
    cout << "[";
    for (auto it = start; it != end; ++it)
        cout << *it << ", ";
    cout << "]\n";
}

template <class BidirectionalIterator>
bool is_palindrome(BidirectionalIterator start, BidirectionalIterator end) {
    /**
     * True if the sequence is a palindrome, else false
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


template <class InputIterator, class T>
int count_num_equal(InputIterator start, InputIterator end, const T& val) {
    /**
     * Return the number of elements between start and end equal to val
     */
    int c = 0;
    for (auto it = start; it != end; ++it)
        if (*it == val)
            ++c;
    return c;
}

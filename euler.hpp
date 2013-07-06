#ifndef EULER_INC_
#define EULER_INC_

// C includes
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
// IO
#include <iostream>
#include <fstream>
// containers
#include <array>
#include <vector>
#include <unordered_set>
#include <map>
// other
#include <string>
#include <utility>
#include <algorithm>
#include <gmpxx.h>

using std::endl;        using std::cout;
using std::cin;         using std::vector;
using std::sqrt;        using std::string;
using std::size_t;

class PrimeWheel {
    public:
        PrimeWheel() {
            current = 0;
            holes = { { 1,2,2,4,2,4,2,4,6,2,6,4,2,4,6,6,2,6,4,2,6,4,6,8,4,
                2,4,2,4,8,6,4,6,2,4,6,2,6,6,4,2,4,6,2,6,4,2,4,2,10,2,10 } };
        };
        inline int next() {
            if (current == holes.size())
                current = 4;
            return holes[current++];
        };
        inline int start() const { return 2; };
    private:
        int current;
        std::array<int, 52> holes;
};


// non-template forward declares
mpz_class combinations(int, int);
inline int count_digits(long);
inline int count_digits(const mpz_class&);
int reverse_number(int);
mpz_class reverse_number(const mpz_class&);
vector<int> split_number(int);
vector<int> split_number(mpz_class);
int join_number(vector<int>);
int digit_sum(int);
int digit_sum(const mpz_class&);
inline unsigned long concat_nums(unsigned long, unsigned long);
bool contain_same_digits(int, int);
bool is_prime(long);
int gcd(int, int);
inline bool are_coprime(long, long);
vector<long> prime_sieve(long);
vector<long> totient_sieve(long);
vector<int> find_repeated_sqrt(int);

// template forward declares
template <class InputIterator>
void print_sequence(const InputIterator&, const InputIterator&);

template <class BidirectionalIterator>
bool is_palindrome(BidirectionalIterator, BidirectionalIterator);

template <class Callable>
std::pair<mpz_class, mpz_class> repeated_convergent(int, Callable);
// takes a vector and creates a Callable for it
std::pair<mpz_class, mpz_class> repeated_convergent(int, const vector<int>&);

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

int count_digits(long num) {
    /**
     * Return the number of digits in num
     * Ex: 1318 -> 4
     */
    int c;
    for (c = 0; num > 0; num /= 10, ++c);
    return c;
}

int count_digits(const mpz_class& bignum) {
    /**
     * Return the number of digits in bignum
     * Ex: 12345678909876543210 -> 20
     */
    return bignum.get_str().size();
}

int reverse_number(int num) {
    /**
     * Return the reverse of a number
     * Ex: 47 -> 74
     */
    int r = 0;
    int d = count_digits(num);
    for (int i = 1; i <= d; ++i) {
        r += std::pow(10, (d - i)) * (num % 10);
        num /= 10;
    }
    return r;
}

mpz_class reverse_number(const mpz_class& bignum) {
    /**
     * Return the reverse of a big number
     */
    string bigstr(bignum.get_str());
    std::reverse(bigstr.begin(), bigstr.end());
    return mpz_class(bigstr, 10);
}

vector<int> split_number(int num) {
    /**
     * Split the digits of a number into a vector
     * Ex: 2345 -> <2,3,4,5>
     */
    vector<int> split;
    for (; num > 0; num /= 10)
        split.push_back(num % 10);
    // Reverse the digits
    std::reverse(split.begin(), split.end());
    return split;
}

vector<int> split_number(mpz_class num) {
    /**
     * Split the digits of a big number into a vector
     */
    vector<int> split;
    for (; num > 0; num /= 10)
        split.push_back(mpz_get_ui(num.get_mpz_t()) % 10);
    return split;
}

int join_number(vector<int> split) {
    /**
     * Join together the digits of a split number in a vector
     * Ex: <2,3,4,5> -> 2345
     */
    int n = 0;
    for (int i = 0, e = split.size(); i < e; ++i)
        n += split[i] * std::pow(10, (e - i - 1));
    return n;
}

int digit_sum(int num) {
    /**Find sum of digits
     * Return the sum of the digits in the number
     */
    int sum;
    for (sum = 0; num > 0; num /= 10)
        sum += num % 10;
    return sum;
}

int digit_sum(const mpz_class& bignum) {
    /**Find sum of digits in a bignum
     * Return the sum of the digits in the number
     */
    int sum = 0;
    string bigstr(bignum.get_str());
    for (int i = 0; i < (int)bigstr.size(); ++i)
        // implicit conversion from char to int
        sum += bigstr[i] - '0';
    return sum;
}

unsigned long concat_nums(unsigned long num1, unsigned long num2) {
    /**Concatenate numbers like strings
     * Make a new number starting with num1 followed by num2
     */
    return (num1 * std::pow(10, count_digits(num2)) + num2);
}

bool contain_same_digits(int num1, int num2) {
    /**
     * Return true if num1 and num2 contain the same digits
     */
    // make a table of the frequency of each digit in each num
    int nums1[10] = { 0 };
    int nums2[10] = { 0 };
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

bool is_prime(long n) {
    /**
     * Determine primacy of number n given vector of primes,
     * containing all primes less than the square root of n
     */
    PrimeWheel wheel;
    unsigned int r = sqrt(n);
    for (long p = wheel.start(); p <= r; p += wheel.next()) {
        if (!(n % p))
            return false;
    }
    return true;
}

long gcd(long a, long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool are_coprime(long a, long b) {
    return (gcd(a, b) == 1);
}

vector<long> prime_sieve(long upper_limit) {
    /**
     * Return a vector of all primes <= upper_limit
     * Implements sieve of Eratosthenes with a factor wheel
     */
    PrimeWheel wheel;
    vector<bool> sieve(upper_limit, false);
    vector<long> primes;
    for (long i = wheel.start(); i <= upper_limit; i += wheel.next()) {
        if (!(sieve[i])) {
            for (long j = i*i; j <= upper_limit; j += i)
                sieve[j] = true;
            primes.push_back(i);
        }
    }
    return primes;
}

vector<long> totient_sieve(long upper) {
    /*
     * Return a vector of size upper_limit whose elements are the totient
     * of every number < upper_limit
     */
    PrimeWheel wheel;
    vector<long> totes(upper);
    // Initialize the totient of n to itself
    std::iota(totes.begin(), totes.end(), 0);
    for (long i = wheel.start(); i < upper; i += wheel.next())
        if (totes[i] == i)
            // Then this number is prime, so everything < i is totative
            // Find every multiple of this prime and multiply by (1 - 1/p)
            // --> Refactored into multiplication by ((p - 1) / p)
            // --> to stay integral throughout the operation
            for (long j = i; j < upper; j += i)
                totes[j] = (totes[j] / i) * (i - 1);
    return totes;
}

vector<int> find_repeated_sqrt(int num) {
    /* Return a vector in the form of [m, a0, a1, ... an]
     * where m is the first square less than sqrt(num) and
     * a_n is the sequence of repeated terms in the continued fraction
     * If num is square, return a single element vector containing num
     * E.g: sqrt(2) = 2 + 1
     *                    -----------
     *                    2 + 1
     *                        -------
     *                        2 + ...
     *
     * find_repeated_sqrt(2) -> [1, 2]
     */
    // initialize terms with the first number
    vector<int> terms{int(sqrt(num))};
    if (terms[0] * terms[0] == num)
        return terms;
    int d(1), m(0), a(terms[0]);
    while (a != 2*terms[0]) {
        m = d * a - m;
        d = (num - m * m) / d;
        a = (terms[0] + m) / d;
        terms.push_back(a);
    }
    return terms;
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
        if (*start == *end) {
            ++start;
            --end;
        }
        else
            return false;
    }
    return true;
}

template <class Callable>
std::pair<mpz_class, mpz_class> repeated_convergent(int k, Callable term_func) {
    /* Return a pair of numerator, denominator that is the (k-1)th convergent
     * of the continued fraction where each (k-1)th term is given by term_func
     *
     * E.g: let t be the term_func of e.
     *      t(0) = 2
     *      t(n) = (n % 3 == 2) ? (2*(n+1)/3) : 1;
     * as a lambda:
     * [](int n) { return (n == 0) ? 2 : (n % 3 == 2) ? (2*(n+1)/3) : 1; }
     */
    std::pair<mpz_class, mpz_class> frac(term_func(k), 1);
    while (k --> 0) {
        frac.second += term_func(k) * frac.first;
        std::swap(frac.first, frac.second); }
    return frac;
}

std::pair<mpz_class, mpz_class> repeated_convergent(int k, const vector<int>& terms) {
    /* Return a pair of numerator, denominator that is the (k-1)th convergent
     * of the continued fraction defined by terms,
     * where terms[0] is the first term, and terms[1] to terms[n] are
     * repeated ad infinitum
     *
     * E.g: terms of sqrt(2): [1, 2]
     * repeated_convergent(0, [1, 2]) -> std::pair<mpz, mpz>(1, 1)
     * repeated_convergent(4, [1, 2]) -> std::pair<mpz, mpz>(41, 29)
     */
    // create functor which simulates cycling of tail of terms
    return repeated_convergent(k, [&terms](int t) {
            return (t == 0) ? terms[0]:terms[(t-1) % (terms.size()-1) + 1]; });
}

#endif

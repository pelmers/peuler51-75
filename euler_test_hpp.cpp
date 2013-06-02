#include "euler.hpp"

int main(int argc, char** argv);

int main(int argc, char** argv) {
    /*int x = 5;
    int y = 8;
    vector<int> z = {1,2,3,2,1};
    int b[] = {1, 2, 3, 4, 5};
    swap(x,y);
    if (x == 8 && y == 5)
        cout << "Swap works...\n";
    print_sequence(z.begin(), z.end());
    print_sequence(&(b[0]), &(b[5]));
    vector<unsigned int> primes = find_primes(75000);
    cout << primes[70000] << " : prime generator works" << '\n';
    if (is_palindrome(z.begin(), z.end()))
        cout << "Palindromer working" << '\n';
    if (is_palindrome(&(b[0]), &(b[5])))
        cout << "J/k, not working..." << '\n';*/
    vector<unsigned int> primes2 = prime_sieve(10000000);
    cout << primes2.size() << " primes found below ten M" << '\n';
    return 0;
}

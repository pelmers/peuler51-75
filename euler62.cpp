#include "euler.hpp"

long hash_number(long);
int main(void);

long hash_number(long num) {
    // return a hash of the number based on its digits
    // every permutation of num has the same hash
    long hash = 0;
    int nums[10];
    std::memset(nums, 0, sizeof(int)*10);
    for (; num > 0; num /= 10)
        ++nums[num % 10];
    for (int i = 0; i < 10; ++i)
        hash += nums[i]*std::pow(10, i);
    return hash;
}

int main(void) {
    long cube;
    long hash;
    std::map<long, vector<long> > table;
    for (int i = 2; i < 10000; ++i) {
        cube = (long)i*i*i;
        hash = hash_number(cube);
        table[hash].push_back(cube);
        if (table[hash].size() == 5) {
            cout << "Answer: " << table[hash][0] << '\n';
            break;
        }
    }
    return 0;
}

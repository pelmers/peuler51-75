#include "euler.hpp"

static const int TRIANGLE = 8;
static const int SQUARE   = 16;
static const int PENTAGON = 32;
static const int HEXAGON  = 64;
static const int HEPTAGON = 128;
static const int OCTAGON  = 256;
static const int TOTAL    = 8+16+32+64+128+256; // sum of all of the above

vector<int> populate_range();
int find_cycle(int, vector<int>&, int = 6, int = 0, int = TOTAL);
int main(void);

vector<int> populate_range() {
    // mark each element in the range [1000,10000) with figurate code
    vector<int> numbers(10000,0);
    // P_(m,n) = ((m-2)*n*n + (4-m)*n) / 2
    for (int m = 3; m <= 8; ++m) {
        for (int n = 1, term = 0; term < 10000; ++n) {
            term = ((m - 2)*n*n + (4 - m)*n) / 2;
            if (term > 999)
                numbers[term] = std::pow(2, m);
        }
    }
    return numbers;
}

int find_cycle(int num, vector<int>& range, int depth, int target, int total) {
    // return early if this number's no good
    if (range[num] == 0 || num % 100 < 10)
        return total;
    // set the target: we must cycle back to this number
    if (depth == 6)
        target = num / 100;
    if (depth == 1)
        return (num % 100 == target)?
                total-range[num]:total;
    // tail recurse on each possible path
    for (int i = (num % 100) * 100; i < (num % 100 + 1) * 100; ++i)
        if (find_cycle(i, range, depth - 1, target, total-range[num]) == 0)
            return 0;
    return total;
}

int main(void) {
    vector<int> range = populate_range();
    int sum = 0;
    // make every 6 number cycle using each octagon
    // check to see that there is one of each other type in them 
    for (int i = 1000; i < 10000; ++i) {
        if (find_cycle(i,range) == 0) {
            cout << i << " succeeds." << '\n';
            sum += i;
        }
    }
    cout << "Sum: " << sum << '\n';
    return 0;
}

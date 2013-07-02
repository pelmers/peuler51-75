#include "euler.hpp"


int main(void);

int main(void) {
    const int HEIGHT = 100;
    FILE *datafile = fopen("e67.dat", "r");
    // used to mark row boundaries
    int rows[HEIGHT];
    int d = 0;
    for (int i = 1; i < HEIGHT + 1; ++i) {
        d += i;
        rows[i-1] = d;
    }
    int nums[rows[HEIGHT-1]];
    // lazy, re-using a counter
    d = 0;
    while (fscanf(datafile, "%d", &nums[d]) != EOF)
        ++d;
    // Go up the pyramid, replacing each element with the maximum sum that
    // can be reached starting from that element and going to the bottom
    for (d = HEIGHT - 3; d >= 0; --d)
        for (int i = rows[d]; i < rows[d+1]; ++i)
            nums[i] += std::max(nums[i+d+2], nums[i+d+3]);
    cout << "Answer: " << nums[0] + std::max(nums[1],nums[2]) << endl;
    fclose(datafile);
    return 0;
}

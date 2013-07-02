#include "euler.hpp"

#define CC concat_nums

vector<long> find_solutions_3gon();
vector<long> find_solutions_5gon();
int main(void);

vector<long> find_solutions_3gon() {
    /* Return a vector where each element is a solution to a 3-gon ring
     * Each solution is the concatenated form of the numbers, reading
     * clockwise, starting with smallest external node.
     */
    // Naming pattern:
    //    (a)
    //      \
    //      (d)
    //      / \
    //    (f)-(e) - (b)
    //    /
    //  (c)
    //  a + d = b + f
    //  a + e = c + f
    //  b + e = c + d
    //  Answer order: ade,bef,cfd

    vector<long> solutions;
    // we have to generate four spots, and see if they work
    for (int a = 1; a <= 6; ++a) {
        for (int b = a+1; b <= 6; ++b) {
            if (b == a)
                continue;
            for (int c = a+1; c <= 6; ++c) {
                if (c == b || c == a)
                    continue;
                for (int e, f, d = 1; d <= 6; ++d) {
                    if (d == c || d == b || d == a)
                        continue;
                    e = c + d - b;
                    f = a + d - b;
                    if (e == b || e == c || f == a || f == b)
                        continue;
                    if (a + b + c + d + e + f == 21 && e != f)
                        solutions.push_back(concat_nums(a, concat_nums(d,
                                concat_nums(e, concat_nums(b, concat_nums(e,
                                concat_nums(f, concat_nums(c, concat_nums(f,
                                d)))))))));
                }
            }
        }
    }
    return solutions;
}

vector<long> find_solutions_5gon() {
    /* Return a vector where each element is a solution to a 5-gon ring
     * Each solution is the concatenated form of the numbers, reading
     * clockwise, starting with smallest external node.
     */
    // Naming pattern:
    //          (a)
    //            \
    //             (f)  (b)
    //          //   \  /
    //       (j)     (g)
    //    //  \      /
    //  (e)  (i) - (h) - (c)
    //          \
    //          (d)
    //  ^^ (terrible ascii diagram attempt) ^^
    //
    //  a + f = b + h
    //  b + g = c + i
    //  c + h = d + j
    //  d + i = e + f
    //  e + j = a + g
    //  Must generate a,b,c,d,e,f
    //  Solution: afg,bgh,chi,dij,ejf
    //
    vector<long> solutions;
    for (int a = 1; a <= 10; ++a) {
        for (int b = a+1; b <= 10; ++b) {
            if (b == a)
                continue;
            for (int c = a+1; c <= 10; ++c) {
                if (c == b || c == a)
                    continue;
                for (int d = a+1; d <= 10; ++d) {
                    if (d == c || d == b || d == a)
                        continue;
                    for (int e = a+1; e <= 10; ++e) {
                        if (e == d || e == c || e == b || e == a)
                            continue;
                        for (int g, h, i, j, f = 1; f < 10; ++f) {
                            if (f == e || f == d || f == c || f == b ||
                                    f == a)
                                continue;
                            i = e + f - d;
                            if (0 > i || 9 < i || i == a || i == b || i == c
                                    || i == d || i == e || i == f)
                                continue;
                            g = c + i - b;
                            if (0 > g || 9 < g || g == a || g == b || g == c
                                    || g == d || g == e || g == f || g == i)
                                continue;
                            j = a + g - e;
                            if (0 > j || 9 < j || j == a || j == b || j == c
                                    || j == d || j == e || j == f || j == i
                                    || j == g)
                                continue;
                            h = d + j - c;
                            if (0 > h || 9 < h || h == a || h == b || h == c
                                    || h == d || h == e || h == f || h == i
                                    || h == g || h == j)
                                continue;
                            if (a+b+c+d+e+f+g+h+i+j == 55)
                                solutions.push_back(CC(a,CC(f,CC(g,
                                                    CC(b,CC(g,CC(h,
                                                    CC(c,CC(h,CC(i,
                                                    CC(d,CC(i,CC(j,
                                                    CC(e,CC(j,f)
                                                      ))))))))))))));
                        }
                    }
                }
            }
        }
    }
    return solutions;
}

int main(void) {
    vector<long> s = find_solutions_5gon();
    std::sort(s.begin(), s.end());
    print_sequence(s.begin(), s.end());
    cout << s.size() << " solutions, pick the biggest." << endl;
    return 0;
}

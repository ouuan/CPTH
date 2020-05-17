#include "SparseTable.h"

#include <cctype>
#include <cstdio>
#include <vector>

int read()
{
    int out = 0;
    char c;
    while (!isdigit(c = getchar()))
        ;
    for (; isdigit(c); c = getchar())
        out = out * 10 + c - '0';
    return out;
}

int main()
{
    int n = read();
    int m = read();

    std::vector<int> a(n);

    for (auto &x : a)
        x = read();

    CPTH::SparseTable<int> st(a, [](int x, int y) {
        return x > y ? x : y;
    });

    assert((int)st.size() == n);

    while (m--)
    {
        int l = read();
        int r = read();
        printf("%d\n", st.query(l - 1, r));
    }

    st.init(std::vector<int>(), [](int x, int y) {
        return x < y ? x : y;
    });

    assert(st.size() == 0);

    return 0;
}

#include "SparseTable.h"

#include <cstdio>
#include <vector>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    std::vector<int> a(n);

    for (auto &x : a)
        scanf("%d", &x);

    CPTH::SparseTable<int> st(a, [](int x, int y) {
        return x > y ? x : y;
    });

    assert((int)st.size() == n);

    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", st.query(l - 1, r));
    }

    st.init(std::vector<int>(), [](int x, int y) {
        return x < y ? x : y;
    });

    assert(st.size() == 0);

    return 0;
}

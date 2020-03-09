#include "data_structure/SegmentTree.h"

#include <cstdio>

typedef long long ll;

int n, m, p;

struct Modification
{
    int add, mul;
    Modification(int _add = 0, int _mul = 1)
    {
        add = _add;
        mul = _mul;
    }
    void operator+=(const Modification &y)
    {
        add = ((ll)add * y.mul + y.add) % p;
        mul = (ll)mul * y.mul % p;
    }
};

int merge(const int &x, const int &y) { return (x + y) % p; }

void update(SegmentTreeNode<int, Modification> &node, const Modification &mod)
{
    node.val = ((ll)node.val * mod.mul + (ll)mod.add * (node.right - node.left)) % p;
    node.mod += mod;
}

int main()
{
    scanf("%d%d%d", &n, &m, &p);

    std::vector<int> a(n);
    for (auto &x : a)
    {
        scanf("%d", &x);
        x %= p;
    }

    SegmentTree<int, Modification, merge, update> t(a);

    while (m--)
    {
        int opt, l, r;
        scanf("%d%d%d", &opt, &l, &r);
        if (opt == 1)
        {
            int x;
            scanf("%d", &x);
            t.modify(l, r + 1, Modification(0, x));
        }
        else if (opt == 2)
        {
            int x;
            scanf("%d", &x);
            t.modify(l, r + 1, Modification(x, 1));
        }
        else
            printf("%d\n", t.query(l, r + 1));
    }

    return 0;
}

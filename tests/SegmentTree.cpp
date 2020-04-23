#include "SegmentTree.h"

#include <iostream>

using namespace std;
using namespace CPTH;

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

void update(SegmentTreeNode<int, Modification> &node, const Modification &mod)
{
    node.val = ((ll)node.val * mod.mul + (ll)mod.add * (node.right - node.left)) % p;
    node.mod += mod;
}

int main()
{
    cin >> n >> m >> p;

    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
        x %= p;
    }

    SegmentTree<int, Modification> t(
        a,
        [](int x, int y) {
            return (x + y) % p;
        },
        update);

    while (m--)
    {
        int opt, l, r;
        cin >> opt >> l >> r;
        if (opt == 1)
        {
            int x;
            cin >> x;
            if (l == r)
                t.modify(l, {0, x});
            else
                t.modify(l, r + 1, {0, x});
        }
        else if (opt == 2)
        {
            int x;
            cin >> x;
            if (l == r)
                t.modify(l, {x, 1});
            else
                t.modify(l, r + 1, {x, 1});
        }
        else
        {
            if (l == r)
                cout << t.query(l) << endl;
            else
                cout << t.query(l, r + 1) << endl;
        }
    }

    return 0;
}

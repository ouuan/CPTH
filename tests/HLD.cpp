#include "HLD.h"

#include <cstdio>
#include <iostream>

#include "SegmentTree.h"

using namespace std;

int main()
{
    int n, m, r, p;

    cin >> n >> m >> r >> p;

    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
        x %= p;
    }

    CPTH::HLD hld(n);

    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        hld.addEdge(u, v);
    }

    hld.build(r);

    vector<int> init(n);
    for (int i = 1; i <= n; ++i)
        init[i - 1] = a[hld.atId(i) - 1];

    CPTH::SegmentTree<int, int> seg(
        init,
        [&](int x, int y) {
            return (x + y) % p;
        },
        [&](CPTH::SegmentTreeNode<int, int> &node, int x) {
            node.val = (node.val + 1ll * x * (node.right - node.left)) % p;
            node.mod = (node.mod + x) % p;
        });

    while (m--)
    {
        int type, x;
        cin >> type >> x;
        switch (type)
        {
            case 1:
            {
                int y, z;
                cin >> y >> z;
                for (auto s : hld.path(x, y))
                    seg.modify(s.first, s.second + 1, z % p);
                break;
            }
            case 2:
            {
                int y;
                cin >> y;
                int ans = 0;
                for (auto s : hld.path(x, y))
                    ans = (ans + seg.query(s.first, s.second + 1)) % p;
                cout << ans << endl;
                break;
            }
            case 3:
            {
                int z;
                cin >> z;
                auto s = hld.subtree(x);
                seg.modify(s.first, s.second + 1, z % p);
                break;
            }
            case 4:
            {
                auto s = hld.subtree(x);
                cout << seg.query(s.first, s.second + 1) << endl;
                break;
            }
        }
    }

    return 0;
}

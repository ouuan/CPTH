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
    vector<vector<size_t>> g(n + 1);

    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        hld.addEdge(u, v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
    {
        sort(g[i].begin(), g[i].end());
        auto adj = hld.adjacent(i);
        sort(adj.begin(), adj.end());
        assert(g[i] == adj);
    }

    hld.build(1);

    for (int i = 1; i <= n; ++i)
    {
        auto x = hld.subtree(i);
        assert(hld.size(i) == x.second - x.first + 1);
        if (i == 1)
            assert(hld.depth(i) == 0);
        else
            assert(hld.depth(i) == hld.depth(hld.parent(i)) + 1);
        for (auto v : hld.children(i))
            assert(hld.size(v) <= hld.size(hld.heavyChild(i)));
    }

    for (int i = 1; i <= 10000000; ++i)
        hld.build(r);

    int cnt = 0;

    function<void(int)> dfs = [&](int u) {
        if (u == (int)hld.bottom(u))
        {
            ++cnt;
            for (int x = u; x != (int)hld.top(x); x = hld.parent(x))
            {
                ++cnt;
            }
        }
        for (auto v : hld.children(u))
        {
            dfs(v);
        }
    };

    dfs(r);
    assert(cnt == n);

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
                int l = hld.lca(x, y);
                for (auto s : hld.path(x, l))
                    seg.modify(s.first, s.second + 1, z % p);
                for (auto s : hld.path(y, l))
                    seg.modify(s.first, s.second + 1, z % p);
                seg.modify(hld.id(l), (p - z % p) % p);
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

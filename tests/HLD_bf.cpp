#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main()
{
    int n, m, r, p;
    cin >> n >> m >> r >> p;

    vi a(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i] %= p;
    }

    vector<vi> g(n + 1);

    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vi dep(n + 1), pa(n + 1);

    function<void(int)> dfs = [&](int u) {
        for (auto v : g[u])
        {
            if (v == pa[u])
                continue;
            dep[v] = dep[u] + 1;
            pa[v] = u;
            dfs(v);
        }
    };

    dfs(r);

    function<void(int, int)> subTreeAdd = [&](int u, int x) {
        a[u] = (a[u] + x) % p;
        for (auto v : g[u])
        {
            if (v == pa[u])
                continue;
            subTreeAdd(v, x);
        }
    };

    auto pathAdd = [&](int u, int v, int x) {
        while (u != v)
        {
            if (dep[u] > dep[v])
            {
                a[u] = (a[u] + x) % p;
                u = pa[u];
            }
            else
            {
                a[v] = (a[v] + x) % p;
                v = pa[v];
            }
        }
        a[u] = (a[u] + x) % p;
    };

    function<int(int)> subTreeSum = [&](int u) {
        int ans = a[u];
        for (auto v : g[u])
        {
            if (v == pa[u])
                continue;
            ans = (ans + subTreeSum(v)) % p;
        }
        return ans;
    };

    function<int(int, int)> pathSum = [&](int u, int v) {
        int ans = 0;
        while (u != v)
        {
            if (dep[u] > dep[v])
            {
                ans = (ans + a[u]) % p;
                u = pa[u];
            }
            else
            {
                ans = (ans + a[v]) % p;
                v = pa[v];
            }
        }
        ans = (ans + a[u]) % p;
        return ans;
    };

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
                pathAdd(x, y, z % p);
                break;
            }
            case 2:
            {
                int y;
                cin >> y;
                cout << pathSum(x, y) << endl;
                break;
            }
            case 3:
            {
                int z;
                cin >> z;
                subTreeAdd(x, z % p);
                break;
            }
            case 4:
            {
                cout << subTreeSum(x) << endl;
                break;
            }
        }
    }

    return 0;
}

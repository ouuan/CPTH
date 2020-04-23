#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, p;

    cin >> n >> m >> p;

    vector<int> a(n);

    for (auto &x : a)
        cin >> x;

    while (m--)
    {
        int opt, l, r;
        cin >> opt >> l >> r;
        switch (opt)
        {
            case 1:
            {
                int x;
                cin >> x;
                for (int i = l - 1; i < r; ++i)
                    a[i] = 1ll * a[i] * x % p;
                break;
            }
            case 2:
            {
                int x;
                cin >> x;
                for (int i = l - 1; i < r; ++i)
                    a[i] = (a[i] + x) % p;
                break;
            }
            case 3:
            {
                int ans = 0;
                for (int i = l - 1; i < r; ++i)
                    ans = (ans + a[i]) % p;
                cout << ans << endl;
                break;
            }
        }
    }

    return 0;
}

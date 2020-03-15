#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    int n, m;

    cin >> n >> m;

    vector<vector<ll>> a(n + 1);

    while (m--)
    {
        int type, l, r, c;
        cin >> type >> l >> r >> c;
        if (type == 1)
        {
            for (int i = l; i <= r; ++i) { a[i].push_back(c); }
        }
        else
        {
            vector<ll> tmp;
            for (int i = l; i <= r; ++i)
                for (auto x : a[i]) tmp.push_back(x);
            nth_element(tmp.begin(), tmp.begin() + c - 1, tmp.end(), greater<ll>());
            cout << tmp[c - 1] << endl;
        }
    }

    return 0;
}

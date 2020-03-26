#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i <= n - k; ++i)
    {
        int ans = a[i];
        for (int j = i + 1; j < i + k; ++j) ans = min(ans, a[j]);
        cout << ans << " \n"[i == n - k];
    }

    for (int i = 0; i <= n - k; ++i)
    {
        int ans = a[i];
        for (int j = i + 1; j < i + k; ++j) ans = max(ans, a[j]);
        cout << ans << " \n"[i == n - k];
    }

    return 0;
}

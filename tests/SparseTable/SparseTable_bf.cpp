#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);

    for (auto &x : a)
        cin >> x;

    while (m--)
    {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for (int i = l; i <= r; ++i)
            ans = max(ans, a[i - 1]);
        cout << ans << endl;
    }

    return 0;
}

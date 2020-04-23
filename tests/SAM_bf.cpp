#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    string s;

    cin >> s;

    map<string, int> cnt;

    for (int i = 0; i < s.size(); ++i)
    {
        for (int j = 1; j <= s.size() - i; ++j)
        {
            ++cnt[s.substr(i, j)];
        }
    }

    long long ans = 0;

    for (auto x : cnt)
    {
        if (x.second > 1)
            ans = max(ans, (long long)x.first.size() * x.second);
    }

    cout << ans;

    return 0;
}

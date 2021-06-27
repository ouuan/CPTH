#include "../../headers/SAM.h"

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    CPTH::SAM<char> sam('a');

    assert(sam.size() == 2);
    sam.clear();
    assert(sam.size() == 1);

    vector<int> cnt(s.size() * 2 + 10, 0);

    for (auto x : s)
        cnt[sam.append(x)] = 1;

    sam = CPTH::SAM<>(s);

    sam.buildTree();

    long long ans = 0;

    function<void(int)> dfs = [&](int u) {
        for (auto v : sam.children(u))
        {
            dfs(v);
            cnt[u] += cnt[v];
        }
        if (cnt[u] > 1)
            ans = max(ans, (long long)sam[u].len * cnt[u]);
    };

    dfs(0);

    cout << ans;

    return 0;
}

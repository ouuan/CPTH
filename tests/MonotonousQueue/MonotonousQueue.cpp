#include "../../headers/MonotonousQueue.h"

#include <algorithm>
#include <cstdio>
#include <iostream>

typedef std::pair<int, int> pii;

int main()
{
    int n, k, i;

    scanf("%d%d", &n, &k);

    std::vector<int> a(n);
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    CPTH::MonotonousQueue<pii, std::greater<pii>> mn([&](pii x) {
        return x.second > i - k;
    });

    CPTH::MonotonousQueue<pii> mx;

    assert(mx.empty());
    for (i = 1; i <= 10000; ++i)
    {
        mx.push({i * 233, i});
        assert(mx.top() == pii(i * 233, i));
    }
    mx.clear();
    assert(mx.empty());

    mx.setValidate([&](pii x) {
        return x.second > i - k;
    });

    for (i = 0; i < k - 1; ++i)
    {
        mn.push({a[i], i});
        mx.push({a[i], i});
    }

    for (i = k - 1; i < n; ++i)
    {
        mn.push({a[i], i});
        assert(!mn.empty());
        printf("%d%c", mn.top().first, " \n"[i == n - 1]);
    }

    for (i = k - 1; i < n; ++i)
    {
        mx.push({a[i], i});
        assert(!mx.empty());
        printf("%d%c", mx.top().first, " \n"[i == n - 1]);
    }

    return 0;
}

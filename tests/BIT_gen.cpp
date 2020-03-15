#include <chrono>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <random>

using namespace std;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int randint(int l, int r) { return rnd() % (r - l + 1) + l; }

int main()
{
    int n = randint(200, 1000);
    int m = randint(200, 1000);

    printf("%d %d\n", n, m);

    vector<int> a(n + 1, 0);

    while (m--)
    {
        int type = randint(1, 2);
        int l = randint(1, n);
        int r = randint(1, n);
        if (l > r) swap(l, r);
        int sum = 0;
        for (int i = l; i <= r; ++i) sum += a[i];
        if (sum == 0) type = 1;
        if (type == 1)
        {
            printf("1 %d %d %d\n", l, r, randint(-n, n));
            for (int i = l; i <= r; ++i) ++a[i];
        }
        else
            printf("2 %d %d %d\n", l, r, randint(1, sum));
    }

    return 0;
}

#include <chrono>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <random>

using namespace std;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int randint(int l, int r)
{
    return rnd() % (r - l + 1) + l;
}

int main()
{
    int n = randint(10, 5000);
    int m = randint(10, 50000);

    printf("%d %d\n", n, m);

    for (int i = 0; i < n; ++i)
        printf("%d%c", randint(0, 1e9), " \n"[i == n - 1]);

    while (m--)
    {
        int l = randint(1, n);
        int r = randint(1, n);
        if (l > r)
            swap(l, r);
        printf("%d %d\n", l, r);
    }

    return 0;
}

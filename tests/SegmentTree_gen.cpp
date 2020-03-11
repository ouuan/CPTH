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
    int n = randint(1000, 10000);
    int m = randint(1000, 10000);
    int p = randint(1000, 1000000000);

    printf("%d %d %d\n", n, m, p);

    for (int i = 1; i <= n; ++i) printf("%d%c", randint(0, 1000000000), " \n"[i == n]);

    while (m--)
    {
        int opt = randint(1, 3);
        int l = randint(1, n);
        int r = randint(1, n);
        if (l > r) swap(l, r);
        if (opt == 3) printf("3 %d %d\n", l, r);
        else
        {
            int x = randint(0, 10);
            printf("%d %d %d %d\n", opt, l, r, x);
        }
    }

    return 0;
}

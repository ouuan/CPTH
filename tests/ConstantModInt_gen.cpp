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
    int n = randint(100, 1000000);
    int m = 998244353;

    printf("%d %d\n", n, m);

    while (n--)
    {
        int op = randint(1, 5);
        printf("%d ", op);
        if (op <= 4)
            printf("%d\n", randint(0, 1000000000));
        else
            printf("%d\n", randint(1, m - 1));
    }

    return 0;
}

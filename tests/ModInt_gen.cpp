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

bool nprime(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return true;
    }
    return false;
}

int main()
{
    int n = randint(1000, 1000000);
    int m = randint(2, 1000000000);

    while (nprime(m))
        m = randint(2, 1000000000);

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

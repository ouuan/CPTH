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

int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : x;
}

int main()
{
    int n = randint(1000, 200000);
    int m = 404404404;

    printf("%d %d\n", n, m);

    while (n--)
    {
        int op = randint(1, 5);
        printf("%d ", op);
        if (op <= 4)
            printf("%d\n", randint(0, 1000000000));
        else
        {
            int x = randint(1, 1000000000);
            while (gcd(x, m) != 1)
                x = randint(1, 1000000000);
            printf("%d\n", x);
        }
    }

    return 0;
}

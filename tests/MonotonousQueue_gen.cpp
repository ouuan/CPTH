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
    int n = randint(100, 10000);
    int k = randint(20, n / 2);

    printf("%d %d\n", n, k);

    for (int i = 0; i < n; ++i) printf("%d%c", randint(-1000000000, 1000000000), " \n"[i == n - 1]);

    return 0;
}

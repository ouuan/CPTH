#include <chrono>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <random>

#include "../../third_party/Tree-Generator/treegenerator.h"

using namespace std;
using namespace tree_generator_by_ouuan;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int randInt(int l, int r)
{
    return rnd() % (r - l + 1) + l;
}

int main()
{
    randint = randInt;

    int n, m, r, p;
    n = randint(100, 5000);
    m = randint(100, 5000);
    r = randint(1, n);
    p = randint(2, 1000000000);

    printf("%d %d %d %d\n", n, m, r, p);

    for (int i = 1; i <= n; ++i)
        cout << randint(0, 1000000000) << " \n"[i == n];

    Tree t(n);
    t.shuffleNodes();
    t.shuffleEdges();
    cout << t;

    while (m--)
    {
        int type = randint(1, 4);
        int x = randint(1, n);
        int y = randint(1, n);
        int z = randint(0, 1000000000);
        printf("%d %d ", type, x);
        switch (type)
        {
            case 1:
                printf("%d %d\n", y, z);
                break;
            case 2:
                printf("%d\n", y);
                break;
            case 3:
                printf("%d\n", z);
                break;
            case 4:
                puts("");
                break;
        }
    }

    return 0;
}

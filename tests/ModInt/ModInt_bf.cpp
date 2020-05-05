#include <cstdio>
#include <iostream>

int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int g = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return g;
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    int x = 0;

    while (n--)
    {
        int op, a;
        std::cin >> op >> a;
        switch (op)
        {
            case 1:
                x = (x + a) % m;
                break;
            case 2:
                x = (x - a % m + m) % m;
                break;
            case 3:
                x = (a - x + m) % m;
                break;
            case 4:
                x = 1ll * x * a % m;
                break;
            case 5:
            {
                int xx, yy;
                exgcd(a, m, xx, yy);
                xx = (xx + m) % m;
                x = 1ll * x * xx % m;
                break;
            }
        }
        std::cout << x << '\n';
    }

    return 0;
}

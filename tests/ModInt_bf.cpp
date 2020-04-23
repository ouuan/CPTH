#include <cstdio>
#include <iostream>

int qpow(int x, int y, int mod)
{
    int out = 1;
    while (y)
    {
        if (y & 1)
            out = 1ll * out * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return out;
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
                x = 1ll * x * qpow(a, m - 2, m) % m;
                break;
        }
        std::cout << x << '\n';
    }

    return 0;
}

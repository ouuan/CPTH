#include "../../headers/ModInt.h"

#include <cstdio>
#include <iostream>
#include <set>

using CPTH::ModInt;

int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : x;
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    ModInt x(m);

    assert(m == x.modulo());

    int phi = 1;

    int k = m;

    for (int i = 2; i * i <= k; ++i)
    {
        if (k % i == 0)
        {
            phi *= (i - 1);
            k /= i;
            while (k % i == 0)
            {
                phi *= i;
                k /= i;
            }
        }
    }

    if (k > 1)
        phi *= (k - 1);

    while (n--)
    {
        int op, a;
        std::cin >> op >> a;

        switch (op)
        {
            case 1:
            {
                std::set<ModInt> s;
                ModInt ans(m, (x.toInt() + a) % m);
                s.insert(ans);
                if (n % 3 == 0)
                    x += a;
                else if (n % 3 == 1)
                    x += ModInt(m, a);
                else
                    x = a + x;
                s.insert(x);
                assert(x == ans);
                assert(s.size() == 1);
                break;
            }
            case 2:
                if (n & 1)
                    x -= a;
                else
                    x -= ModInt(m, a);
                break;
            case 3:
                x = a - x;
                break;
            case 4:
                if (n & 1)
                    x *= a;
                else
                    x = a * x;
                break;
            case 5:
            {
                auto old = x;
                if (n % 3 == 0)
                    x /= a;
                else if (n % 3 == 1)
                    x /= ModInt(m, a);
                else
                    x = x.toInt() / ModInt(m, a);
                assert(x * a == old);
                break;
            }
        }

        ModInt ans(x.modulo());
        ans.setValue(x.toInt());

        std::cout << (gcd(ans.toInt(), m) == 1 ? pow(ans, phi + 1).toInt() : ans.toInt()) << '\n';
    }

    return 0;
}

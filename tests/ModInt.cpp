#include "ModInt.h"

#include <cstdio>
#include <iostream>
#include <set>

using CPTH::ModInt;

int main()
{
    int n, m;
    std::cin >> n >> m;

    ModInt x(m);

    assert(m == x.modulo());

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
                if (n % 3 == 0)
                    x /= a;
                else if (n % 3 == 1)
                    x /= ModInt(m, a);
                else
                    x = x.toInt() / ModInt(m, a);
                break;
        }

        ModInt ans(x.modulo());
        ans.setValue(x.toInt());

        std::cout << pow(ans, m).toInt() << '\n';
    }

    return 0;
}

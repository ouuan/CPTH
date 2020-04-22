#include "ConstantModInt.h"

#include <cstdio>
#include <iostream>

using CPTH::ConstantModInt;

const int mod = 998244353;

int main()
{
    int n, m;
    std::cin >> n >> m;

    ConstantModInt<mod> x;

    assert(m == x.modulo());

    while (n--)
    {
        int op, a;
        std::cin >> op >> a;

        switch (op)
        {
            case 1:
                if (n & 1) x += a;
                else
                    x = a + x;
                break;
            case 2:
                x -= a;
                break;
            case 3:
                x = a - x;
                break;
            case 4:
                if (n & 1) x *= a;
                else
                    x = a * x;
                break;
            case 5:
                if (n & 1) x /= a;
                else
                    x = x.toInt() / ConstantModInt<mod>(a);
                break;
        }

        ConstantModInt<mod> ans(x.modulo());
        ans.setValue(x.toInt());

        std::cout << ans.toInt() << '\n';
    }

    return 0;
}

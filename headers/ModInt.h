// Get more headers at https://github.com/ouuan/CPTH

#ifndef CPTH_MODINT
#define CPTH_MODINT

#include <cassert>

namespace CPTH
{
class ModInt
{
   public:
    explicit ModInt(int modulo, long long value = 0);

    int toInt() const;
    int modulo() const;

    void setValue(long long x);

    ModInt operator-() const;
    ModInt operator~() const;

    friend ModInt operator+(ModInt x, ModInt y);
    friend ModInt operator+(ModInt x, long long y);
    friend ModInt operator+(long long x, ModInt y);
    ModInt &operator+=(ModInt y);
    ModInt &operator+=(long long y);

    friend ModInt operator-(ModInt x, ModInt y);
    friend ModInt operator-(ModInt x, long long y);
    friend ModInt operator-(long long x, ModInt y);
    ModInt &operator-=(ModInt y);
    ModInt &operator-=(long long y);

    friend ModInt operator*(ModInt x, ModInt y);
    friend ModInt operator*(ModInt x, long long y);
    friend ModInt operator*(long long x, ModInt y);
    ModInt &operator*=(ModInt y);
    ModInt &operator*=(long long y);

    friend ModInt operator/(ModInt x, ModInt y);
    friend ModInt operator/(ModInt x, long long y);
    friend ModInt operator/(long long x, ModInt y);
    ModInt &operator/=(ModInt y);
    ModInt &operator/=(long long y);

    friend bool operator==(ModInt x, ModInt y);
    friend bool operator<(ModInt x, ModInt y);

    ModInt pow(unsigned long long y) const;
    friend ModInt pow(ModInt x, unsigned long long y);

   private:
    int modadd(int x, int y) const;
    static int exgcd(int a, int b, int &x, int &y);

    int val;
    int mod;
};

ModInt::ModInt(int modulo, long long value) : mod(modulo)
{
    assert(modulo >= 1);
    assert(modulo <= __INT_MAX__ - modulo);
    val = (value % mod + mod) % mod;
}

int ModInt::toInt() const
{
    return val;
}
int ModInt::modulo() const
{
    return mod;
}

void ModInt::setValue(long long x)
{
    val = (x % mod + mod) % mod;
}

ModInt ModInt::operator-() const
{
    return ModInt{mod, val ? mod - val : 0};
}
ModInt ModInt::operator~() const
{
    assert(val != 0);  // don't merge this into the next one so that the bug can be easily found
    int x, y;
    assert(exgcd(val, mod, x, y) == 1);
    return ModInt(mod, x);
}

ModInt operator+(ModInt x, ModInt y)
{
    assert(x.mod == y.mod);
    return ModInt{x.mod, x.modadd(x.val, y.val)};
}
ModInt operator+(ModInt x, long long y)
{
    return x + ModInt(x.mod, y);
}
ModInt operator+(long long x, ModInt y)
{
    return y + x;
}
ModInt &ModInt::operator+=(ModInt y)
{
    assert(mod == y.modulo());
    return *this = *this + y;
}
ModInt &ModInt::operator+=(long long y)
{
    return *this = *this + y;
}

ModInt operator-(ModInt x, ModInt y)
{
    assert(x.mod == y.mod);
    return x + (-y);
}
ModInt operator-(ModInt x, long long y)
{
    return x - ModInt(x.mod, y);
}
ModInt operator-(long long x, ModInt y)
{
    return ModInt(y.mod, x) - y;
}
ModInt &ModInt::operator-=(ModInt y)
{
    assert(mod == y.modulo());
    return *this = *this - y;
}
ModInt &ModInt::operator-=(long long y)
{
    return *this = *this - y;
}

ModInt operator*(ModInt x, ModInt y)
{
    assert(x.mod == y.mod);
    return ModInt{x.mod, (long long)x.val * y.val % x.mod};
}
ModInt operator*(ModInt x, long long y)
{
    return x * ModInt(x.mod, y);
}
ModInt operator*(long long x, ModInt y)
{
    return y * x;
}
ModInt &ModInt::operator*=(ModInt y)
{
    assert(mod == y.modulo());
    return *this = *this * y;
}
ModInt &ModInt::operator*=(long long y)
{
    return *this = *this * y;
}

ModInt operator/(ModInt x, ModInt y)
{
    assert(x.mod == y.mod);
    assert(y.val != 0);
    return x * ~y;
}
ModInt operator/(ModInt x, long long y)
{
    assert(y % x.mod != 0);
    return x / ModInt(x.mod, y);
}
ModInt operator/(long long x, ModInt y)
{
    assert(y.val != 0);
    return ModInt(y.mod, x) / y;
}
ModInt &ModInt::operator/=(ModInt y)
{
    assert(mod == y.modulo());
    assert(y.modulo() != 0);
    return *this = *this / y;
}
ModInt &ModInt::operator/=(long long y)
{
    assert(y % mod != 0);
    return *this = *this / y;
}

bool operator==(ModInt x, ModInt y)
{
    return x.val == y.val && x.mod == y.mod;
}

bool operator<(ModInt x, ModInt y)
{
    return x.val == y.val ? x.mod < y.mod : x.val < y.val;
}

ModInt ModInt::pow(unsigned long long y) const
{
    ModInt x = *this, out(mod, 1);
    while (y)
    {
        if (y & 1)
            out *= x;
        x *= x;
        y >>= 1;
    }
    return out;
}
ModInt pow(ModInt x, unsigned long long y)
{
    return x.pow(y);
}

int ModInt::modadd(int x, int y) const
{
    return (x += y) >= mod ? x - mod : x;
}

int ModInt::exgcd(int a, int b, int &x, int &y)
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

}  // namespace CPTH

#endif  // CPTH_MODINT

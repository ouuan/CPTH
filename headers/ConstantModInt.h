// Get more headers at https://github.com/ouuan/CPTH

#ifndef CPTH_CONSTANTMODINT
#define CPTH_CONSTANTMODINT

#include <cassert>

namespace CPTH
{
template <int mod>
class ConstantModInt
{
   public:
    ConstantModInt(long long value = 0);

    int toInt() const;
    int modulo() const;

    void setValue(long long x);

    ConstantModInt operator-() const;
    ConstantModInt operator~() const;

    template <int M>
    friend ConstantModInt<M> operator+(ConstantModInt<M> x, ConstantModInt<M> y);
    template <int M>
    friend ConstantModInt<M> operator+(ConstantModInt<M> x, long long y);
    template <int M>
    friend ConstantModInt<M> operator+(long long x, ConstantModInt<M> y);
    ConstantModInt &operator+=(ConstantModInt y);
    ConstantModInt &operator+=(long long y);

    template <int M>
    friend ConstantModInt<M> operator-(ConstantModInt<M> x, ConstantModInt<M> y);
    template <int M>
    friend ConstantModInt<M> operator-(ConstantModInt<M> x, long long y);
    template <int M>
    friend ConstantModInt<M> operator-(long long x, ConstantModInt<M> y);
    ConstantModInt &operator-=(ConstantModInt y);
    ConstantModInt &operator-=(long long y);

    template <int M>
    friend ConstantModInt<M> operator*(ConstantModInt<M> x, ConstantModInt<M> y);
    template <int M>
    friend ConstantModInt<M> operator*(ConstantModInt<M> x, long long y);
    template <int M>
    friend ConstantModInt<M> operator*(long long x, ConstantModInt<M> y);
    ConstantModInt &operator*=(ConstantModInt y);
    ConstantModInt &operator*=(long long y);

    template <int M>
    friend ConstantModInt<M> operator/(ConstantModInt<M> x, ConstantModInt<M> y);
    template <int M>
    friend ConstantModInt<M> operator/(ConstantModInt<M> x, long long y);
    template <int M>
    friend ConstantModInt<M> operator/(long long x, ConstantModInt<M> y);
    ConstantModInt &operator/=(ConstantModInt y);
    ConstantModInt &operator/=(long long y);

    template <int M>
    friend bool operator==(ConstantModInt<M> x, ConstantModInt<M> y);
    template <int M>
    friend bool operator<(ConstantModInt<M> x, ConstantModInt<M> y);

    ConstantModInt pow(unsigned long long y) const;
    template <int M>
    friend ConstantModInt<M> pow(ConstantModInt<M> x, unsigned long long y);

   private:
    static int modadd(int x, int y);
    static int gcd(int x, int y);

    int val;
};

template <int mod>
ConstantModInt<mod>::ConstantModInt(long long value)
{
    assert(mod >= 1);
    assert(mod <= __INT_MAX__ - mod);
    val = (value % mod + mod) % mod;
}

template <int mod>
int ConstantModInt<mod>::toInt() const
{
    return val;
}
template <int mod>
int ConstantModInt<mod>::modulo() const
{
    return mod;
}

template <int mod>
void ConstantModInt<mod>::setValue(long long x)
{
    val = (x % mod + mod) % mod;
}

template <int mod>
ConstantModInt<mod> ConstantModInt<mod>::operator-() const
{
    return val ? mod - val : 0;
}
template <int mod>
ConstantModInt<mod> ConstantModInt<mod>::operator~() const
{
    assert(val != 0);  // don't merge this into the next one so that the bug can be easily found
    assert(gcd(val, mod) == 1);
    return pow(mod - 2);
}

template <int mod>
ConstantModInt<mod> operator+(ConstantModInt<mod> x, ConstantModInt<mod> y)
{
    return x.modadd(x.val, y.val);
}
template <int mod>
ConstantModInt<mod> operator+(long long x, ConstantModInt<mod> y)
{
    return ConstantModInt<mod>(x) + y;
}
template <int mod>
ConstantModInt<mod> operator+(ConstantModInt<mod> x, long long y)
{
    return x + ConstantModInt<mod>(y);
}
template <int mod>
ConstantModInt<mod> &ConstantModInt<mod>::operator+=(ConstantModInt<mod> y)
{
    return *this = *this + y;
}
template <int mod>
ConstantModInt<mod> &ConstantModInt<mod>::operator+=(long long y)
{
    return *this = *this + y;
}

template <int mod>
ConstantModInt<mod> operator-(ConstantModInt<mod> x, ConstantModInt<mod> y)
{
    return x + (-y);
}
template <int mod>
ConstantModInt<mod> operator-(long long x, ConstantModInt<mod> y)
{
    return ConstantModInt<mod>(x) - y;
}
template <int mod>
ConstantModInt<mod> operator-(ConstantModInt<mod> x, long long y)
{
    return x - ConstantModInt<mod>(y);
}
template <int mod>
ConstantModInt<mod> &ConstantModInt<mod>::operator-=(ConstantModInt<mod> y)
{
    return *this = *this - y;
}
template <int mod>
ConstantModInt<mod> &ConstantModInt<mod>::operator-=(long long y)
{
    return *this = *this - y;
}

template <int mod>
ConstantModInt<mod> operator*(ConstantModInt<mod> x, ConstantModInt<mod> y)
{
    return (long long)x.val * y.val % mod;
}
template <int mod>
ConstantModInt<mod> operator*(long long x, ConstantModInt<mod> y)
{
    return ConstantModInt<mod>(x) * y;
}
template <int mod>
ConstantModInt<mod> operator*(ConstantModInt<mod> x, long long y)
{
    return y * x;
}
template <int mod>
ConstantModInt<mod> &ConstantModInt<mod>::operator*=(ConstantModInt<mod> y)
{
    return *this = *this * y;
}
template <int mod>
ConstantModInt<mod> &ConstantModInt<mod>::operator*=(long long y)
{
    return *this = *this * y;
}

template <int mod>
ConstantModInt<mod> operator/(ConstantModInt<mod> x, ConstantModInt<mod> y)
{
    assert(y.val != 0);
    return x * ~y;
}
template <int mod>
ConstantModInt<mod> operator/(long long x, ConstantModInt<mod> y)
{
    assert(y.val != 0);
    return ConstantModInt<mod>(x) / y;
}
template <int mod>
ConstantModInt<mod> operator/(ConstantModInt<mod> x, long long y)
{
    assert(y % mod != 0);
    return x / ConstantModInt<mod>(y);
}
template <int mod>
ConstantModInt<mod> &ConstantModInt<mod>::operator/=(ConstantModInt<mod> y)
{
    assert(y.toInt() != 0);
    return *this = *this / y;
}
template <int mod>
ConstantModInt<mod> &ConstantModInt<mod>::operator/=(long long y)
{
    assert(y % mod != 0);
    return *this = *this / y;
}

template <int mod>
bool operator==(ConstantModInt<mod> x, ConstantModInt<mod> y)
{
    return x.val == y.val;
}
template <int mod>
bool operator<(ConstantModInt<mod> x, ConstantModInt<mod> y)
{
    return x.val < y.val;
}

template <int mod>
ConstantModInt<mod> ConstantModInt<mod>::pow(unsigned long long y) const
{
    ConstantModInt<mod> x(*this), out(1);
    while (y)
    {
        if (y & 1)
            out *= x;
        x *= x;
        y >>= 1;
    }
    return out;
}

template <int mod>
ConstantModInt<mod> pow(ConstantModInt<mod> x, unsigned long long y)
{
    return x.pow(y);
}

template <int mod>
int ConstantModInt<mod>::modadd(int x, int y)
{
    return (x += y) >= mod ? x - mod : x;
}

template <int mod>
int ConstantModInt<mod>::gcd(int x, int y)
{
    return y ? gcd(y, x % y) : x;
}

}  // namespace CPTH

#endif  // CPTH_CONSTANTMODINT

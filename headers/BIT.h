// Get more headers at https://github.com/ouuan/CPTH

#ifndef CPTH_BIT
#define CPTH_BIT

#include <cassert>
#include <climits>
#include <functional>
#include <vector>

namespace CPTH
{
template <typename T>
class BIT
{
   public:
    BIT();

    BIT(std::size_t _size, std::function<T(const T &, const T &)> _merge, const T &_zero = T());

    void init(std::size_t _size, std::function<T(const T &, const T &)> _merge,
              const T &_zero = T());

    void add(std::size_t p, const T &x);

    T query(std::size_t p) const;

    std::size_t size() const;

    void clear();

   private:
    static std::size_t lowbit(std::size_t x);

    T zero;
    std::vector<T> a;
    unsigned long long tim;
    std::vector<unsigned long long> vis;
    std::function<T(const T &, const T &)> merge;
};

template <typename T>
BIT<T>::BIT() : a(1){};

template <typename T>
BIT<T>::BIT(std::size_t _size, std::function<T(const T &, const T &)> _merge, const T &_zero)
{
    init(_size, _merge, _zero);
}

template <typename T>
void BIT<T>::init(std::size_t _size, std::function<T(const T &, const T &)> _merge, const T &_zero)
{
    assert(_size < vis.max_size());
    assert(_size < a.max_size());
    tim = 0;
    zero = _zero;
    merge = _merge;
    vis.assign(_size + 1, 0);
    a.assign(_size + 1, zero);
}

template <typename T>
void BIT<T>::add(std::size_t p, const T &x)
{
    assert(p);
    for (; p <= size(); p += lowbit(p))
    {
        if (vis[p] != tim)
        {
            vis[p] = tim;
            a[p] = x;
        }
        else
            a[p] = merge(a[p], x);
    }
}

template <typename T>
T BIT<T>::query(std::size_t p) const
{
    assert(p <= size());
    T out = zero;
    for (; p; p -= lowbit(p))
    {
        if (vis[p] == tim)
            out = merge(out, a[p]);
    }
    return out;
}

template <typename T>
std::size_t BIT<T>::size() const
{
    assert(a.size());
    return a.size() - 1;
}

template <typename T>
void BIT<T>::clear()
{
    assert(tim < ULLONG_MAX);
    ++tim;
}

template <typename T>
std::size_t BIT<T>::lowbit(std::size_t x)
{
    return std::size_t(1) << __builtin_ctzll(x);
}

}  // namespace CPTH

#endif  // CPTH_BIT

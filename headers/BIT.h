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
    BIT() : a(1){};

    BIT(std::size_t _size, std::function<T(const T &, const T &)> _merge, const T &_zero = T())
    {
        init(_size, _merge, _zero);
    }

    void init(std::size_t _size, std::function<T(const T &, const T &)> _merge,
              const T &_zero = T())
    {
        assert(_size < vis.max_size());
        assert(_size < a.max_size());
        tim = 0;
        zero = _zero;
        merge = _merge;
        vis.assign(_size + 1, 0);
        a.assign(_size + 1, zero);
    }

    void add(std::size_t p, const T &x)
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

    T query(std::size_t p) const
    {
        assert(p <= size());
        T out = zero;
        for (; p; p -= lowbit(p))
        {
            if (vis[p] == tim) out = merge(out, a[p]);
        }
        return out;
    }

    std::size_t size() const
    {
        assert(a.size());
        return a.size() - 1;
    }

    void clear()
    {
        assert(tim < ULLONG_MAX);
        ++tim;
    }

   private:
    static std::size_t lowbit(std::size_t x) { return std::size_t(1) << __builtin_ctzll(x); }

    T zero;
    std::vector<T> a;
    unsigned long long tim;
    std::vector<unsigned long long> vis;
    std::function<T(const T &, const T &)> merge;
};
}  // namespace CPTH

#endif  // CPTH_BIT

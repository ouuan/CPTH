// Get more headers at https://github.com/ouuan/CPTH

#ifndef CPTH_SPARSETABLE
#define CPTH_SPARSETABLE

#include <cassert>
#include <cstddef>
#include <functional>
#include <vector>

namespace CPTH
{
template <typename T>
class SparseTable
{
   public:
    explicit SparseTable() = default;

    explicit SparseTable(const std::vector<T> &a, std::function<T(const T &, const T &)> merge);

    void init(const std::vector<T> &a, std::function<T(const T &, const T &)> merge);

    T query(size_t l, size_t r) const;

    size_t size() const;

   private:
    std::function<T(const T &, const T &)> f;
    std::vector<std::vector<T>> st;
    std::vector<size_t> k;
};

template <typename T>
SparseTable<T>::SparseTable(const std::vector<T> &a, std::function<T(const T &, const T &)> merge)
{
    init(a, merge);
}

template <typename T>
void SparseTable<T>::init(const std::vector<T> &a, std::function<T(const T &, const T &)> merge)
{
    f = merge;
    if (a.empty())
    {
        k.clear();
        st.clear();
        return;
    }
    k.resize(a.size());
    for (size_t i = 3; i <= a.size(); ++i)
    {
        if (((i - 2) & (i - 1)) == 0)
            k[i - 1] = k[i - 2] + 1;
        else
            k[i - 1] = k[i - 2];
    }
    st.assign(k.back() + 1, std::vector<T>());
    st.front() = a;
    for (size_t i = 1; i <= k.back(); ++i)
    {
        size_t x = size_t(1) << (i - 1);
        size_t y = x << 1;
        st[i].reserve(a.size() - y + 1);
        for (size_t j = 0; j <= a.size() - y; ++j)
            st[i].push_back(f(st[i - 1][j], st[i - 1][j + x]));
    }
}

template <typename T>
T SparseTable<T>::query(size_t l, size_t r) const
{
    assert(l < r);
    assert(r <= st.front().size());
    size_t x = k[r - l - 1];
    return f(st[x][l], st[x][r - (size_t(1) << x)]);
}

template <typename T>
size_t SparseTable<T>::size() const
{
    if (st.empty())
        return 0;
    return st.front().size();
}
}  // namespace CPTH

#endif  // CPTH_SPARSETABLE

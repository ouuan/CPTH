// Get more headers at https://github.com/ouuan/CPTH

#ifndef CPTH_MONOTONOUSQUEUE
#define CPTH_MONOTONOUSQUEUE

#include <cassert>
#include <functional>
#include <vector>

namespace CPTH
{
template <typename T, typename cmp = std::less<T>>
class MonotonousQueue
{
   public:
    explicit MonotonousQueue(std::function<bool(const T &)> validate =
                                 [](const T &) { return true; })
        : m_validate(validate)
    {}

    void setValidate(std::function<bool(const T &)> validate) { m_validate = validate; }

    bool empty()
    {
        removeInvalidElements();
        return m_empty();
    }

    void clear()
    {
        a.clear();
        head = 0;
    }

    void push(const T &x)
    {
        while (!m_empty() && cmp()(a.back(), x)) a.pop_back();
        a.push_back(x);
    }

    T top()
    {
        removeInvalidElements();
        assert(!m_empty());
        return a[head];
    }

   private:
    bool m_empty() const { return head >= a.size(); }

    void removeInvalidElements()
    {
        while (!m_empty() && !m_validate(a[head])) ++head;
    }

    std::vector<T> a;
    std::size_t head = 0;
    std::function<bool(const T &)> m_validate;
};
}  // namespace CPTH

#endif  // CPTH_MONOTONOUSQUEUE

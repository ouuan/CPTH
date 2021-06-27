// Get more headers at https://github.com/ouuan/CPTH

#ifndef CPTH_MONOTONOUSQUEUE
#define CPTH_MONOTONOUSQUEUE

#include <cassert>
#include <cstddef>
#include <functional>
#include <vector>

namespace CPTH
{
template <typename T, typename cmp = std::less<T>>
class MonotonousQueue
{
   public:
    explicit MonotonousQueue(std::function<bool(const T &)> validate = [](const T &) {
        return true;
    });

    void setValidate(std::function<bool(const T &)> validate);

    bool empty();

    void clear();

    void push(const T &x);

    T top();

   private:
    bool m_empty() const;

    void removeInvalidElements();

    std::vector<T> a;
    size_t head = 0;
    std::function<bool(const T &)> m_validate;
};

template <typename T, typename cmp>
MonotonousQueue<T, cmp>::MonotonousQueue(std::function<bool(const T &)> validate)
    : m_validate(validate)
{}

template <typename T, typename cmp>
void MonotonousQueue<T, cmp>::setValidate(std::function<bool(const T &)> validate)
{
    m_validate = validate;
}

template <typename T, typename cmp>
bool MonotonousQueue<T, cmp>::empty()
{
    removeInvalidElements();
    return m_empty();
}

template <typename T, typename cmp>
void MonotonousQueue<T, cmp>::clear()
{
    a.clear();
    head = 0;
}

template <typename T, typename cmp>
void MonotonousQueue<T, cmp>::push(const T &x)
{
    while (!m_empty() && cmp()(a.back(), x))
        a.pop_back();
    a.push_back(x);
}

template <typename T, typename cmp>
T MonotonousQueue<T, cmp>::top()
{
    removeInvalidElements();
    assert(!m_empty());
    return a[head];
}

template <typename T, typename cmp>
bool MonotonousQueue<T, cmp>::m_empty() const
{
    return head >= a.size();
}

template <typename T, typename cmp>
void MonotonousQueue<T, cmp>::removeInvalidElements()
{
    while (!m_empty() && !m_validate(a[head]))
        ++head;
}

}  // namespace CPTH

#endif  // CPTH_MONOTONOUSQUEUE

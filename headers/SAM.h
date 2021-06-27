// Get more headers at https://github.com/ouuan/CPTH

#ifndef CPTH_SAM
#define CPTH_SAM

#include <cassert>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

namespace CPTH
{
template <typename charType = char>
class SAM
{
   public:
    struct SAMNode
    {
        size_t pa, len;
        std::map<charType, size_t> ch;
        SAMNode() : pa(std::vector<SAMNode>().max_size()), len(0)
        {}
        size_t &operator[](const charType &x)
        {
            return ch[x];
        }
        size_t operator[](const charType &x) const
        {
            try
            {
                return ch.at(x);
            }
            catch (std::out_of_range const &)
            {
                return charType();
            }
        }
    };

    SAM();

    explicit SAM(const charType &x);

    template <typename T>
    explicit SAM(const T &str);

    size_t append(const charType &x);

    template <typename T>
    void append(const T &str);

    void clear();

    void buildTree();

    size_t size() const;

    const SAMNode &operator[](size_t x) const;

    const std::vector<size_t> &children(size_t x) const;

   private:
    std::vector<SAMNode> t;
    std::vector<std::vector<size_t>> g;
    size_t p;
};

template <typename charType>
SAM<charType>::SAM()
{
    clear();
}

template <typename charType>
SAM<charType>::SAM(const charType &x) : SAM()
{
    append(x);
}

template <typename charType>
template <typename T>
SAM<charType>::SAM(const T &str) : SAM()
{
    append(str);
}

template <typename charType>
size_t SAM<charType>::append(const charType &x)
{
    size_t np = t.size();
    t.emplace_back();
    t[np].len = t[p].len + 1;
    while (p != t.max_size() && !t[p].ch.count(x))
    {
        t[p][x] = np;
        p = t[p].pa;
    }
    if (p == t.max_size())
        t[np].pa = 0;
    else
    {
        size_t q = t[p][x];
        if (t[q].len == t[p].len + 1)
            t[np].pa = q;
        else
        {
            size_t nq = t.size();
            t.push_back(t[q]);
            t[nq].len = t[p].len + 1;
            t[q].pa = t[np].pa = nq;
            while (p != t.max_size() && t[p][x] == q)
            {
                t[p][x] = nq;
                p = t[p].pa;
            }
        }
    }
    return p = np;
}

template <typename charType>
template <typename T>
void SAM<charType>::append(const T &str)
{
    for (auto x : str)
        append(x);
}

template <typename charType>
void SAM<charType>::clear()
{
    t.clear();
    g.clear();
    t.resize(1);
    p = 0;
}

template <typename charType>
void SAM<charType>::buildTree()
{
    g.assign(t.size(), std::vector<size_t>());
    for (size_t i = 1; i < t.size(); ++i)
        g[t[i].pa].push_back(i);
}

template <typename charType>
size_t SAM<charType>::size() const
{
    return t.size();
}

template <typename charType>
const typename SAM<charType>::SAMNode &SAM<charType>::operator[](size_t x) const
{
    assert(x < t.size());
    return t[x];
}

template <typename charType>
const std::vector<size_t> &SAM<charType>::children(size_t x) const
{
    assert(x < g.size());
    return g[x];
}

}  // namespace CPTH

#endif  // CPTH_SAM

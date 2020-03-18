// Get more headers at https://github.com/ouuan/CPTH

#ifndef CPTH_SAM
#define CPTH_SAM

#include <cassert>
#include <map>
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
        std::size_t pa, len;
        std::map<charType, std::size_t> ch;
        SAMNode() : pa(std::vector<SAMNode>().max_size()), len(0) {}
        std::size_t &operator[](std::size_t x) { return ch[x]; }
    };

    SAM() { clear(); }

    explicit SAM(const charType &x) : SAM() { append(x); }

    template <typename T>
    explicit SAM(const T &str) : SAM()
    {
        append(str);
    }

    std::size_t append(const charType &x)
    {
        std::size_t np = t.size();
        t.emplace_back();
        t[np].len = t[p].len + 1;
        while (p != t.max_size() && !t[p].ch.count(x))
        {
            t[p][x] = np;
            p = t[p].pa;
        }
        if (p == t.max_size()) t[np].pa = 0;
        else
        {
            std::size_t q = t[p][x];
            if (t[q].len == t[p].len + 1) t[np].pa = q;
            else
            {
                std::size_t nq = t.size();
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

    template <typename T>
    void append(const T &str)
    {
        for (auto x : str) append(x);
    }

    void clear()
    {
        t.clear();
        g.clear();
        t.resize(1);
        p = 0;
    }

    void buildTree()
    {
        g.assign(t.size(), std::vector<std::size_t>());
        for (std::size_t i = 1; i < t.size(); ++i) g[t[i].pa].push_back(i);
    }

    std::size_t size() const { return t.size(); }

    const SAMNode &operator[](std::size_t x) const
    {
        assert(x < t.size());
        return t[x];
    }

    const std::vector<std::size_t> &children(std::size_t x) const
    {
        assert(x < g.size());
        return g[x];
    }

   private:
    std::vector<SAMNode> t;
    std::vector<std::vector<std::size_t>> g;
    std::size_t p;
};
}  // namespace CPTH

#endif  // CPTH_SAM

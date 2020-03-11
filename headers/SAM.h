// Get other headers at https://github.com/ouuan/CPTH

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
        int pa, len;
        std::map<charType, int> ch;
        SAMNode() : pa(-1), len(0) {}
        int &operator[](charType x) { return ch[x]; }
    };

    explicit SAM() { clear(); }

    explicit SAM(const charType &x) : SAM() { append(x); }

    template <typename T>
    explicit SAM(const T &str) : SAM()
    {
        append(str);
    }

    int append(const charType &x)
    {
        int np = t.size();
        t.emplace_back();
        t[np].len = t[p].len + 1;
        while (~p && !t[p].ch.count(x))
        {
            t[p][x] = np;
            p = t[p].pa;
        }
        if (p == -1) t[np].pa = 0;
        else
        {
            int q = t[p][x];
            if (t[q].len == t[p].len + 1) t[np].pa = q;
            else
            {
                int nq = t.size();
                t.push_back(t[q]);
                t[nq].len = t[p].len + 1;
                t[q].pa = t[np].pa = nq;
                while (~p && t[p][x] == q)
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
        t.resize(1);
        g.clear();
        p = 0;
    }

    void buildTree()
    {
        g.assign(t.size(), std::vector<int>());
        for (unsigned int i = 1; i < t.size(); ++i) g[t[i].pa].push_back(i);
    }

    unsigned int size() const { return t.size(); }

    const SAMNode &operator[](unsigned int x) const
    {
        assert(x < t.size());
        return t[x];
    }

    const std::vector<int> &children(unsigned int x) const
    {
        assert(x < g.size());
        return g[x];
    }

   private:
    std::vector<SAMNode> t;
    std::vector<std::vector<int>> g;
    int p;
};
}  // namespace CPTH

#endif  // CPTH_SAM

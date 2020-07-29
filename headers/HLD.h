// Get more headers at https://github.com/ouuan/CPTH

#ifndef CPTH_HLD
#define CPTH_HLD

#include <algorithm>
#include <cassert>
#include <vector>

namespace CPTH
{
class HLD
{
   public:
    explicit HLD(size_t size = 0);

    void init(size_t size);

    void addEdge(size_t u, size_t v);

    void build(size_t root = 1);

    size_t lca(size_t u, size_t v) const;

    size_t id(size_t u) const;

    size_t atId(size_t x) const;

    size_t top(size_t u) const;

    size_t size(size_t u) const;

    size_t depth(size_t u) const;

    size_t bottom(size_t u) const;

    size_t parent(size_t u) const;

    size_t heavyChild(size_t u) const;

    const std::vector<size_t> &adjacent(size_t u) const;

    std::vector<size_t> children(size_t u) const;

    std::pair<size_t, size_t> subtree(size_t u) const;

    std::vector<std::pair<size_t, size_t>> path(size_t u, size_t v) const;

   private:
    void dfs1(size_t u);

    void dfs2(size_t u);

    void validate(size_t u) const;

    void reset();

   private:
    bool built;
    size_t n, dfntot;
    std::vector<std::vector<size_t>> g;
    std::vector<size_t> pa, heavy, dep, siz, tp, bt, dfn, rdfn, exi;
};

HLD::HLD(size_t size)
{
    init(size);
}

void HLD::init(size_t size)
{
    assert(size < g.max_size());
    assert(size < pa.max_size());
    n = size;
    g.clear();
    g.resize(n + 1);
    reset();
}

void HLD::addEdge(size_t u, size_t v)
{
    validate(u);
    validate(v);
    g[u].push_back(v);
    g[v].push_back(u);
}

void HLD::build(size_t root)
{
    if (built)
    {
        if (root == atId(1))
            return;
        reset();
    }
    assert(n >= 1);
    validate(root);
    dfs1(root);
    tp[root] = root;
    dfs2(root);
    assert(dfntot == n);
    built = true;
}

size_t HLD::lca(size_t u, size_t v) const
{
    assert(built);
    validate(u);
    validate(v);
    while (tp[u] != tp[v])
    {
        if (dep[tp[u]] > dep[tp[v]])
            u = pa[tp[u]];
        else
            v = pa[tp[v]];
    }
    return dep[u] < dep[v] ? u : v;
}

size_t HLD::id(size_t u) const
{
    assert(built);
    validate(u);
    return dfn[u];
}

size_t HLD::atId(size_t x) const
{
    assert(built);
    validate(x);
    return rdfn[x];
}

size_t HLD::top(size_t u) const
{
    assert(built);
    validate(u);
    return tp[u];
}

size_t HLD::size(size_t u) const
{
    assert(built);
    validate(u);
    return siz[u];
}

size_t HLD::depth(size_t u) const
{
    assert(built);
    validate(u);
    return dep[u];
}

size_t HLD::bottom(size_t u) const
{
    assert(built);
    validate(u);
    return bt[tp[u]];
}

size_t HLD::parent(size_t u) const
{
    assert(built);
    validate(u);
    return pa[u];
}

size_t HLD::heavyChild(size_t u) const
{
    assert(built);
    validate(u);
    return heavy[u];
}

const std::vector<size_t> &HLD::adjacent(size_t u) const
{
    validate(u);
    return g[u];
}

std::vector<size_t> HLD::children(size_t u) const
{
    assert(built);
    validate(u);
    auto ret = g[u];
    if (pa[u])
        ret.erase(std::find(ret.begin(), ret.end(), pa[u]));
    return ret;
}

std::pair<size_t, size_t> HLD::subtree(size_t u) const
{
    assert(built);
    validate(u);
    return {dfn[u], exi[u]};
}

std::vector<std::pair<size_t, size_t>> HLD::path(size_t u, size_t v) const
{
    assert(built);
    validate(u);
    validate(v);
    std::vector<std::pair<size_t, size_t>> res;
    while (tp[u] != tp[v])
    {
        if (dep[tp[u]] > dep[tp[v]])
        {
            res.emplace_back(dfn[tp[u]], dfn[u]);
            u = pa[tp[u]];
        }
        else
        {
            res.emplace_back(dfn[tp[v]], dfn[v]);
            v = pa[tp[v]];
        }
    }
    if (dep[u] > dep[v])
        std::swap(u, v);
    res.emplace_back(dfn[u], dfn[v]);
    return res;
}

void HLD::dfs1(size_t u)
{
    assert(siz[u] == 0);
    siz[u] = 1;
    for (auto v : g[u])
    {
        if (v == pa[u])
            continue;
        dep[v] = dep[u] + 1;
        pa[v] = u;
        dfs1(v);
        siz[u] += siz[v];
        if (siz[v] > siz[heavy[u]])
            heavy[u] = v;
    }
}

void HLD::dfs2(size_t u)
{
    bt[tp[u]] = u;
    dfn[u] = ++dfntot;
    rdfn[dfn[u]] = u;
    if (heavy[u])
    {
        tp[heavy[u]] = tp[u];
        dfs2(heavy[u]);
        for (auto v : g[u])
        {
            if (v == pa[u] || v == heavy[u])
                continue;
            tp[v] = v;
            dfs2(v);
        }
    }
    exi[u] = dfntot;
}

void HLD::validate(size_t u) const
{
    assert(u >= 1);
    assert(u <= n);
}

void HLD::reset()
{
    built = false;
    dfntot = 0;
    pa.assign(n + 1, 0);
    heavy = dep = siz = tp = bt = dfn = rdfn = exi = pa;
}
}  // namespace CPTH

#endif  // CPTH_HLD

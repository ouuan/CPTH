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
    HLD(std::size_t size = 0);

    void reset(std::size_t size);

    void addEdge(std::size_t u, std::size_t v);

    void build(std::size_t root = 1);

    std::size_t lca(std::size_t u, std::size_t v) const;

    std::size_t id(std::size_t u) const;

    std::size_t atId(std::size_t x) const;

    std::size_t top(std::size_t u) const;

    std::size_t bottom(std::size_t u) const;

    std::size_t parent(std::size_t u) const;

    std::vector<std::size_t> children(std::size_t u) const;

    std::pair<std::size_t, std::size_t> subtree(std::size_t u) const;

    std::vector<std::pair<std::size_t, std::size_t>> path(std::size_t u, std::size_t v) const;

   private:
    void dfs1(std::size_t u);

    void dfs2(std::size_t u);

    void validate(std::size_t u) const;

   private:
    bool built;
    std::size_t n, dfntot;
    std::vector<std::vector<std::size_t>> g;
    std::vector<std::size_t> pa, heavy, dep, siz, tp, bt, dfn, rdfn, exi;
};

HLD::HLD(std::size_t size)
{
    reset(size);
}

void HLD::reset(std::size_t size)
{
    assert(size < g.max_size());
    assert(size < pa.max_size());
    built = false;
    n = size;
    dfntot = 0;
    g.clear();
    g.resize(n + 1);
    pa.assign(n + 1, 0);
    heavy = dep = siz = tp = bt = dfn = rdfn = exi = pa;
}

void HLD::addEdge(std::size_t u, std::size_t v)
{
    validate(u);
    validate(v);
    g[u].push_back(v);
    g[v].push_back(u);
}

void HLD::build(std::size_t root)
{
    if (built)
        return;
    assert(n >= 1);
    validate(root);
    dfs1(root);
    tp[root] = root;
    dfs2(root);
    assert(dfntot == n);
    built = true;
}

std::size_t HLD::lca(std::size_t u, std::size_t v) const
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

std::size_t HLD::id(std::size_t u) const
{
    assert(built);
    validate(u);
    return dfn[u];
}

std::size_t HLD::atId(std::size_t x) const
{
    assert(built);
    validate(x);
    return rdfn[x];
}

std::size_t HLD::top(std::size_t u) const
{
    assert(built);
    validate(u);
    return tp[u];
}

std::size_t HLD::bottom(std::size_t u) const
{
    assert(built);
    validate(u);
    return bt[tp[u]];
}

std::size_t HLD::parent(std::size_t u) const
{
    assert(built);
    validate(u);
    return pa[u];
}

std::vector<std::size_t> HLD::children(std::size_t u) const
{
    auto ret = g[u];
    if (pa[u])
        ret.erase(std::find(ret.begin(), ret.end(), pa[u]));
    return ret;
}

std::pair<std::size_t, std::size_t> HLD::subtree(std::size_t u) const
{
    assert(built);
    validate(u);
    return {dfn[u], exi[u]};
}

std::vector<std::pair<std::size_t, std::size_t>> HLD::path(std::size_t u, std::size_t v) const
{
    assert(built);
    validate(u);
    validate(v);
    std::vector<std::pair<std::size_t, std::size_t>> res;
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

void HLD::dfs1(std::size_t u)
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

void HLD::dfs2(std::size_t u)
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

void HLD::validate(std::size_t u) const
{
    assert(u >= 1);
    assert(u <= n);
}
}  // namespace CPTH

#endif  // CPTH_HLD

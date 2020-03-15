// Get other headers at https://github.com/ouuan/CPTH

#ifndef CPTH_SEGMENTTREE
#define CPTH_SEGMENTTREE

#include <cassert>
#include <climits>
#include <functional>
#include <vector>

namespace CPTH
{
template <typename valueType, typename modType>
struct SegmentTreeNode
{
   public:
    std::size_t id;
    long long left, right;
    valueType val;
    modType mod;
};

template <typename valueType, typename modType>
class SegmentTree
{
   public:
    SegmentTree() = default;

    SegmentTree(const std::vector<valueType> &_initValue,
                std::function<valueType(const valueType &, const valueType &)> _merge,
                std::function<void(SegmentTreeNode<valueType, modType> &, const modType &)> _update,
                long long _startPoint = 1, const valueType &_valueZero = valueType(),
                const modType &_modZero = modType())
    {
        init(_initValue, _merge, _update, _startPoint, _valueZero, _modZero);
    }

    void init(const std::vector<valueType> &_initValue,
              std::function<valueType(const valueType &, const valueType &)> _merge,
              std::function<void(SegmentTreeNode<valueType, modType> &, const modType &)> _update,
              long long _startPoint = 1, const valueType &_valueZero = valueType(),
              const modType &_modZero = modType())
    {
        assert(_startPoint >= LLONG_MIN / 2);
        assert(_startPoint <= LLONG_MAX / 2 - (long long)_initValue.size());
        leftRange = _startPoint;
        rightRange = _startPoint + _initValue.size();
        m_init(_initValue, _merge, _update, _valueZero, _modZero);
    }

    void modify(long long l, long long r, const modType &mod)
    {
        modify(1, leftRange, rightRange, l, r, mod);
    }

    void modify(long long p, const modType &mod) { modify(p, p + 1, mod); }

    valueType query(long long l, long long r) { return query(1, leftRange, rightRange, l, r); }

    valueType query(long long p) { return query(p, p + 1); }

   private:
    void pushup(std::size_t cur)
    {
        nodes[cur].val = merge(nodes[cur << 1].val, nodes[cur << 1 | 1].val);
    }

    void pushdown(std::size_t cur)
    {
        update(nodes[cur << 1], nodes[cur].mod);
        update(nodes[cur << 1 | 1], nodes[cur].mod);
        nodes[cur].mod = modZero;
    }

    void build(std::size_t cur, long long l, long long r, const std::vector<valueType> &initValue)
    {
        nodes[cur].id = cur;
        nodes[cur].left = l;
        nodes[cur].right = r;
        nodes[cur].mod = modZero;
        if (l == r - 1) nodes[cur].val = initValue[l - leftRange];
        else
        {
            build(cur << 1, l, (l + r) >> 1, initValue);
            build(cur << 1 | 1, (l + r) >> 1, r, initValue);
            pushup(cur);
        }
    }

    void m_init(const std::vector<valueType> &_initValue,
                std::function<valueType(const valueType &, const valueType &)> _merge,
                std::function<void(SegmentTreeNode<valueType, modType> &, const modType &)> _update,
                const valueType &_valueZero, const modType &_modZero)
    {
        merge = _merge;
        update = _update;
        valueZero = _valueZero;
        modZero = _modZero;
        nodes.resize((rightRange - leftRange) << 2);
        build(1, leftRange, rightRange, _initValue);
    }

    void modify(std::size_t cur, long long l, long long r, long long L, long long R,
                const modType &mod)
    {
        if (l >= R || r <= L) return;
        if (L <= l && r <= R) update(nodes[cur], mod);
        else
        {
            pushdown(cur);
            modify(cur << 1, l, (l + r) >> 1, L, R, mod);
            modify(cur << 1 | 1, (l + r) >> 1, r, L, R, mod);
            pushup(cur);
        }
    }

    valueType query(std::size_t cur, long long l, long long r, long long L, long long R)
    {
        if (l >= R || r <= L) return valueZero;
        if (L <= l && r <= R) return nodes[cur].val;
        pushdown(cur);
        return merge(query(cur << 1, l, (l + r) >> 1, L, R),
                     query(cur << 1 | 1, (l + r) >> 1, r, L, R));
    }

    std::function<valueType(const valueType &, const valueType &)> merge;
    std::function<void(SegmentTreeNode<valueType, modType> &, const modType &)> update;
    std::vector<SegmentTreeNode<valueType, modType>> nodes;
    long long leftRange = 0, rightRange = 0;
    valueType valueZero;
    modType modZero;
};
}  // namespace CPTH

#endif  // CPTH_SEGMENTTREE

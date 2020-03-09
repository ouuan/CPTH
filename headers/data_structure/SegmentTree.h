#ifndef CPTH_SEGMENTTREE
#define CPTH_SEGMENTTREE

#include <vector>

template <typename valueType, typename modType>
struct SegmentTreeNode
{
   public:
    int id, left, right;
    valueType val;
    modType mod;
};

template <typename valueType, typename modType,
          valueType (*merge)(const valueType &, const valueType &),
          void (*update)(SegmentTreeNode<valueType, modType> &, const modType &)>
class SegmentTree
{
   public:
    explicit SegmentTree() { init(std::vector<valueType>(1)); }

    explicit SegmentTree(int _startPoint, const std::vector<valueType> &_initValue,
                         const valueType &_valueZero = valueType(),
                         const modType &_modZero = modType())
    {
        init(_startPoint, _initValue, _valueZero, _modZero);
    }

    explicit SegmentTree(const std::vector<valueType> &_initValue,
                         const valueType &_valueZero = valueType(),
                         const modType &_modZero = modType())
    {
        init(_initValue, _valueZero, _modZero);
    }

    void init(int _startPoint, const std::vector<valueType> &_initValue,
              const valueType &_valueZero = valueType(), const modType &_modZero = modType())
    {
        leftRange = _startPoint;
        rightRange = _startPoint + _initValue.size();
        m_init(_initValue, _valueZero, _modZero);
    }

    void init(const std::vector<valueType> &_initValue, const valueType &_valueZero = valueType(),
              const modType &_modZero = modType())
    {
        leftRange = 1;
        rightRange = _initValue.size() + 1;
        m_init(_initValue, _valueZero, _modZero);
    }

    void modify(int l, int r, const modType &mod) { modify(1, leftRange, rightRange, l, r, mod); }

    void modify(int p, const modType &mod) { modify(p, p + 1, mod); }

    valueType query(int l, int r) { return query(1, leftRange, rightRange, l, r); }

    valueType query(int p) { return query(p, p + 1); }

   private:
    void pushup(int cur) { nodes[cur].val = merge(nodes[cur << 1].val, nodes[cur << 1 | 1].val); }

    void pushdown(int cur)
    {
        update(nodes[cur << 1], nodes[cur].mod);
        update(nodes[cur << 1 | 1], nodes[cur].mod);
        nodes[cur].mod = modZero;
    }

    void build(int cur, int l, int r, const std::vector<valueType> &initValue)
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

    void m_init(const std::vector<valueType> &_initValue, const valueType &_valueZero,
                const modType &_modZero)
    {
        valueZero = _valueZero;
        modZero = _modZero;
        nodes.resize((rightRange - leftRange) << 2);
        build(1, leftRange, rightRange, _initValue);
    }

    void modify(int cur, int l, int r, int L, int R, const modType &mod)
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

    valueType query(int cur, int l, int r, int L, int R)
    {
        if (l >= R || r <= L) return valueZero;
        if (L <= l && r <= R) return nodes[cur].val;
        pushdown(cur);
        return merge(query(cur << 1, l, (l + r) >> 1, L, R),
                     query(cur << 1 | 1, (l + r) >> 1, r, L, R));
    }

    std::vector<SegmentTreeNode<valueType, modType>> nodes;
    int leftRange, rightRange;
    valueType valueZero;
    modType modZero;
};

#endif  // CPTH_SEGMENTTREE

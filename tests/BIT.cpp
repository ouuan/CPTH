// https://ouuan.github.io/post/parallel-binary-search/#zjoi2013k%E5%A4%A7%E6%95%B0%E6%9F%A5%E8%AF%A2httpswwwluogucomcnproblemp3332

#include "BIT.h"

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct Operation
{
    int l, r, id;
    ll target, current, tmp;
    Operation(int _l, int _r, int _id, ll _target)
        : l(_l), r(_r), id(_id), target(_target), current(0), tmp(0)
    {}
};

CPTH::BIT<ll> bitk, bitb;

void add(int p, int x)
{
    bitk.add(p, x);
    bitb.add(p, (1 - p) * x);
}

ll query(int p) { return bitk.query(p) * p + bitb.query(p); }

void clear()
{
    bitk.clear();
    bitb.clear();
}

vector<int> ans;

#define mid ((l + r) >> 1)

void solve(int l, int r, vector<Operation> &ops)
{
    if (l == r - 1)
    {
        for (auto op : ops)
        {
            if (~op.id) ans[op.id] = l;
        }
        return;
    }
    clear();
    for (auto &op : ops)
    {
        if (~op.id) op.tmp = query(op.r) - query(op.l - 1);
        else if (op.target < mid)
        {
            add(op.l, 1);
            add(op.r + 1, -1);
        }
    }
    vector<Operation> lop, rop;
    for (auto op : ops)
    {
        if (op.id == -1)
        {
            if (op.target < mid) lop.push_back(op);
            else
                rop.push_back(op);
        }
        else
        {
            if (op.current + op.tmp >= op.target) lop.push_back(op);
            else
            {
                op.current += op.tmp;
                rop.push_back(op);
            }
        }
    }
    vector<Operation>().swap(ops);
    solve(l, mid, lop);
    solve(mid, r, rop);
}

int main()
{
    int n, m;

    scanf("%d%d", &n, &m);

    int qid = 0;
    vector<Operation> ops;

    for (int i = 0; i < m; ++i)
    {
        int op, l, r;
        ll x;
        scanf("%d%d%d%lld", &op, &l, &r, &x);
        if (op == 1) ops.emplace_back(l, r, -1, -x);
        else
            ops.emplace_back(l, r, qid++, x);
    }

    ans.resize(qid);
    bitk.init(n, plus<ll>());
    bitb.init(n, plus<ll>());
    solve(-n, n + 1, ops);

    for (auto x : ans) printf("%d\n", -x);

    return 0;
}

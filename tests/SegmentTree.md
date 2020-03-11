## SegmentTree

[【模板】线段树 2](https://www.luogu.com.cn/problem/P3373)

### Description

You have an array a_1, a_2, ..., a_n.

You have to do m operations, each of them is one of:

1. Multiply each element of a_l, a_{l+1}, ..., a_r by x.
2. Add x to each element of a_l, a_{l+1}, ..., a_r.
3. Get the sum of a_l, a_{l+1}, ..., a_r, modulo p.

### Input

The first line contains the number of numbers in the array n, the number of operations m, the modulo number p.

The second line contains the array.

In the following m lines, each line contains `1 l r x`, `2 l r x` or `3 l r`, corresponding to the operations above.

### Output

The output contains some integers — the answers to the operation 3.

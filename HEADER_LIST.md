## SegmentTree

A segment tree template, supports lazy propagation (range modify, range query), you only have to implement two key functions, you can use lambda for these two functions.

- [SegmentTree.h](headers/SegmentTree.h)
- [SegmentTree.md](docs/SegmentTree.md)
- [SegmentTree.cpp](tests/SegmentTree/SegmentTree.cpp)

## SAM

A suffix automaton template which supports arbitary character type, can construct the SAM and the parent tree.

- [SAM.h](headers/SAM.h)
- [SAM.md](docs/SAM.md)
- [SAM.cpp](tests/SAM/SAM.cpp)

## BIT

A binary indexed tree (Fenwick tree) template which supports element addition, query prefix sum. You only need to implement "add two values", lambda is supported. You can clear it in O(1).

- [BIT.h](headers/BIT.h)
- [BIT.md](docs/BIT.md)
- [BIT.cpp](tests/BIT/BIT.cpp)

## MonotonousQueue

Get the maximum value in a FIFO queue  in linear time.

- [MonotonousQueue.h](headers/MonotonousQueue.h)
- [MonotonousQueue.md](docs/MonotonousQueue.md)
- [MonotonousQueue.cpp](tests/MonotonousQueue/MonotonousQueue.cpp)

## ModInt

Integer modulo an number.

- [ModInt.h](headers/ModInt.h)
- [ModInt.md](docs/ModInt.md)
- [ModInt.cpp](tests/ModInt/ModInt.cpp)

## ConstantModInt

A faster ModInt with a compile-time constant modulo as a template parameter.

- [ConstantModInt.h](headers/ConstantModInt.h)
- [ConstantModInt.md](docs/ConstantModInt.md)
- [ConstantModInt.cpp](tests/ConstantModInt/ConstantModInt.cpp)

## HLD

The heavy-light decomposition of a tree. Can be used to perform operations on paths.

- [HLD.h](headers/HLD.h)
- [HLD.md](docs/HLD.md)
- [HLD.cpp](tests/HLD/HLD.cpp)

## SparseTable

Sparse table can be used to get the "sum" of an interval in O(nlogn)-O(1), where the "sum" behaves like a function of a (non-multi) set. For example, min and gcd.

- [SparseTable.h](headers/SparseTable.h)
- [SparseTable.md](docs/SparseTable.md)
- [SparseTable.cpp](tests/SparseTable/SparseTable.cpp)

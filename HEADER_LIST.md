## SegmentTree

A segment tree template, supports lazy propagation (range modify, range query), you only have to implement two key functions, you can use lambda for these two functions.

- [SegmentTree.h](headers/SegmentTree.h)
- [SegmentTree.md](docs/SegmentTree.md)
- [SegmentTree.cpp](tests/SegmentTree.cpp)

## SAM

A suffix automaton template which supports arbitary character type, can construct the SAM and the parent tree.

- [SAM.h](headers/SAM.h)
- [SAM.md](docs/SAM.md)
- [SAM.cpp](tests/SAM.cpp)

## BIT

A binary indexed tree (Fenwick tree) template which supports element addition, query prefix sum. You only need to implement "add two values", lambda is supported. You can clear it in O(1).

- [BIT.h](headers/BIT.h)
- [BIT.md](docs/BIT.md)
- [BIT.cpp](tests/BIT.cpp)

## MonotonousQueue

Get the maximum value in a FIFO queue  in linear time.

- [MonotonousQueue.h](headers/MonotonousQueue.h)
- [MonotonousQueue.md](docs/MonotonousQueue.md)
- [MonotonousQueue.cpp](tests/MonotonousQueue.cpp)

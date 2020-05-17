## SparseTable

Sparse table is constructed on an array, it doesn't support modification, you can query the "sum" of an interval, where the "sum" has this property:

Suppose `f(x, y)` means the "sum" of `x` and `y`, then `f(x, f(x, y)) = f(x, y)` holds for arbitrary `x` and `y`.

The "sum" can be considered as a function of a (non-multi) set.

For example, the "sum" can be the minimum value, or the greatest common divisor.

It can be constructed in O(nlogn), and answer each query online in O(1). It's memory complexity is O(nlogn).

### Template

`SparseTable<T>`, where `T` is the type stored in the sparse table.

### Member functions

`explicit SparseTable()`: Construct an empty sparse table.

`explicit SparseTable(const std::vector<T> &a, std::function<T(const T &, const T &)> merge)`: Construct a sparse table on the array `a`, with the "sum" function `merge`.

`void init(const std::vector<T> &a, std::function<T(const T &, const T &)> merge)`: The same as the constructor above.

`T query(size_t l, size_t r) const`: Query the "sum" of the interval `[l, r)`, i.e. `merge(a[l], merge(a[l + 1], ..., merge(a[r - 2], a[r - 1]) ... ))`. Note that the interval is left-closed, right-open. `r` should be strictly greater than `l`, and not greater than the size of the array.

`size_t size() const`: Get the size of the array.
